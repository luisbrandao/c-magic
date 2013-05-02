#include "definicoes.h"
#ifndef H_MAGO_NEGRO_H
#define H_MAGO_NEGRO_H

/** @file MagoNegro.h
 * 
 * @brief Cabeçalhos e definições da biblioteca "Mago negro"
 Biblioteca de funções, procedimentos e definições referentes a classe "Mago negro."<br>
 * Este arquivo de cabeçalhos contém a função global usada para a execução de uma ação de um Mago negro e as definições de dano, custos de aps e custos de mps das magias dessa classe.
 */
 
/*** === Missil mágico ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_mm
 * @brief Número identificador (opção) do ataque "Missil mágico". */
#define MN_ID_mm 2
/** --------------------------------------------------------------------------------------
 * @def MN_MIN_dmg_mm
 * @brief Dano mínimo causado pelo ataque "Missil mágico". */
#define MN_MIN_dmg_mm 1
/** --------------------------------------------------------------------------------------
 * @def MN_mod_mm
 * @brief Modificador do ataque "v", usado no calculo de dano. */
#define MN_mod_mm 6
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_mm
 * @brief Custo em pontos de mana do ataque "Missil mágico". */
#define MN_mpc_mm 0
/** --------------------------------------------------------------------------------------
 * @def MN_apc_mm
 * @brief Custo em pontos de movimento da magia "Missil mágico".*/
#define MN_apc_mm 1
// --------------------------------------------------------------------------------------


/*** === Estigma ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_stg
 * @brief Número identificador (opção) da magia "Estigma". */
#define MN_ID_stg 3
/**  --------------------------------------------------------------------------------------
 * @def MN_dmg_stg
 * @brief Dano adicionado por cada invocação da magia "Estigma" */
#define MN_dmg_stg -2
/**  --------------------------------------------------------------------------------------
 * @def MN_dur_stg
 * @brief Duração adicionada a cada invocação da magia "Estigma" */
#define MN_dur_stg -4
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_stg
 * @brief Custo em pontos de mana do ataque "Estigma". */
#define MN_mpc_stg 4
/** --------------------------------------------------------------------------------------
 * @def MN_apc_stg
 * @brief Custo em pontos de movimento da magia "Estigma".*/
#define MN_apc_stg 2
// --------------------------------------------------------------------------------------


/*** === Retalhador de almas ==========================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_sr
 * @brief Número identificador (opção) da magia "Retalhador de almas". */
#define MN_ID_sr 4
/** --------------------------------------------------------------------------------------
 * @def MN_MIN_dmg_sr
 * @brief Dano mínimo causado pela magia "Retalhador de almas". */
#define MN_MIN_dmg_sr 20
/** --------------------------------------------------------------------------------------
 * @def MN_mod_sr
 * @brief Modificador da magia "Retalhador de almas", usado no calculo de dano. */
#define MN_mod_sr 22
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_sr
 * @brief Custo em pontos de mana da magia "Retalhador de almas". */
#define MN_mpc_sr 10
/** --------------------------------------------------------------------------------------
 * @def MN_apc_sr
 * @brief Custo em pontos de movimento da magia "Retalhador de almas". */
#define MN_apc_sr 4
// --------------------------------------------------------------------------------------


/*** === Exordia ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_exo
 * @brief Número identificador (opção) da magia "Exordia". */
#define MN_ID_exo 5/** --------------------------------------------------------------------------------------
 * @def MN_MIN_dmg_exo
 * @brief Dano mínimo causado pela magia "Exordia". */
#define MN_MIN_dmg_exo 15
/** --------------------------------------------------------------------------------------
 * @def MN_mod_exo
 * @brief Modificador da magia "Exordia", usado no calculo de dano. */
#define MN_mod_exo 20
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_exo
 * @brief Custo em pontos de mana da magia "Exordia". */
#define MN_mpc_exo 15
/** --------------------------------------------------------------------------------------
 * @def MN_apc_exo
 * @brief Custo em pontos de movimento da magia "Exordia". */
#define MN_apc_exo 4
// --------------------------------------------------------------------------------------


/*** === Maldição ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_cur
 * @brief Número identificador (opção) da magia "Maldição". */
#define MN_ID_cur 6
/**  --------------------------------------------------------------------------------------
 * @def MN_vdmg_cur
 * @brief Dano adicionado ao veneno por cada invocação da magia "Maldição" */
#define MN_vdmg_cur -3			// Dano por rodada adicionando a cada magia
/**  --------------------------------------------------------------------------------------
 * @def MN_vdur_cur
 * @brief Duração adicionada ao veneno a cada invocação da magia "Maldição" */
#define MN_vdur_cur -3			// duração do veneno
/**  --------------------------------------------------------------------------------------
 * @def MN_ldmg_cur
 * @brief Dano adicionado a lentidão por cada invocação da magia "Maldição" */
#define MN_ldmg_cur -1		// perda de aps por rodada
/**  --------------------------------------------------------------------------------------
 * @def MN_ldur_cur
 * @brief Duração adicionada a lentidão a cada invocação da magia "Maldição" */
#define MN_ldur_cur -1		// duração da perda de aps por magia
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_cur
 * @brief Custo em pontos de mana da magia "Maldição". */
#define MN_mpc_cur 8
/** --------------------------------------------------------------------------------------
 * @def MN_apc_cur
 * @brief Custo em pontos de movimento da magia "Maldição".*/
#define MN_apc_cur 4
// --------------------------------------------------------------------------------------


/*** === Drenar Hp ==================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_hpd
 * @brief Número identificador (opção) do ataque "Drenar Hp". */
#define MN_ID_hpd 7/** --------------------------------------------------------------------------------------
 * @def MN_MIN_dmg_hpd
 * @brief Dano mínimo causado pelo ataque "Drenar Hp". */
#define MN_MIN_dmg_hpd 5
/** --------------------------------------------------------------------------------------
 * @def MN_mod_hpd
 * @brief Modificador do ataque "Drenar Hp", usado no calculo de dano. */
#define MN_mod_hpd 6
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_hpd
 * @brief Custo em pontos de mana do ataque "Drenar Hp". */
#define MN_mpc_hpd 6
/** --------------------------------------------------------------------------------------
 * @def MN_apc_hpd
 * @brief Custo em pontos de movimento da magia "Drenar Hp".*/
#define MN_apc_hpd 2
// --------------------------------------------------------------------------------------


/*** === Drenar MP ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_mpd
 * @brief Número identificador (opção) do ataque "Drenar MP". */
#define MN_ID_mpd 8
/** --------------------------------------------------------------------------------------
 * @def MN_MIN_dmg_mpd
 * @brief Dano mínimo causado pelo ataque "Drenar MP". */
#define MN_MIN_dmg_mpd 4
/** --------------------------------------------------------------------------------------
 * @def MN_mod_mpd
 * @brief Modificador do ataque "Drenar MP", usado no calculo de dano. */
#define MN_mod_mpd 9
/** --------------------------------------------------------------------------------------
 * @def MN_apc_mpd
 * @brief Custo em pontos de movimento da magia "Drenar MP".*/
#define MN_apc_mpd 3
// --------------------------------------------------------------------------------------


/*** === Charge ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_pow
 * @brief Número identificador (opção) da magia "convocar circulo superior" */
#define MN_ID_pow 9
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_pow
 * @brief Custo em pontos de mana do da magia "convocar circulo superior"*/
#define MN_mpc_pow 10
/** --------------------------------------------------------------------------------------
 * @def MN_apc_pow
 * @brief Custo em pontos de movimento da magia da magia "convocar circulo superior"*/
#define MN_apc_pow 4
// --------------------------------------------------------------------------------------


/*** === Sonho Vampírico ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_sv
 * @brief Número identificador (opção) do ataque "Sonho Vampírico". */
#define MN_ID_sv 10/** --------------------------------------------------------------------------------------
 * @def MN_MIN_dmg_sv
 * @brief Dano mínimo causado pelo ataque "Sonho Vampírico". */
#define MN_MIN_dmg_sv 7
/** --------------------------------------------------------------------------------------
 * @def MN_mod_sv
 * @brief Modificador do ataque "Sonho Vampírico", usado no calculo de dano. */
#define MN_mod_sv 12
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_sv
 * @brief Custo em pontos de mana do ataque "Sonho Vampírico". */
#define MN_mpc_sv 4
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_sv
 * @brief Custo em pontos de mana do ataque "Sonho Vampírico". */
#define MN_apc_sv 3
// --------------------------------------------------------------------------------------


/*** === Sombra da lua ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MN_ID_sl
 * @brief Número identificador (opção) do ataque "Sombra da lua". */
#define MN_ID_sl 10
/** --------------------------------------------------------------------------------------
 * @def MN_mpc_sl
 * @brief Custo em pontos de mana do ataque "Sombra da lua". */
#define MN_mpc_sl 10
/** --------------------------------------------------------------------------------------
 * @def MN_apc_sl
 * @brief Custo em pontos de movimento da magia "Sombra da lua".*/
#define MN_apc_sl 4
// --------------------------------------------------------------------------------------

int acao_negro(int aps, int jogs,int jogatual,vetor jogadores); // Essa função retorna quantos aps foram gastos

#endif
