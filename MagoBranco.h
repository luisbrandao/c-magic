#include "definicoes.h"
#ifndef H_MAGO_BRANCO_H
#define H_MAGO_BRANCO_H

/** @file MagoBranco.h
 * 
 * @brief Cabeçalhos e definições da biblioteca "Mago branco"
 Biblioteca de funções, procedimentos e definições referentes a classe "Mago branco."<br>
 * Este arquivo de cabeçalhos contém a função global usada para a execução de uma ação de um Mago branco e as definições de dano, custos de aps e custos de mps das magias dessa classe.
 */
 
/*** ====== Feixe de luz ================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_fdl
 * @brief Número identificador (opção) do ataque "Feixe de luz". */
#define MB_ID_fdl 2
/** --------------------------------------------------------------------------------------
 * @def MB_MIN_dmg_fdl
 * @brief Dano mínimo causado pelo ataque "Feixe de luz". */
#define MB_MIN_dmg_fdl 2
/** --------------------------------------------------------------------------------------
 * @def MB_mod_fdl
 * @brief Modificador do ataque "Feixe de luz", usado no calculo de dano. */
#define MB_mod_fdl 3
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_fdl
 * @brief Custo em pontos de mana do ataque "Feixe de luz". */
#define MB_mpc_fdl 2
/** --------------------------------------------------------------------------------------
 * @def MB_apc_fdl
 * @brief Custo em pontos de movimento do ataque "Feixe de luz". */
#define MB_apc_fdl 1
// --------------------------------------------------------------------------------------


/*** ====== Raio ========================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_ray
 * @brief Número identificador (opção) do ataque "Raio". */
#define MB_ID_ray 3
/** --------------------------------------------------------------------------------------
 * @def MB_MIN_dmg_ray
 * @brief Dano minimo causado pelo ataque "Raio". */
#define MB_MIN_dmg_ray 3
/** --------------------------------------------------------------------------------------
 * @def MB_mod_ray
 * @brief Modificador do ataque "Raio", usado no calculo de dano. */
#define MB_mod_ray 4
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_ray
 * @brief Custo em pontos de mana do ataque "Raio". */
#define MB_mpc_ray 3
/** --------------------------------------------------------------------------------------
 * @def MB_apc_ray
 * @brief Custo em pontos de movimento do ataque "Raio". */
#define MB_apc_ray 2
// --------------------------------------------------------------------------------------


/*** ====== Furacão ===================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_fur
 * @brief Número identificador (opção) do ataque "Furacão". */
#define MB_ID_fur 4
/** --------------------------------------------------------------------------------------
 * @def MB_MIN_dmg_fur
 * @brief Dano minimo causado pelo ataque "Furacão". */
#define MB_MIN_dmg_fur 5
/** --------------------------------------------------------------------------------------
 * @def MB_mod_fur
 * @brief Modificador do ataque "Furacão", usado no calculo de dano. */
#define MB_mod_fur 6
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_fur
 * @brief Custo em pontos de mana do ataque "Furacão". */
#define MB_mpc_fur 5
/** --------------------------------------------------------------------------------------
 * @def MB_apc_fur
 * @brief Custo em pontos de movimento do ataque "Furacão". */
#define MB_apc_fur 5
// --------------------------------------------------------------------------------------


/*** ====== Tornado ===================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_torn
 * @brief Número identificador (opção) do ataque "Tornado". */
#define MB_ID_torn 5
/** --------------------------------------------------------------------------------------
 * @def MB_MIN_dmg_torn
 * @brief Dano minimo causado pelo ataque "Tornado". */
#define MB_MIN_dmg_torn 5
/** --------------------------------------------------------------------------------------
 * @def MB_mod_torn
 * @brief Modificador do ataque "Tornado", usado no calculo de dano. */
#define MB_mod_torn 11
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_torn
 * @brief Custo em pontos de mana do ataque "Tornado". */
#define MB_mpc_torn 6
/** --------------------------------------------------------------------------------------
 * @def MB_apc_torn
 * @brief Custo em pontos de movimento do ataque "Tornado". */
#define MB_apc_torn 3
// --------------------------------------------------------------------------------------


/*** ====== Cura ======================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_cur
 * @brief Número identificador (opção) do ataque "Cura". */
#define MB_ID_cur 6
/** --------------------------------------------------------------------------------------
 * @def MB_MIN_dmg_cur
 * @brief Dano minimo causado pelo ataque "Cura". */
#define MB_MIN_dmg_cur 7
/** --------------------------------------------------------------------------------------
 * @def MB_mod_cur
 * @brief Modificador do ataque "Cura", usado no calculo de dano. */
#define MB_mod_cur 8
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_cur
 * @brief Custo em pontos de mana do ataque "Cura". */
#define MB_mpc_cur 4
/** --------------------------------------------------------------------------------------
 * @def MB_apc_cur
 * @brief Custo em pontos de movimento do ataque "Cura". */
#define MB_apc_cur 3
// --------------------------------------------------------------------------------------


/*** ====== Velocidade (haste) ========================================================== */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_haste
 * @brief Número identificador (opção) da magia de "Velocidade (haste)". */
#define MB_ID_haste 7
/** --------------------------------------------------------------------------------------
 * @def MB_dmg_haste
 * @brief Aceleração causada pelo uso da magia de "Velocidade (haste)"*/
#define MB_dmg_haste 4
/** --------------------------------------------------------------------------------------
 * @def MB_dur_haste
 * @brief Duração que a aceleração causada pela magia "Velocidade (haste)" perdurará */
#define MB_dur_haste 3
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_haste
 * @brief Custo em pontos de mana da magia de "Velocidade (haste)". */
#define MB_mpc_haste 5
/** --------------------------------------------------------------------------------------
 * @def MB_apc_haste
 * @brief Custo em pontos de movimento da magia "Velocidade (haste)" "". */
#define MB_apc_haste 4
// --------------------------------------------------------------------------------------


/*** ====== Concentração ================================================================ */
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_con
 * @brief Número identificador (opção) do movimento Concentração. */
#define MB_ID_con 8
/** --------------------------------------------------------------------------------------
 * @def MB_MIN_dmg_con
 * @brief Dano minimo causado pelo movimento Concentração. */
#define MB_MIN_dmg_con 8
/** --------------------------------------------------------------------------------------
 * @def MB_mod_con
 * @brief Modificador do movimento movimento, usado no calculo de mp recuperado. */
#define MB_mod_con 14
/** --------------------------------------------------------------------------------------
 * @def MB_apc_con
 * @brief Custo em pontos de movimento do movimento concentração. */
#define MB_apc_con 4
// --------------------------------------------------------------------------------------


/*** === Convocar círculo superior =====================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_pow
 * @brief Número identificador (opção) da magia "convocar circulo superior" */
#define MB_ID_pow 9
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_pow
 * @brief Custo em pontos de mana do da magia "convocar circulo superior"*/
#define MB_mpc_pow 10
/** --------------------------------------------------------------------------------------
 * @def MB_apc_pow
 * @brief Custo em pontos de movimento da magia da magia "convocar circulo superior"*/
#define MB_apc_pow 4


/*** === Parar tempo ===================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MB_ID_st
 * @brief Número identificador (opção) da magia "Parar tempo" */
#define MB_ID_st 10
/** --------------------------------------------------------------------------------------
 * @def MB_dur_st
 * @brief Aceleração causada pelo uso da magia de "Parar tempo"*/
#define MB_dur_st 1
/** --------------------------------------------------------------------------------------
 * @def MB_dmg_st
 * @brief Aceleração causada pelo uso da magia de "Parar tempo"*/
#define MB_dmg_st 16
/** --------------------------------------------------------------------------------------
 * @def MB_mpc_st
 * @brief Custo em pontos de mana do da magia "Parar tempo"*/
#define MB_mpc_st 10
/** --------------------------------------------------------------------------------------
 * @def MB_apc_st
 * @brief Custo em pontos de movimento da magia da magia "Parar tempo"*/
#define MB_apc_st 5


int acao_branco(int aps, int jogs,int jogatual,vetor jogadores); // Essa função retorna quantos aps foram gastos

#endif
