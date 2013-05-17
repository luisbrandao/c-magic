#include "definicoes.h"
#ifndef H_MAGO_VERMELHO_H
#define H_MAGO_VERMELHO_H

/** @file MagoVermelho.h
 * @brief Cabeçalhos e definições da biblioteca "Mago Vermelho"
 Biblioteca de funções, procedimentos e definições referentes a classe "Mago Vermelho."
 * Este arquivo de cabeçalhos contém a função global usada para a execução de uma ação de um Mago Vermelho e as definições de dano, custos de aps e custos de mps das magias dessa classe. */

/*** ====== Labareda ==================================================================== */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_lab
 * @brief Número identificador (opção) do ataque "Labareda". */
#define MV_ID_lab 2
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_lab
 * @brief Dano minimo causado pela magia "Labareda". */
#define MV_MIN_dmg_lab 3
/** --------------------------------------------------------------------------------------
 * @def MV_mod_lab
 * @brief Modificador da magia "Labareda".*/
#define MV_mod_lab 3
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_lab
 * @brief Custo em pontos de mana do da magia "Labareda"*/
#define MV_mpc_lab 2
/** --------------------------------------------------------------------------------------
 * @def MV_apc_lab
 * @brief Custo em pontos de movimento da magia da magia "Labareda"*/
#define MV_apc_lab 1
// --------------------------------------------------------------------------------------


/*** ====== Bola de fogo ================================================================ */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_bdf
 * @brief Número identificador (opção) do ataque "". */
#define MV_ID_bdf 3
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_bdf
 * @brief Dano minimo causado pela magia "". */
#define MV_MIN_dmg_bdf 5
/** --------------------------------------------------------------------------------------
 * @def MV_mod_bdf
 * @brief Modificador da magia "".*/
#define MV_mod_bdf 6
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_bdf
 * @brief Custo em pontos de mana do da magia ""*/
#define MV_mpc_bdf 4
/** --------------------------------------------------------------------------------------
 * @def MV_apc_bdf
 * @brief Custo em pontos de movimento da magia da magia ""*/
#define MV_apc_bdf 2
// --------------------------------------------------------------------------------------


/*** ====== Explosão ==================================================================== */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_exp
 * @brief Número identificador (opção) do ataque "Explosão". */
#define MV_ID_exp 4
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_exp
 * @brief Dano minimo causado pela magia "Explosão". */
#define MV_MIN_dmg_exp 10
/** --------------------------------------------------------------------------------------
 * @def MV_mod_exp
 * @brief Modificador da magia "Explosão".*/
#define MV_mod_exp 11
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_exp
 * @brief Custo em pontos de mana do da magia "Explosão"*/
#define MV_mpc_exp 8
/** --------------------------------------------------------------------------------------
 * @def MV_apc_exp
 * @brief Custo em pontos de movimento da magia da magia "Explosão"*/
#define MV_apc_exp 4
// --------------------------------------------------------------------------------------


/*** ====== Plasma ====================================================================== */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_plas
 * @brief Número identificador (opção) do ataque "Plasma". */
#define MV_ID_plas 5
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_plas
 * @brief Dano minimo causado pela magia "Plasma". */
#define MV_MIN_dmg_plas 15
/** --------------------------------------------------------------------------------------
 * @def MV_mod_plas
 * @brief Modificador da magia "Plasma".*/
#define MV_mod_plas 11
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_plas
 * @brief Custo em pontos de mana do da magia "Plasma"*/
#define MV_mpc_plas 8
/** --------------------------------------------------------------------------------------
 * @def MV_apc_plas
 * @brief Custo em pontos de movimento da magia da magia "Plasma"*/
#define MV_apc_plas 4
// --------------------------------------------------------------------------------------


/*** ====== Cura Leve =================================================================== */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_cul
 * @brief Número identificador (opção) do ataque "Cura Leve". */
#define MV_ID_cul 6
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_cul
 * @brief Dano minimo causado pela magia "Cura Leve". */
#define MV_MIN_dmg_cul 4
/** --------------------------------------------------------------------------------------
 * @def MV_mod_cul
 * @brief Modificador da magia "Cura Leve".*/
#define MV_mod_cul 6
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_cul
 * @brief Custo em pontos de mana do da magia "Cura Leve"*/
#define MV_mpc_cul 4
/** --------------------------------------------------------------------------------------
 * @def MV_apc_cul
 * @brief Custo em pontos de movimento da magia da magia "Cura Leve"*/
#define MV_apc_cul 3
// --------------------------------------------------------------------------------------


/*** ====== Negatis ===================================================================== */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_neg
 * @brief Número identificador (opção) da magia "Negatis". */
#define MV_ID_neg 7
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_neg
 * @brief Custo em pontos de mana do da magia "Negatis"*/
#define MV_mpc_neg 8
/** --------------------------------------------------------------------------------------
 * @def MV_apc_neg
 * @brief Custo em pontos de movimento da magia da magia "Negatis"*/
#define MV_apc_neg 3
// --------------------------------------------------------------------------------------


/*** ====== Concentração ================================================================ */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_con
 * @brief Número identificador (opção) do ataque "Concentração". */
#define MV_ID_con 8
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_con
 * @brief Dano minimo causado pela magia "Concentração". */
#define MV_MIN_dmg_con 5
/** --------------------------------------------------------------------------------------
 * @def MV_mod_con
 * @brief Modificador da magia "Concentração".*/
#define MV_mod_con 8
/** --------------------------------------------------------------------------------------
 * @def MV_apc_con
 * @brief Custo em pontos de movimento da magia da magia "Concentração" */
#define MV_apc_con 3
// --------------------------------------------------------------------------------------


/*** === Charge ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MV_ID_pow
 * @brief Número identificador (opção) da magia "convocar circulo superior" */
#define MV_ID_pow 9
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_pow
 * @brief Custo em pontos de mana do da magia "convocar circulo superior"*/
#define MV_mpc_pow 12
/** --------------------------------------------------------------------------------------
 * @def MV_apc_pow
 * @brief Custo em pontos de movimento da magia da magia "convocar circulo superior"*/
#define MV_apc_pow 4
// --------------------------------------------------------------------------------------

/*** ====== Fogo da fenix =============================================================== */
/** --------------------------------------------------------------------------------------
 * @def MV_ID_ff
 * @brief Número identificador (opção) do ataque "Fogo da fenix". */
#define MV_ID_ff 10
/** --------------------------------------------------------------------------------------
 * @def MV_MIN_dmg_ff  
 * @brief Dano minimo instantaneo causado pela magia "Fogo da fenix". */
#define MV_MIN_dmg_ff 10
/** --------------------------------------------------------------------------------------
 * @def MV_mod_ff
 * @brief Modificador de dano instantaneo magia "Fogo da fenix".*/
#define MV_mod_ff 20
/** --------------------------------------------------------------------------------------
 * @def MV_dur_ff
 * @brief Duração do HPmod da magia "Fogo da fenix".*/
#define MV_dur_ff -2
/** --------------------------------------------------------------------------------------
 * @def MV_fdmg_ff
 * @brief Dano do HPmod da magia "Fogo da fenix".*/
#define MV_fdmg_ff -4
/** --------------------------------------------------------------------------------------
 * @def MV_mpc_ff
 * @brief Custo em pontos de mana do da magia "Fogo da fenix"*/
#define MV_mpc_ff 12
/** --------------------------------------------------------------------------------------
 * @def MV_apc_ff
 * @brief Custo em pontos de movimento da magia da magia "Fogo da fenix"*/
#define MV_apc_ff 5
// --------------------------------------------------------------------------------------

int acao_vermelho(int aps, int jogs,int jogatual,vetor jogadores); // Essa função retorna quantos aps foram gastos

#endif
