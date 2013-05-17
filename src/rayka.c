#include <stdio.h>			// inclui diretivas de entrada-saída
#include <stdlib.h>			// Usa recursos do sistema
#include <stdio_ext.h>		// Precisa para o fpurge
#include <unistd.h>			// Sleep sem syscall

#include "rayka.h"		//Constantes da rayka
#include "MagoVermelho.h"	//Constantes do mago vermelho
#include "definicoes.h"		// Constantes e structs usados no jogo
#include "funcoesA.h"		// Modulos básicos do jogo
#include "funcoesB.h"		// Modulos básicos do jogo

/* ======================================================================================== */
/**
 * @file rayka.c
 * @brief Maga vermelha: Rayka
 *
 *
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */


//----------------------------------- Protótipos ------------------------------------
int AI_rayka_target(int atual,int jogs, vetor jogadores);
//-------------------------------- Função principal ---------------------------------



/* ----------------------------------------------------------------------------------------*/
/** @brief Função principal da Rayka
 * Está é a função principal da AI "rayka" Ela decide um "Humor" (agressivo ou defensivo) aleatoriamente e a seqüencia de condições é baseada nesse humor.
 *
 * @param vivos Numero de jogadores vivos
 * @param aps AP disponivel
 * @param jogs Número de jogadores
 * @param jogatual Índice do jogador atual no vetor jogadores
 * @param jogadores Vetor de jogadores, contendo todos os dados de status, HP, MP e classe
 *
 * @return AP gasto */
/* ----------------------------------------------------------------------------------------*/
int acao_rayka(int vivos, int aps, int jogs,int jogatual,vetor jogadores)
{
int modA,alvo;
int raykaMP = jogadores[jogatual].mp;
int raykaHP = jogadores[jogatual].hp;
placar (jogs, jogatual, jogadores);
modA = rand()%(2);

if (modA) // Defensivo
	{
	printf ("Rayka entrou em modo defensivo!\n");
	/* Se Rayka estiver com pouco mp, concentra */
	if ((raykaMP < MV_mpc_plas+1) && (aps >= MV_apc_con))
		{
		printf("Rayka se concentra para recuperar seu poder!\n");
		GL_concentra(jogatual,jogadores,MV_MIN_dmg_con,MV_mod_con);
		sleep(t_delay);
		return MV_apc_con;
		}
	/* Se Rayka estiver com pouco hp, cura */
	if ((raykaHP < RaykaMinHP) && (aps >= MV_apc_cul) && (raykaMP >= MV_mpc_cul))
		{
		printf("Rayka usa seu poder para curar seus ferimentos!\n");
		GL_cura(jogatual,jogadores, MV_MIN_dmg_cul, MV_mod_cul, MV_mpc_cul);
		sleep(t_delay);
		return MV_apc_cul;
		}
	/* Se Rayka estiver com stat forte, negatis.
	Critério:
	1. Rayka tem mp e ap suficiente.
	2. Rayka vai perder no mínimo dois turnos pelas proximas duas rodadas
	ou
	2. Rayka var perder no mínimo três de hp pelas proximas três rodadas*/
	if (
		((aps >= MV_apc_neg) && (raykaMP >= MV_mpc_neg)) &&
		(  
		((jogadores[jogatual].apmod.mod < -1) && (jogadores[jogatual].apmod.dur < -1))
		|| /*or*/
		((jogadores[jogatual].hpmod.mod < -2) && (jogadores[jogatual].hpmod.dur < -2))
		)
	   )
		/*then*/
		{
		printf("Rayka neutraliza seus status!\n");
		GL_negatis(jogatual,jogadores);
		sleep(t_delay);
		return MV_mpc_neg;
		}
	/* Se nem cura nem concentração são necessários,  então ataque*/
	modA = !modA;
	}
if (!modA) // Agressivo
	{
	printf ("Rayka entrou em modo agressivo\n");
 	if ((raykaMP >= MV_mpc_exp) && (aps >= MV_apc_exp) && (vivos > 2))
		{
		printf ("Rayka conjura uma grande explosão!\n");
		GL_area_ataque(jogs, jogatual, jogadores, MV_MIN_dmg_exp, MV_mod_exp, MV_mpc_exp);
		sleep(t_delay);
		return MV_apc_exp;
		}
 	if ((raykaMP >= MV_mpc_plas) && (aps >= MV_apc_plas))
		{
		printf ("Rayka ataca seu inimigo com plasma!\n");
		alvo = AI_rayka_target(jogatual,jogs,jogadores);	
		GL_base_ataque(alvo,jogatual,jogadores,MV_MIN_dmg_plas,MV_mod_plas,MV_mpc_plas);
		sleep(t_delay);
		return MV_apc_plas;
		}
 	if ((raykaMP >= MV_mpc_bdf) && (aps >= MV_apc_bdf))
		{
/**<b>fixme:</b> AI_base_ataque devia cuidar de descontar mp como as outras funções de ataque fazem */
		printf ("Bola de fogo!\n");
		alvo = AI_rayka_target(jogatual,jogs,jogadores);
		GL_base_ataque(alvo,jogatual,jogadores,MV_MIN_dmg_bdf,MV_mod_bdf,MV_mpc_bdf);
		sleep(t_delay);
		return MV_apc_bdf;
		}
 	if ((raykaMP >= MV_mpc_lab) && (aps >= MV_apc_lab))
		{
		printf ("Labareda!\n");
		alvo = AI_rayka_target(jogatual,jogs,jogadores);
		GL_base_ataque(alvo,jogatual,jogadores,MV_MIN_dmg_lab,MV_mod_lab,MV_mpc_lab);
		sleep(t_delay);
		return MV_apc_lab;
		}
	}

// Se nada mais deu certo, cajadada!
printf("Rayka ataca com seu cajado!\n");
alvo = AI_rayka_target(jogatual,jogs,jogadores);
GL_base_ataque(alvo,jogatual,jogadores,GL_MIN_dmg_caj,GL_mod_caj,0);
sleep(t_delay);
return GL_apc_caj;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Rayka target
 * Procedimento para a escolha de alvo da ai "Rayka" <br>
 * Rayka sempre escolhe como alvo, o jogador mais fraco.
 *
 * @param atual Índice da rayka (para ela não se escolher como alvo.
 * @param jogs Número total de jogadores
 * @param jogadores Vetor de jogadores, contendo todos os dados de status, HP, MP e classe
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
int AI_rayka_target(int atual,int jogs, vetor jogadores)
{
int i,alvoHP=maxHP+1,alvo=0;
for (i=0; i < jogs ; i ++)
	if (i != atual)
		{
		if ((jogadores[i].hp < alvoHP) && (jogadores[i].hp > 0))
			{
			alvo=i;
			alvoHP=jogadores[i].hp;
			}
		}
return alvo;
}

