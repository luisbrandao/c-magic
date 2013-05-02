#include <stdio.h>			// inclui diretivas de entrada-saída
#include <stdlib.h>			// Usa recursos do sistema
#include <stdio_ext.h>		// Precisa para o fpurge
#include <unistd.h>			// Sleep sem syscall

#include "MagoNegro.h"		//Constantes do mago hpdro
#include "funcoesA.h"		// Modulos básicos do jogo
#include "funcoesB.h"		// Modulos básicos do jogo
#include "definicoes.h"		// Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file MagoNegro.c
 * @brief Biblioteca de procedimentos do mago Negro
 * Esta bliblioteca tem como objetivo implementar a classe secreta "mago Negro", exibindo na tela o menu de ações possíveis do mago, e tratando a entrada do jogador, decidindo se o movimento é válido ou não.<br>
 * Essa função também cuida dos ataques especiais do mago Negro.
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

//------------------------------------- Protótipos ------------------------------------------
int opcoes_negro (int ap,int mpAtual,int powstat);
void MN_vampDream	(int jogs,int jogatual,vetor jogadores);

/* ----------------------------------------------------------------------------------------*/
/** @brief Ações do mago negro
 * Está é a função que invoca o painel de ações do mago negro, trata a entrada do jogador, chama respectiva função do movimento escolhido e retorna o número de mps gastos na rodada.
 * 
 * @param aps Número de pontos de movimento disponiveis ao jogador
 * @param jogs Número total de jogadores
 * @param jogatual indice do jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int apc_<ação> Caso a entrada do jogador seja válida
 * @return 0 Caso a entrada do jogador seja inválida  */
/* ----------------------------------------------------------------------------------------*/
int acao_negro(int aps, int jogs,int jogatual,vetor jogadores)
{
int acao;
placar (jogs, jogatual, jogadores);
acao = opcoes_negro(aps,jogadores[jogatual].mp,jogadores[jogatual].buffer);

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
// ==== Míssil mágico =================================================================
	case MN_ID_mm:
		{
		if ((jogadores[jogatual].mp < MN_mpc_mm) || (aps < MN_apc_mm))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores,MN_MIN_dmg_mm, MN_mod_mm, MN_mpc_mm);
		sleep(t_delay);
		return MN_apc_mm; // Custo de aps do missil mágico
		}
// ==== Estigma =======================================================================
	case MN_ID_stg:
		{
		if ((jogadores[jogatual].mp < MN_mpc_stg) || (aps < MN_apc_stg))
			return 0;
		acao = target(jogs, jogatual, jogadores, 0);
		GL_hp_effect(acao,jogatual,jogadores,MN_dmg_stg,MN_dur_stg, MN_mpc_stg);
		sleep(t_delay);
		return MN_apc_stg; // Custo de aps
		}
// ==== Retalhador de almas ===========================================================
	case MN_ID_sr:
		{
		if ((jogadores[jogatual].mp < MN_mpc_sr) || (jogadores[jogatual].buffer == 0) || (aps < MN_apc_sr))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MN_MIN_dmg_sr,MN_mod_sr, MN_mpc_sr);
		jogadores[jogatual].buffer -= 1; // GL_base não sabe tratar do buffer.
		sleep(t_delay);
		return MN_apc_sr; // Custo de aps
		}
// ==== Exordia =======================================================================
	case MN_ID_exo:
		{
		if ((jogadores[jogatual].mp < MN_mpc_exo) || (jogadores[jogatual].buffer == 0) || (aps < MN_apc_exo))
			return 0;
		GL_area_ataque(jogs, jogatual, jogadores, MN_MIN_dmg_exo, MN_mod_exo, MN_mpc_exo);
		jogadores[jogatual].buffer -= 1; // GL_area não sabe tratar do buffer.
		sleep(t_delay);
		return MN_apc_exo; // Custo de aps
		}
// ==== Maldição ======================================================================
	case MN_ID_cur:
		{
		if ((jogadores[jogatual].mp < MN_mpc_cur) || (aps < MN_apc_cur))
			return 0;
			
		/* O custo de mp da hp_effect é zero pois esse custo só deve ser cobrado uma vez e a ap_effect já cuida disso */

		acao = target(jogs,jogatual,jogadores,0);
		
		GL_ap_effect(acao,jogatual,jogadores,MN_ldmg_cur,MN_ldur_cur, MN_mpc_cur);
		GL_hp_effect(acao,jogatual,jogadores,MN_vdmg_cur,MN_vdur_cur, 0);
	
		sleep(t_delay);
		return MN_apc_cur; // Custo de aps
		}

// ==== Sugar vida ====================================================================
	case MN_ID_hpd:
		{
		if ((jogadores[jogatual].mp < MN_mpc_hpd) || (aps < MN_apc_hpd))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_hp_drain(acao, jogatual, jogadores, MN_MIN_dmg_hpd, MN_mod_hpd, MN_mpc_hpd);
		sleep(t_delay);
		return MN_apc_hpd; // Custo de aps
		}
// ==== Sugar mana ====================================================================
	case MN_ID_mpd:
		{
		if (aps < MN_apc_mpd)
			return 0;
		acao = target(jogs,jogatual,jogadores,1);
		GL_mp_drain(acao, jogatual, jogadores, MN_MIN_dmg_mpd, MN_mod_mpd);
		sleep(t_delay);
		return MN_apc_mpd; // Custo de aps
		}
// ==== Magia Superior ================================================================
	case MN_ID_pow:
		{
		if ((jogadores[jogatual].mp < MN_mpc_pow) || (aps < MN_apc_pow)|| (jogadores[jogatual].buffer > 2))
			return 0;
		GL_charge(jogatual,jogadores,MN_mpc_pow);
		sleep(t_delay);
		return MN_apc_pow; // Custo de aps
		}
// ==== Sonho vampírico ===============================================================
	case MN_ID_sv:
		{
		if ((jogadores[jogatual].mp < MN_mpc_sv) || (jogadores[jogatual].buffer < 2) || (aps < MN_apc_sv))
			return 0;
		MN_vampDream(jogs,jogatual,jogadores);
		sleep(t_delay);
		return MN_apc_sv; // Custo de aps
		}
// ====================================================================================
	}
return 0; // Não foi uma escolha válida então não gasta ap.
}

// --------------------------------------------------------------------------------------
// -------------------------------- Funções internas ------------------------------------
// --------------------------------------------------------------------------------------

/* ----------------------------------------------------------------------------------------*/
/** @brief Painel de ações do mago negro
 * 
 * @param ap Número de pontos de movimento disponiveis ao jogador
 * @param mpAtual Mana atual do jogador
 * @param powstat Status do indicador de magia superior
 *
 * @return int opção digitada pelo jogador */
/* ----------------------------------------------------------------------------------------*/
int opcoes_negro(int ap,int mpAtual,int powstat)
{
int temp;
printf ("Voce ainda tem %d pontos de movimento.\n", ap);
printf ("<%d> para atacar com o seu cajado.\n",GL_caj);
printf ("	1-3 attack, 1 ap, 0 mp\n"); //revisar aqui mpdstantes > variaveis
if ((mpAtual >= MN_mpc_mm) && (ap >= MN_apc_mm))
	{
	printf ("===============================================================\n");
	printf ("<%d> para lancar um missil mágico.\n",MN_ID_mm);
	printf ("	%d-%d attack, %d ap, %d mp\n", MN_MIN_dmg_mm, MN_MIN_dmg_mm+MN_mod_mm-1, MN_apc_mm, MN_mpc_mm);
	}
if ((mpAtual >= MN_mpc_stg) && (ap >= MN_apc_stg))
	{
	printf ("===============================================================\n");
	printf ("<%d> estigma.\n",MN_ID_stg);
	printf ("	%d dano, %d duração, %d ap, %d mp\n", MN_dmg_stg, MN_dur_stg, MN_apc_stg, MN_mpc_stg);
	}
if ((mpAtual >= MN_mpc_sr) && (ap >= MN_apc_sr) && (powstat > 0))
	{
	printf ("===============================================================\n");
	printf ("<%d> Magia superior: Retalhador de almas.\n",MN_ID_sr);
	printf ("	%d-%d attack, %d ap, %d mp\n", MN_MIN_dmg_sr, MN_MIN_dmg_sr+MN_mod_sr-1, MN_apc_sr, MN_mpc_sr);
	}

if ((mpAtual >= MN_mpc_exo) && (ap >= MN_apc_exo) && (powstat > 0))
	{
	printf ("===============================================================\n");
	printf ("<%d> Magia superior: Exórdia.\n",MN_ID_exo);
	printf ("	%d-%d area attack, %d ap, %d mp\n", MN_MIN_dmg_exo, MN_MIN_dmg_exo+MN_mod_exo-1, MN_apc_exo, MN_mpc_exo);
	}

if ((mpAtual >= MN_mpc_cur) && (ap >= MN_apc_cur))
	{
	printf ("===============================================================\n");
	printf ("<%d> Maldição.\n",MN_ID_cur);
	printf ("	%d dano, %d duração; lentidão, %d duração, %d ap, %d mp\n", MN_vdmg_cur, MN_vdur_cur, MN_vdur_cur, MN_apc_cur, MN_mpc_cur);
	}

if ((mpAtual >= MN_mpc_hpd) && (ap >= MN_apc_hpd))
	{
	printf ("===============================================================\n");
	printf ("<%d> Drenar a vida de seu adversário.\n",MN_ID_hpd);
	printf ("	%d-%d sugados, %d ap, %d mp\n", MN_MIN_dmg_hpd, MN_MIN_dmg_hpd+MN_mod_hpd-1, MN_apc_hpd, MN_mpc_hpd);
	}

if (ap >= MN_apc_mpd)
	{
	printf ("===============================================================\n");
	printf ("<%d> Drenar o poder de seu adversario.\n",MN_ID_mpd);
	printf ("	%d-%d mana sugada, %d ap\n", MN_MIN_dmg_mpd, MN_MIN_dmg_mpd+MN_mod_mpd-1, MN_apc_mpd);
	}

if ((mpAtual >= MN_mpc_pow) && (ap >= MN_apc_pow) && (powstat < 2))
	{
	printf ("===============================================================\n");
	printf ("<%d> Encantamento superior: Convocar circulo\n",MN_ID_pow);
	printf ("	Custo de mana: %d; Aps: %d\n", MN_mpc_pow,MN_apc_pow);
	}

if ((mpAtual >= MN_mpc_exo) && (ap >= MN_apc_exo) && (powstat > 1))
	{
	printf ("===============================================================\n");
	printf ("<%d> Magia suprema: Sonho vampírico.\n",MN_ID_sv);
	printf ("	%d-%d area attack, %d ap, %d mp\n", MN_MIN_dmg_sv, MN_MIN_dmg_sv+MN_mod_sv-1, MN_apc_sv, MN_mpc_sv);
	}

printf ("Ação: ");
scanf ("%d", &temp);
__fpurge(stdin);
return(temp);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Ataque especial: Sonho Vampirico
 * Esse é o ataque especial do mago negro. Esse ataque funciona exatamente como o "drenar hp", mas ao invez de machucar apenas um jogador, afeta todos.
 * 
 * @param jogs Número total de jogadores
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void MN_vampDream(int jogs,int jogatual,vetor jogadores)
{
int alvo,dmg,buffer = 0,total=0;
jogadores[jogatual].buffer = 0;

for (alvo=0; alvo < jogs ; alvo ++)
	if (alvo != jogatual)
		{
		dmg = (rand()%MN_mod_sv)+MN_MIN_dmg_sv;
		jogadores[alvo].hp -= dmg;
		printf ("%s teve %d Hps sugados\n",jogadores[alvo].nome,dmg);
		buffer += dmg -1;
		total += dmg;
		}


jogadores[jogatual].hp += buffer;
jogadores[jogatual].mp -= MN_mpc_sv;

printf ("\n%d Hps sugados, %d Hps absorvidos.\n",total,buffer);
}
