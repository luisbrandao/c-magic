#include <stdio.h>		// inclui diretivas de entrada-saída
#include <stdlib.h>     // Usa recursos do sistema
#include <stdio_ext.h>  // Precisa para o fpurge
#include <unistd.h>		// Sleep sem syscall

#include "MagoBranco.h"
#include "funcoesA.h"   // Modulos básicos do jogo
#include "funcoesB.h"   // Modulos básicos do jogo
#include "definicoes.h" // Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file MagoBranco.c
 * @brief Biblioteca de procedimentos do mago Branco
 * Esta bliblioteca tem como objetivo implementar a classe "mago Branco", exibindo na tela o menu de ações possíveis do mago, e tratando a entrada do jogador, decidindo se o movimento é válido ou não.<br>
 * Essa função também cuida dos ataques especiais do mago Branco.
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

//------------------------------------ Protótipos -------------------------------------
int opcoes_branco(int,int,int);
void MB_stopTime(int jogatual, vetor jogadores);


/* ----------------------------------------------------------------------------------------*/
/** @brief Ações do mago branco
 * Está é a função que invoca o painel de ações do mago branco, trata a entrada do jogador, chama respectiva função do movimento escolhido e retorna o número de mps gastos na rodada.
 * 
 * @param aps Número de pontos de movimento disponiveis ao jogador
 * @param jogs Número total de jogadores
 * @param jogatual indice do jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int apc_<ação> Caso a entrada do jogador seja válida
 * @return 0 Caso a entrada do jogador seja inválida  */
/* ----------------------------------------------------------------------------------------*/
int acao_branco(int aps, int jogs,int jogatual,vetor jogadores)
{
int acao,mpAtual = jogadores[jogatual].mp;
placar (jogs, jogatual, jogadores);
acao = opcoes_branco(aps,jogadores[jogatual].mp,jogadores[jogatual].buffer);

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
// ==== Feixe de luz ==================================================================
	case MB_ID_fdl:
		{
		if ((mpAtual < MB_mpc_fdl) || (aps < MB_apc_fdl))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MB_MIN_dmg_fdl, MB_mod_fdl, MB_mpc_fdl);
		sleep(t_delay);
		return MB_apc_fdl; // Custo de aps da magia
		}
// ==== Raio ==========================================================================
	case MB_ID_ray:
		{
		if ((mpAtual < MB_mpc_ray) || (aps < MB_apc_ray))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MB_MIN_dmg_ray, MB_mod_ray, MB_mpc_ray);
		sleep(t_delay);
		return MB_apc_ray; // Custo de aps da magia
		}
// ==== Furação =======================================================================
	case MB_ID_fur:
		{
		if ((mpAtual < MB_mpc_fur) || (aps < MB_apc_fur))
			return 0;
		GL_area_ataque(jogs, jogatual, jogadores, MB_MIN_dmg_fur, MB_mod_fur, MB_mpc_fur);
		sleep(t_delay);
		return MB_apc_fur; // Custo de aps da magia
		}
// ==== Tornado =======================================================================
	case MB_ID_torn:
		{
		if ((mpAtual < MB_mpc_torn) || (aps < MB_apc_torn))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MB_MIN_dmg_torn, MB_mod_torn, MB_mpc_torn);
		sleep(t_delay);
		return MB_apc_torn;  // Custo de aps da magia
		}
// ==== Cura ==========================================================================
	case MB_ID_cur:
		{
		if ((mpAtual < MB_mpc_cur) || (aps < MB_apc_cur))
			return 0;
		acao = target(jogs,jogatual,jogadores,3);
		GL_cura(acao, jogadores, MB_MIN_dmg_cur,MB_mod_cur,MB_mpc_cur);
		sleep(t_delay);
		return MB_apc_cur;  // Custo de aps da magia
		}
// ==== Acelerar ======================================================================
	case MB_ID_haste:
		{
		if ((mpAtual < MB_mpc_haste) || (aps < MB_apc_haste))
			return 0;
		acao = target(jogs,jogatual,jogadores,2);
		GL_ap_effect(acao,jogatual,jogadores,MB_dmg_haste,MB_dur_haste,MB_mpc_haste);
		sleep(t_delay);
		return MB_apc_haste; // Custo de aps da magia
		}
// ==== Concentração ==================================================================
	case MB_ID_con:
		{
		if (aps < MB_apc_con)
			return 0;
		GL_concentra(jogatual,jogadores, MB_MIN_dmg_con, MB_mod_con);
		sleep(t_delay);
		return MB_apc_con;  // Custo de aps da magia
		}
// ==== Magia Superior ================================================================
	case MB_ID_pow:
		{
		if ((mpAtual < MB_mpc_pow) || (aps < MB_apc_pow)|| (jogadores[jogatual].buffer > 1))
			return 0;
		GL_charge(jogatual,jogadores,MB_mpc_pow);
		sleep(t_delay);
		return MB_apc_pow; // Custo de aps
		}
// ==== Parar tempo ===================================================================
	case MB_ID_st:
		{
		if ((mpAtual < MB_mpc_st) || (jogadores[jogatual].buffer < 1) || (aps < MB_apc_st))
			return 0;
		MB_stopTime(jogatual,jogadores);
		sleep(t_delay);
		return MB_apc_st; // Custo de aps
		}
// ====================================================================================
	}
return 0; // Não foi uma escolha válida então não gasta ap.
}

// --------------------------------------------------------------------------------------
// -------------------------------- Funções internas ------------------------------------
// --------------------------------------------------------------------------------------

/* ----------------------------------------------------------------------------------------*/
/** @brief Painel de ações do mago branco
 * 
 * @param ap Número de pontos de movimento disponiveis ao jogador
 * @param mpAtual Mana atual do jogador
 * @param powstat Status do indicador de magia superior
 *
 * @return int opção digitada pelo jogador */
/* ----------------------------------------------------------------------------------------*/
int opcoes_branco(int ap,int mpAtual, int powstat)
{
int temp;
printf ("Voce ainda tem %d pontos de movimento.\n", ap);
printf ("<%d> para atacar com o seu cajado.\n",GL_caj);
printf ("	1-3 attack, 1 ap, 0 mp\n"); //revisar aqui constantes > variaveis
if (mpAtual >= MB_ID_fdl)
	{
	printf ("===============================================================\n");
	printf ("<%d> para concentrar um feixe de luz no seu adversario.\n",MB_ID_fdl);
	printf ("	%d-%d attack, %d ap, %d mp\n", MB_MIN_dmg_fdl, MB_MIN_dmg_fdl+MB_mod_fdl-1, MB_apc_fdl, MB_mpc_fdl);
	}

if ((mpAtual >= MB_mpc_ray) && (ap >= MB_apc_ray))
	{
	printf ("===============================================================\n");
	printf ("<%d> para direcionar um raio sobre seu adversario.\n",MB_ID_ray);
	printf ("	%d-%d attack, %d ap, %d mp\n", MB_MIN_dmg_ray, MB_MIN_dmg_ray+MB_mod_ray-1, MB_apc_ray, MB_mpc_ray);
	}

if ((mpAtual >= MB_mpc_fur) && (ap >= MB_apc_fur))
	{
	printf ("===============================================================\n");
	printf ("<%d> para criar um furacão.\n",MB_ID_fur);
	printf ("	%d-%d area attack, %d ap, %d mp\n", MB_MIN_dmg_fur, MB_MIN_dmg_fur+MB_mod_fur-1, MB_apc_fur, MB_mpc_fur);
	}

if ((mpAtual >= MB_mpc_torn) && (ap >= MB_apc_torn))
	{
	printf ("===============================================================\n");
	printf ("<%d> para criar um tornado sobre seu inimigo\n",MB_ID_torn);
	printf ("	%d-%d attack, %d ap, %d mp\n", MB_MIN_dmg_torn, MB_MIN_dmg_torn+MB_mod_torn-1, MB_apc_torn, MB_mpc_torn);
	}

if ((mpAtual >= MB_mpc_cur) && (ap >= MB_apc_cur))
	{
	printf ("===============================================================\n");
	printf ("<%d> para conjurar uma magia de cura.\n",MB_ID_cur);
	printf ("	%d-%d hps restaurados, %d ap, %d mp\n", MB_MIN_dmg_cur, MB_MIN_dmg_cur+MB_mod_cur-1, MB_apc_cur, MB_mpc_cur);
	}

if ((mpAtual >= MB_mpc_haste) && (ap >= MB_apc_haste))
	{
	printf ("===============================================================\n");
	printf ("<%d> para acelerar seu alvo.\n",MB_ID_haste);
	printf ("	+%d Aps, %d duração, %d ap, %d mp\n",MB_dmg_haste, MB_dur_haste, MB_apc_haste, MB_mpc_haste);
	}

if (ap >= MB_apc_con)
	{
	printf ("===============================================================\n");
	printf ("<%d> para se concentrar e restaurar parte de seu poder.\n",MB_ID_con);
	printf ("	%d-%d mps recuperados, %d ap\n", MB_MIN_dmg_con, MB_MIN_dmg_con+MB_mod_con-1, MB_apc_con);
	}
	
if ((mpAtual >= MB_mpc_pow) && (ap >= MB_apc_pow) && (powstat < 1))
	{
	printf ("===============================================================\n");
	printf ("<%d> Encantamento superior: Convocar circulo\n",MB_ID_pow);
	printf ("	Custo de mana: %d, Aps: %d\n", MB_mpc_pow,MB_apc_pow);
	}

if ((mpAtual >= MB_mpc_st) && (ap >= MB_apc_st) && (powstat > 0))
	{
	printf ("===============================================================\n");
	printf ("<%d> Magia superior: Parar tempo.\n",MB_ID_st);
	printf ("	Custo: %d ap, %d mp\n", MB_apc_st, MB_mpc_st);
	}

printf ("Ação: ");
scanf ("%d", &temp);
__fpurge(stdin);
return(temp);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Ataque especial: Parar tempo
 * Está magia adiciona MB_dmg_st pontos de movimento ao conjudaror, e trava a modificação posterior do apmod.
 * 
 * @param alvo Indice do jogador a receber o dano
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void MB_stopTime(int alvo, vetor jogadores)
{
int trava;
int esp = jogadores[alvo].apmod.esp;

// decompoe o especial
trava = esp % 10; esp = esp / 10;

// Se a trava de ap mod está ativada, não faz nada
if (trava == 1)
	{
	printf ("Sem efeito!\n");
	return;
	}
else // Se não tem trava, ativa.
	{
	jogadores[alvo].apmod.esp += 1;	
	}	

// Seta a duração
jogadores[alvo].apmod.dur = MB_dur_st;

// Adiciona a velocidade
jogadores[alvo].apmod.mod += MB_dmg_st;

printf ("O grande relógio é ajustado.\n");

jogadores[alvo].buffer -= 1;
jogadores[alvo].mp -= MB_mpc_st;
return;
}
