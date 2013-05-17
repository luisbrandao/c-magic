#include "definicoes.h"
#ifndef H_FUNCOESB_H
#define H_FUNCOESB_H

/** @file funcoesB.h
 * @brief Cabeçalhos das funções de combate genéricas 
 */

int target(int jogs, int jogatual, vetor jogadores, int spec);
void GL_base_ataque(int alvo, int jogatual, vetor jogadores, int min, int mod, int custo);
void GL_area_ataque(int jogs, int jogatual, vetor jogadores, int min, int mod, int custo);
void GL_mp_drain(int alvo, int jogatual, vetor jogadores, int min, int mod);
void GL_hp_drain(int alvo, int jogatual, vetor jogadores, int min, int mod, int custo);
void GL_concentra(int jogatual, vetor jogadores, int min, int mod);
void GL_hp_effect(int alvo, int jogatual, vetor jogadores,int efeito,int tempo,int custo);
void GL_ap_effect(int alvo, int jogatual, vetor jogadores,int efeito,int tempo, int custo);
void GL_cura(int alvo, vetor jogadores, int min, int mod, int custo);
void GL_charge(int jogatual,vetor jogadores, int custo);
void GL_negatis(int alvo,vetor jogadores);

#endif
