#include "definicoes.h"
#ifndef H_FUNCOESA_H
#define H_FUNCOESA_H

/** @file funcoesA.h
 * 
 * @brief Cabeçalho das funções "administrativas" (manipulação de fichas e jogadores.)
 */

/** --------------------------------------------------------------------------------------
 * @def decrementa_apdur
 * @brief Regra para decrementar a duração do modificador de velocidade (a cada turno a duração fica mais perto de zero) */
#define decrementa_apdur (jogadores[jogatual].apmod.dur>0)?(jogadores[jogatual].apmod.dur--):jogadores[jogatual].apmod.dur++
/** --------------------------------------------------------------------------------------
 * @def decrementa_hpdur
 * @brief Regra para decrementar a duração do modificador de pontos de vida (a cada turno a duração fica mais perto de zero) */
#define decrementa_hpdur (jogadores[jogatual].hpmod.dur>0)?(jogadores[jogatual].hpmod.dur--):jogadores[jogatual].hpmod.dur++
// --------------------------------------------------------------------------------------

void lipatudo (vetor);
void placar (int, int, vetor);
int opcoes(int, int);
int conta_vivos(vetor, int);
int cold_start(vetor jogadores); // Essa função retorna jogs(número de jogadores)
void trata_condicoes(int *aps,int jogatual,vetor jogadores);

#endif
