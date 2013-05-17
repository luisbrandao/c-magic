#include <stdio.h>	// Inclui diretivas de entrada-saída
#include <stdlib.h>     // Usa recursos do sistema
#include <stdio_ext.h>  // Precisa para o fpurge
#include <unistd.h>	// Sleep sem syscall

#include "MagoVerde.h"
#include "funcoesA.h"   // Modulos básicos do jogo
#include "funcoesB.h"   // Modulos básicos do jogo
#include "definicoes.h" // Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file MagoVerde.c
 * @brief Biblioteca de procedimentos do mago Verde
 * Esta bliblioteca tem como objetivo implementar a classe "mago Verde", exibindo na tela o menu de ações possíveis do mago, e tratando a entrada do jogador, decidindo se o movimento é válido ou não.<br>
 * Essa função também cuida dos ataques especiais do mago Verde.
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

//----------------------------------- Protótipos ------------------------------------
int opcoes_verde(int ap,int mpAtual,int powstat);
void MG_manaVoid(int jogs,int jogatual,vetor jogadores);
/* ----------------------------------------------------------------------------------------*/
/** @brief Ações do mago verde
 * Está é a função que invoca o painel de ações do mago verde, trata a entrada do jogador, chama respectiva função do movimento escolhido e retorna o número de mps gastos na rodada.
 * 
 * @param aps Número de pontos de movimento disponiveis ao jogador
 * @param jogs Número total de jogadores
 * @param jogatual indice do jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int apc_<ação> Caso a entrada do jogador seja válida
 * @return 0 Caso a entrada do jogador seja inválida  */
/* ----------------------------------------------------------------------------------------*/
int acao_verde(int aps, int jogs,int jogatual,vetor jogadores)
{
int acao, mpAtual = jogadores[jogatual].mp;
placar (jogs, jogatual, jogadores);
acao = opcoes_verde(aps,jogadores[jogatual].mp,jogadores[jogatual].buffer);

/* Tratador da ação do jagador. Note que, como ao entrar no case o valor da váriavel "acao" deixa de ser importante, ela é reutilizada para servir como a váriavel "alvo" */
switch (acao)
	{
// ==== Cajado ========================================================================
	case GL_caj:
		{
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, GL_MIN_dmg_caj, GL_mod_caj, 0);
		sleep(t_delay);
		return GL_apc_caj;
		}
// ==== Tempestade de folhas ==========================================================
	case MG_ID_tdf:
		{
		if ((jogadores[jogatual].mp < MG_mpc_tdf) || (aps < MG_apc_tdf))
			return 0;
		GL_area_ataque(jogs, jogatual, jogadores, MG_MIN_dmg_tdf, MG_mod_tdf, MG_mpc_tdf);
		sleep(t_delay);
		return MG_apc_tdf; // Custo de aps 
		}
// ==== Esporos =======================================================================
	case MG_ID_ec:
		{
		if ((jogadores[jogatual].mp < MG_mpc_ec) || (aps < MG_apc_ec))
			return 0;
		acao = target(jogs, jogatual, jogadores, 0);
		GL_hp_effect(acao,jogatual,jogadores,MG_dmg_ec,MG_dur_ec, MG_mpc_ec);
		sleep(t_delay);
		return MG_apc_ec; // Custo de aps
		}
// ==== Veneno ========================================================================
	case MG_ID_ven:
		{
		if ((jogadores[jogatual].mp < MG_mpc_ven) || (aps < MG_apc_ven))
			return 0;
		acao = target(jogs, jogatual, jogadores, 0);
		GL_hp_effect(acao,jogatual,jogadores,MG_dmg_ven,MG_dur_ven, MG_mpc_ven);
		sleep(t_delay);
		return MG_apc_ven; // Custo de aps 
		}
// ==== Sugar vida ====================================================================
	case MG_ID_hpd:
		{
		if ((jogadores[jogatual].mp < MG_mpc_hpd) || (aps < MG_apc_hpd))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_hp_drain(acao,jogatual,jogadores, MG_MIN_dmg_hpd, MG_mod_hpd, MG_mpc_hpd);
		sleep(t_delay);
		return MG_apc_hpd; // Custo de aps 
		}
// ==== Emrolar =======================================================================
	case MG_ID_enrol:
		{
		if ((jogadores[jogatual].mp < MG_mpc_enrol) || (aps < MG_apc_enrol))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_ap_effect(acao,jogatual,jogadores,MG_dmg_enrol,MG_dur_enrol,MG_mpc_enrol);
		sleep(t_delay);
		return MG_apc_enrol; // Custo de aps
		}
// ==== Sugar mana ====================================================================
	case MG_ID_mpd:
		{
		if (aps < MG_apc_mpd)
			return 0;
		acao = target(jogs,jogatual,jogadores,1);
		GL_mp_drain(acao, jogatual, jogadores, MG_MIN_dmg_mpd, MG_mod_mpd);
		sleep(t_delay);
		return MG_apc_mpd; // Custo de aps
		}
// ==== Magia Superior ================================================================
	case MG_ID_pow:
		{
		if ((mpAtual < MG_mpc_pow) || (aps < MG_apc_pow)|| (jogadores[jogatual].buffer > 1))
			return 0;
		GL_charge(jogatual,jogadores,MG_mpc_pow);
		sleep(t_delay);
		return MG_apc_pow; // Custo de aps
		}
// ==== Mana void =====================================================================
	case MG_ID_mv:
		{
		if ((mpAtual < MG_mpc_mv) || (jogadores[jogatual].buffer < 1) || (aps < MG_apc_mv))
			return 0;
		MG_manaVoid(jogs,jogatual,jogadores);
		sleep(t_delay);
		return MG_apc_mv; // Custo de aps
		}
// ====================================================================================
	}
return 0; // Não foi uma escolha válida então não gasta ap.
}

// --------------------------------------------------------------------------------------
// -------------------------------- Funções internas ------------------------------------
// --------------------------------------------------------------------------------------

/* ----------------------------------------------------------------------------------------*/
/** @brief Painel de ações do mago verde
 * 
 * @param ap Número de pontos de movimento disponiveis ao jogador
 * @param mpAtual Mana atual do jogador
 * @param powstat Status do indicador de magia superior
 *
 * @return int opção digitada pelo jogador */
/* ----------------------------------------------------------------------------------------*/
int opcoes_verde(int ap,int mpAtual,int powstat)
{
int temp;
printf ("Você ainda tem %d pontos de movimento.\n", ap);
printf ("<%d> para atacar com o seu cajado.\n",GL_caj);
printf ("	1-3 attack, 1 ap, 0 mp\n");
if ((mpAtual >= MG_mpc_tdf) && (ap >= MG_apc_tdf))
	{
	printf ("===============================================================\n");
	printf ("<%d> Uma tempestade de folhas cortantes.\n",MG_ID_tdf);
	printf ("	%d-%d area attack, %d ap, %d mp\n", MG_MIN_dmg_tdf, MG_MIN_dmg_tdf+MG_mod_tdf-1, MG_apc_tdf, MG_mpc_tdf);
	}
if ((mpAtual >= MG_mpc_ec) && (ap >= MG_apc_ec))
	{
	printf ("===============================================================\n");
	printf ("<%d> Lançar uma onda de esporos corrosivos.\n",MG_ID_ec);
	printf ("	%d dano, %d duração, %d ap, %d mp\n", MG_dmg_ec, MG_dur_ec, MG_apc_ec, MG_mpc_ec);
	}

if ((mpAtual >= MG_mpc_ven) && (ap >= MG_apc_ven))
	{
	printf ("===============================================================\n");
	printf ("<%d> para envenenar seu inimigo.\n",MG_ID_ven);
	printf ("	%d dano, %d duração, %d ap, %d mp\n", MG_dmg_ven, MG_dur_ven, MG_apc_ven, MG_mpc_ven);
	}

if ((mpAtual >= MG_mpc_hpd) && (ap >= MG_apc_hpd))
	{
	printf ("===============================================================\n");
	printf ("<%d> Sugar a força vital do seu adversário.\n",MG_ID_hpd);
	printf ("	%d-%d sugados, %d ap, %d mp\n", MG_MIN_dmg_hpd, MG_MIN_dmg_hpd+MG_mod_hpd-1, MG_apc_hpd, MG_mpc_hpd);
	}

if ((mpAtual >= MG_mpc_enrol) && (ap >= MG_apc_enrol))
	{
	printf ("===============================================================\n");
	printf ("<%d> para enrolar seu alvo e deixa-lo lento.\n",MG_ID_enrol);
	printf ("	+%d Aps, %d duração, %d ap, %d mp\n",MG_dmg_enrol, MG_dur_enrol, MG_apc_enrol, MG_mpc_enrol);
	}

if (ap >= MG_apc_mpd)
	{
	printf ("===============================================================\n");
	printf ("<%d> Drenar o poder de seu adversario.\n",MG_ID_mpd);
	printf ("	%d-%d mana sugada, %d ap\n", MG_MIN_dmg_mpd, MG_MIN_dmg_mpd+MG_mod_mpd-1, MG_apc_mpd);
	}

printf ("Ação: ");
scanf ("%d", &temp);
__fpurge(stdin);
return(temp);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Ataque especial: Vazio mágico.
 * Esse é o ataque especial do mago verde. O vazio mágico suga todas  <br>
 <b>ATENÇÃO:</B> Esse ataque não respeita os máximos globais nem trava.<br>
 Está sendo que, como está é considerada uma magia superior, ela não vai ser usada com freqüencia suficiente para "Danificar" o HPmod, e ela sendo "mais forte" consegue fazer efeito mesmo sobre alguma trava. 
 * 
 * @param jogs Número total de jogadores
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void MG_manaVoid(int jogs,int jogatual,vetor jogadores)
{
int alvo;
jogadores[jogatual].buffer--;

for (alvo=0; alvo < jogs ; alvo ++)
	if (alvo != jogatual)
		{
		GL_mp_drain(alvo, jogatual, jogadores, MG_MIN_dmg_mv, MG_mod_mv);
		}
return;
}
