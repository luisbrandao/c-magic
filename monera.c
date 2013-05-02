#include <stdio.h>			// inclui diretivas de entrada-saída
#include <stdlib.h>     	// Usa recursos do sistema
#include <time.h>			// Permite o uso do tempo do sistema 
#include <stdio_ext.h>		// Precisa para o fpurge
#include <unistd.h>			// Sleep sem syscall

#include "definicoes.h"
#include "MagoVerde.h"
#include "monera.h"
#include "funcoesA.h"
#include "funcoesB.h"

/* ======================================================================================== */
/**
 * @file monera.c
 * @brief Biblioteca de funções, procedimentos e definições referentes ao AI de mago verde "Monera"
 * Este arquivo de cabeçalhos contém a função global usada para as decisões do AI Monera e as definições de Índices dos movimentos no vetor auxiliar utilizado.<br>
 * <br>
 * @author Fabricio Schiavon Kolberg
 */
/* ======================================================================================== */

// === Funções locais =======================================================================  

// ==========================================================================================

/* ----------------------------------------------------------------------------------------*/
/** @brief Função principal do Monera
 *
 * Esta função é o "cérebro" do nosso AI, ela toma a decisão do movimento e retorna os aps gastos
 *
 * @param vivos Numero de jogadores vivos
 * @param aps AP disponivel
 * @param jogs Número de jogadores
 * @param jogatual Índice do jogador atual no vetor jogadores
 * @param jogadores Vetor de jogadores, contendo todos os dados de status, HP, MP e classe
 *
 * @return AP gasto */
/* ----------------------------------------------------------------------------------------*/
int acao_monera(int vivos, int aps, int jogs,int jogatual,vetor jogadores){
	int possivel[7];
	int minimoHPmod = -1, minimoAPmod = -1, i;
	placar (jogs, jogatual, jogadores);
//parte 1: verificar a possibilidade de todos os movimentos
	//monera_CAJADO vai ser sempre possivel
	possivel[0]=1;
	
	//verificar tempestade de monera_monera_FOLHAS
	possivel[monera_FOLHA]=0;
	if(aps >= MG_apc_tdf && jogadores[jogatual].mp >= MG_mpc_tdf && vivos > 2)
		possivel[monera_FOLHA]=1;
	
	//verificar monera_ESPOROS corrosivos
	possivel[monera_ESPOROS]=0;
	if(aps >= MG_apc_ec && jogadores[jogatual].mp >= MG_mpc_ec && minimoHPmod >= GBL_hp_loss)
		possivel[monera_ESPOROS]=1;
	
	//verificar monera_VENENO
	possivel[monera_VENENO]=0;
	if(aps >= MG_apc_ven && jogadores[jogatual].mp >= MG_mpc_ven && minimoHPmod >= GBL_hp_loss)
		possivel[monera_VENENO]=1;

	//verificar monera_HPDRAIN
	possivel[monera_HPDRAIN]=0;
	if(aps >= MG_apc_hpd && jogadores[jogatual].mp >= MG_mpc_hpd)
		possivel[monera_HPDRAIN]=1;
	
	//verificar monera_ENROLAR
	possivel[monera_ENROLAR]=0;
	if(aps >= MG_apc_enrol && jogadores[jogatual].mp >= MG_mpc_enrol && minimoAPmod >= GBL_ap_loss)
		possivel[monera_ENROLAR]=1;

	//verificar monera_MPDRAIN
	possivel[monera_MPDRAIN]=0;
	if(aps >= MG_apc_mpd)
		possivel[monera_MPDRAIN]=1;

// parte 2: COMANDOS COM PRIORIDADE 
	// prioridade 1: causar status de HPmod

	for(i=0; i<jogs && (possivel[monera_VENENO] || possivel[monera_ESPOROS]); i++)
		if(jogadores[i].hpmod.mod>minimoHPmod && jogadores[i].hp > 0 && i!=jogatual)
			{
			if(!possivel[monera_VENENO]){
				printf("Monera lança esporos corrosivos em %s!\n",jogadores[i].nome);
				GL_hp_effect(i, jogatual, jogadores, MG_dmg_ec, MG_dur_ec,MG_mpc_ec);
				sleep(t_delay);
				return MG_apc_ec;
				}
			else{
				printf("Monera lança veneno em %s!\n",jogadores[i].nome);
				GL_hp_effect(i, jogatual, jogadores, MG_dmg_ven, MG_dur_ven,MG_mpc_ven);
				sleep(t_delay);
				return MG_apc_ven;
				}

			}

	minimoHPmod=jogadores[0==jogatual?1:0].hpmod.mod-1;
	if(minimoHPmod < GBL_hp_loss) minimoHPmod=GBL_hp_loss;

	// prioridade 2: causar status de APmod
	for(i=0; i<jogs && possivel[monera_ENROLAR]; i++)
		if(jogadores[i].apmod.mod>minimoAPmod && jogadores[i].hp > 0 && i!=jogatual){
			printf("Monera enrola %s!\n",jogadores[i].nome);
			GL_ap_effect(i, jogatual, jogadores, MG_dmg_enrol, MG_dur_enrol, MG_mpc_enrol);
			sleep(t_delay);
			return MG_apc_enrol;
		}

	minimoAPmod=jogadores[0==jogatual?1:0].apmod.mod-1;
	if(minimoAPmod < GBL_ap_loss) minimoAPmod=GBL_ap_loss;

	// prioridade 3: ficou sem HP, usa monera_HPDRAIN
	if(possivel[monera_HPDRAIN] && jogadores[jogatual].hp < 50)
		for(i=0; i<jogs; i++)
			if(jogadores[i].hp > jogadores[jogatual].hp || (jogadores[i].hp <= MG_mod_hpd+3 && jogadores[i].hp > 0 && i != jogatual)){		printf("Monera suga a energia vital de %s!\n",jogadores[i].nome);
				GL_hp_drain(i, jogatual, jogadores, MG_MIN_dmg_hpd, MG_mod_hpd, MG_mpc_hpd);
				sleep(t_delay);
				return MG_apc_hpd;

			}

	// prioridade 4: ficou sem MP, usar monera_MPDRAIN
	if(possivel[monera_MPDRAIN] && jogadores[jogatual].mp < 10)
		for(i=0; i<jogs; i++)
			if(jogadores[i].mp > jogadores[jogatual].mp){
				printf("Monera suga a energia mágica de %s!\n",jogadores[i].nome);
				GL_mp_drain(i, jogatual, jogadores, MG_MIN_dmg_mpd, MG_mod_mpd);
				sleep(t_delay);
				return MG_apc_mpd;

			}

	// prioridade 5: nada de util, usar tempestade de monera_monera_FOLHAS
	if(possivel[monera_FOLHA]){
		printf("Monera lança tempestade de FOLHAS!\n");
		GL_area_ataque(jogs,jogatual,jogadores,MG_MIN_dmg_tdf,MG_mod_tdf,MG_mpc_tdf);
		sleep(t_delay);
		return MG_apc_tdf;
	}

	// prioridade 6: fodeu, mete o monera_CAJADO 
	int alvo;
	printf("Monera golpeia com seu CAJADO!\n");
	alvo=rand()%jogs;
	while(alvo == jogatual || jogadores[alvo].hp <= 0)
		alvo=rand()%jogs;
		
	GL_base_ataque(alvo, jogatual, jogadores, GL_MIN_dmg_caj,  GL_mod_caj, 0);
	sleep(t_delay);
	return GL_apc_caj;
}

