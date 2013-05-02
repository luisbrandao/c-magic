#include <stdio.h>		// inclui diretivas de entrada-saída
#include <stdlib.h>		// Usa recursos do sistema
#include <stdio_ext.h>		// Precisa para o fpurge
#include <unistd.h>		// Sleep sem syscall

#include "MagoVermelho.h"	//Constantes do mago vermelho
#include "funcoesA.h"		// Modulos básicos do jogo
#include "funcoesB.h"		// Modulos básicos do jogo
#include "definicoes.h"		// Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file MagoVermelho.c
 * @brief Biblioteca de procedimentos do mago Vermelho
 * Esta bliblioteca tem como objetivo implementar a classe "mago Vermelho", exibindo na tela o menu de ações possíveis do mago, e tratando a entrada do jogador, decidindo se o movimento é válido ou não.<br>
 * Essa função também cuida dos ataques especiais do mago Vermelho.
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

//----------------------------------- Protótipos ------------------------------------
int opcoes_vermelho(int ap,int mpAtual,int powstat);
void MV_fenixFire(int jogs,int jogatual,vetor jogadores);
/* ----------------------------------------------------------------------------------------*/
/** @brief Ações do mago vermelho
 * Está é a função que invoca o painel de ações do mago vermelho, trata a entrada do jogador, chama respectiva função do movimento escolhido e retorna o número de mps gastos na rodada.
 * 
 * @param aps Número de pontos de movimento disponiveis ao jogador
 * @param jogs Número total de jogadores
 * @param jogatual indice do jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int apc_<ação> Caso a entrada do jogador seja válida
 * @return 0 Caso a entrada do jogador seja inválida  */
/* ----------------------------------------------------------------------------------------*/
int acao_vermelho(int aps, int jogs,int jogatual,vetor jogadores)
{
int acao,mpAtual = jogadores[jogatual].mp;
placar (jogs, jogatual, jogadores);
acao = opcoes_vermelho(aps,jogadores[jogatual].mp,jogadores[jogatual].buffer);

/* Tratador da ação do jagador. Note que, como ao entrar no case o valor da váriavel "acao" deixa de ser importante, ela é reutilizada para servir como a váriavel "alvo" */
switch (acao)
	{
// ==== Cajdado =======================================================================
	case GL_caj:
		{
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, GL_MIN_dmg_caj, GL_mod_caj, 0);
		sleep(t_delay);
		return GL_apc_caj;
		}
// ==== Labareda ======================================================================
	case MV_ID_lab:
		{
		if (mpAtual < MV_mpc_lab)
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MV_MIN_dmg_lab, MV_mod_lab, MV_mpc_lab);
		sleep(t_delay);
		return MV_apc_lab; // Custo de aps da labareda
		}
// ==== Bola de fogo ==================================================================
	case MV_ID_bdf:
		{
		if (mpAtual < MV_mpc_bdf)
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MV_MIN_dmg_bdf, MV_mod_bdf, MV_mpc_bdf);
		sleep(t_delay);
		return MV_apc_bdf; // Custo de aps da bola de fogo
		}
// ==== Explosão ======================================================================
	case MV_ID_exp:
		{
		if (mpAtual < MV_mpc_exp)
			return 0;
		GL_area_ataque(jogs, jogatual, jogadores, MV_MIN_dmg_exp, MV_mod_exp, MV_mpc_exp);
		sleep(t_delay);
		return MV_apc_exp; // Custo de aps da bola de fogo
		}
// ==== Plasma ========================================================================
	case MV_ID_plas:
		{
		if (mpAtual < MV_mpc_plas)
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MV_MIN_dmg_plas, MV_mod_plas, MV_mpc_plas);
		sleep(t_delay);
		return MV_apc_plas; // Custo de aps da bola de fogo
		}
// ==== Cura leve =====================================================================
	case MV_ID_cul:
		{
		if (mpAtual < MV_mpc_cul)
			return 0;
		acao = target(jogs,jogatual,jogadores,3);
		GL_cura(acao,jogadores,MV_MIN_dmg_cul, MV_mod_cul, MV_mpc_cul);
		sleep(t_delay);
		return MV_apc_cul; // Custo de aps da bola de fogo
		}
// ==== Negatis =======================================================================
	case MV_ID_neg:
		{
		if (mpAtual < MV_mpc_neg)
			return 0;
		acao = target(jogs,jogatual,jogadores,4);
		GL_negatis(acao,jogadores);
		sleep(t_delay);
		return MV_apc_neg; // Custo de aps da bola de fogo
		}
// ==== Concentração ==================================================================
	case MV_ID_con:
		{
		GL_concentra(jogatual,jogadores,MV_MIN_dmg_con,MV_mod_con);
		sleep(t_delay);
		return MV_apc_con; // Custo de aps da concentração
		}
// ==== Magia Superior ================================================================
	case MV_ID_pow:
		{
		if ((mpAtual < MV_mpc_pow) || (aps < MV_apc_pow)|| (jogadores[jogatual].buffer > 1))
			return 0;
		GL_charge(jogatual,jogadores,MV_mpc_pow);
		sleep(t_delay);
		return MV_apc_pow; // Custo de aps
		}
// ==== Fogo da fenix =================================================================
	case MV_ID_ff:
		{
		if ((mpAtual < MV_mpc_ff) || (jogadores[jogatual].buffer < 1) || (aps < MV_apc_ff))
			return 0;
		MV_fenixFire(jogs,jogatual,jogadores);
		sleep(t_delay);
		return MV_apc_ff; // Custo de aps
		}
// ====================================================================================
	}
return 0;
}

// --------------------------------------------------------------------------------------
// -------------------------------- Funções internas ------------------------------------
// --------------------------------------------------------------------------------------

/* ----------------------------------------------------------------------------------------*/
/** @brief Painel de ações do mago vermelho
 * 
 * @param ap Número de pontos de movimento disponiveis ao jogador
 * @param mpAtual Mana atual do jogador
 * @param powstat Status do indicador de magia superior
 *
 * @return int opção digitada pelo jogador */
/* ----------------------------------------------------------------------------------------*/
int opcoes_vermelho(int ap,int mpAtual,int powstat)
{
int temp;
printf ("Voce ainda tem %d pontos de movimento.\n", ap);
printf ("<%d> para atacar com o seu cajado.\n",GL_caj);
printf ("	1-3 attack, 1 ap, 0 mp\n"); //revisar aqui constantes > variaveis
if ((mpAtual >= MV_mpc_lab) && (ap >= MV_apc_lab))
	{
	printf ("===============================================================\n");
	printf ("<%d> para lancar uma labareda.\n",MV_ID_lab);
	printf ("	%d-%d attack, %d ap, %d mp\n", MV_MIN_dmg_lab, MV_MIN_dmg_lab+MV_mod_lab-1, MV_apc_lab, MV_mpc_lab);
	}
if ((mpAtual >= MV_mpc_bdf) && (ap >= MV_apc_bdf))
	{
	printf ("===============================================================\n");
	printf ("<%d> para lancar uma bola de fogo.\n",MV_ID_bdf);
	printf ("	%d-%d attack, %d ap, %d mp\n", MV_MIN_dmg_bdf, MV_MIN_dmg_bdf+MV_mod_bdf-1, MV_apc_bdf, MV_mpc_bdf);
	}
if ((mpAtual >= MV_mpc_exp) && (ap >= MV_apc_exp))
	{
	printf ("===============================================================\n");
	printf ("<%d> para lancar uma explosão.\n",MV_ID_exp);
	printf ("	%d-%d attack, %d ap, %d mp\n", MV_MIN_dmg_exp, MV_MIN_dmg_exp+MV_mod_exp-1, MV_apc_exp, MV_mpc_exp);
	}

if ((mpAtual >= MV_mpc_plas) && (ap >= MV_apc_plas))
	{
	printf ("===============================================================\n");
	printf ("<%d> para envolver seu oponene em plasma realmente quente.\n",MV_ID_plas);
	printf ("	%d-%d attack, %d ap, %d mp\n", MV_MIN_dmg_plas, MV_MIN_dmg_plas+MV_mod_plas-1, MV_apc_plas, MV_mpc_plas);
	}

if ((mpAtual >= MV_mpc_cul) && (ap >= MV_apc_cul))
	{
	printf ("===============================================================\n");
	printf ("<%d> usar cura leve.\n",MV_ID_cul);
	printf ("	%d-%d attack, %d ap, %d mp\n", MV_MIN_dmg_cul, MV_MIN_dmg_cul+MV_mod_cul-1, MV_apc_cul, MV_mpc_cul);
	}

if ((mpAtual >= MV_mpc_neg) && (ap >= MV_apc_neg))
	{
	printf ("===============================================================\n");
	printf ("<%d> negatis.\n",MV_ID_neg);
	printf ("	neutraliza todas as condições\n");
	}

if (ap >= MV_apc_con)
	{
	printf ("===============================================================\n");
	printf ("<%d> para se concentrar e recuparar parte do seu poder.\n",MV_ID_con);
	printf ("	%d-%d mana recuperados, %d ap\n", MV_MIN_dmg_con, MV_MIN_dmg_con+MV_mod_con-1, MV_apc_con);
	}

if ((mpAtual >= MV_mpc_pow) && (ap >= MV_apc_pow) && (powstat < 1))
	{
	printf ("===============================================================\n");
	printf ("<%d> Encantamento superior: Convocar circulo\n",MV_ID_pow);
	printf ("	Custo de mana: %d, Aps: %d\n", MV_mpc_pow,MV_apc_pow);
	}

if ((mpAtual >= MV_mpc_ff) && (ap >= MV_apc_ff) && (powstat > 0))
	{
	printf ("===============================================================\n");
	printf ("<%d> Magia superior: Fogo da fenix.\n",MV_ID_ff);
	printf ("	Custo: %d ap, %d mp | %d/%d dmg instantaneo| %d/%d dmg/turno\n",
MV_apc_ff, MV_mpc_ff, MV_MIN_dmg_ff, MV_MIN_dmg_ff+MV_mod_ff-1, MV_fdmg_ff, MV_dur_ff);
	}

printf ("Ação: ");
scanf ("%d", &temp);
__fpurge(stdin);
return(temp);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Ataque especial: Fogo da fenix
 * Esse é o ataque especial do mago vermelho. Ele é uma mistura de um ataque de área normal com um ataque de efeito, criando hpmod e dando dano normal. <br>
 <b>ATENÇÃO:</B> Esse ataque não respeita os máximos globais nem trava.<br>
 Está sendo que, como está é considerada uma magia superior, ela não vai ser usada com freqüencia suficiente para "Danificar" o HPmod, e ela sendo "mais forte" consegue fazer efeito mesmo sobre alguma trava. 
 * 
 * @param jogs Número total de jogadores
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void MV_fenixFire(int jogs,int jogatual,vetor jogadores)
{
int alvo,dmg;
jogadores[jogatual].buffer--;

for (alvo=0; alvo < jogs ; alvo ++)
	if (alvo != jogatual)
		{
		dmg = (rand()%MV_mod_ff)+ MV_MIN_dmg_ff;
		jogadores[alvo].hp -= dmg; // Aplica o dano
		jogadores[alvo].hpmod.dur += MV_dur_ff; // Aumenta duração pro HPmod
		jogadores[alvo].hpmod.mod += MV_fdmg_ff; // Aumenta dano pro HPmod
		printf("%s recebeu %d pontos de dano e queimará por %d, perdendo %d pontos de vida.\n", jogadores[alvo].nome, dmg, MV_dur_ff, MV_fdmg_ff);
		}
return;
}
