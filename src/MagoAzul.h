#include "definicoes.h"
#ifndef H_MAGO_AZUL_H
#define H_MAGO_AZUL_H

/** @file MagoAzul.h
 * 
 * @brief Biblioteca de funções, procedimentos e definições referentes a classe "Mago azul."
 * Este arquivo de cabeçalhos contém a função global usada para a execução de uma ação de um Mago azul e as definições de dano, custos de aps e custos de mps das magias dessa classe.
 */
/*** ====== Lança de água =============================================================== */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_lda
 * @brief Número identificador (opção) do ataque "lança de agua". */
#define MA_ID_lda 2
/** --------------------------------------------------------------------------------------
 * @def MA_MIN_dmg_lda
 * @brief Dano minimo causado pelo ataque "lança de agua". */
#define MA_MIN_dmg_lda 3
/** --------------------------------------------------------------------------------------
 * @def MA_mod_lda
 * @brief Modificador do ataque "lança de agua", usado no calculo de dano (Calculo de número aleatório). */
#define MA_mod_lda 2
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_lda
 * @brief Custo em pontos de mana do ataque "lança de agua". */
#define MA_mpc_lda 2
/** --------------------------------------------------------------------------------------
 * @def MA_apc_lda
 * @brief Custo em pontos de movimento do ataque "lança de agua". */
#define MA_apc_lda 1
// --------------------------------------------------------------------------------------


/*** ====== Pedras de gelo ============================================================== */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_pdg
 * @brief Número identificador (opção) do ataque "Pedras de gelo". */
#define MA_ID_pdg 3
/** --------------------------------------------------------------------------------------
 * @def MA_MIN_dmg_pdg
 * @brief Dano mínimo do ataque "Pedras de gelo". */
#define MA_MIN_dmg_pdg 4
/** --------------------------------------------------------------------------------------
 * @def MA_mod_pdg
 * @brief Modificador do ataque "Pedras de gelo", usado no calculo de dano (Número aleatório). */
#define MA_mod_pdg 4
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_pdg
 * @brief Custo em pontos de mana do ataque "Pedras de gelo". */
#define MA_mpc_pdg 3
/** --------------------------------------------------------------------------------------
 * @def MA_apc_pdg
 * @brief Custo em pontos de movimento do ataque "Pedras de gelo". */
#define MA_apc_pdg 2
// --------------------------------------------------------------------------------------


/*** ====== Tempestade de neve ========================================================== */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_temn
 * @brief Número identificador (opção) do ataque "Tempestade de neve". */
#define MA_ID_temn 4
/** --------------------------------------------------------------------------------------
 * @def MA_MIN_dmg_temn
 * @brief Dano mínimo do ataque "Tempestade de neve". */
#define MA_MIN_dmg_temn 4
/** --------------------------------------------------------------------------------------
 * @def MA_mod_temn
 * @brief Modificador do ataque "Tempestade de neve", usado no calculo de dano (Número aleatório) */
#define MA_mod_temn 8
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_temn
 * @brief Custo em pontos de mana do ataque "Tempestade de neve".*/
#define MA_mpc_temn 5
/** --------------------------------------------------------------------------------------
 * @def MA_apc_temn
 * @brief Custo em pontos de movimento do ataque "Tempestade de neve".*/
#define MA_apc_temn 3
// --------------------------------------------------------------------------------------


/*** ====== Zero Absoluto =============================================================== */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_zeroa
 * @brief Número identificador (opção) do ataque "zero absoluto". */
#define MA_ID_zeroa 5
/** --------------------------------------------------------------------------------------
 * @def MA_MIN_dmg_zeroa
 * @brief Dano mínimo do ataque "zero absoluto". */
#define MA_MIN_dmg_zeroa 10
/** --------------------------------------------------------------------------------------
 * @def MA_mod_zeroa
 * @brief Modificador do ataque "Pedras de gelo", usado no calculo de dano (Número aleatório). */
#define MA_mod_zeroa 16
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_zeroa
 * @brief Custo em pontos de mana do ataque "zero absoluto". */
#define MA_mpc_zeroa 6
/** --------------------------------------------------------------------------------------
 * @def MA_apc_zeroa
 * @brief Custo em pontos de movimento do ataque "zero absoluto". */
#define MA_apc_zeroa 5
// --------------------------------------------------------------------------------------


/*** ====== Regeneração ================================================================= */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_regem
 * @brief Número identificador (opção) da magia "regeneração".
 */
#define MA_ID_regem 6
/** --------------------------------------------------------------------------------------
 * @def MA_dmg_regem
 * @brief Efeito causado pela magia "regeneração".
 */
#define MA_dmg_regem 4
/** --------------------------------------------------------------------------------------
 * @def MA_dur_regem
 * @brief Duração da magia "regeneração". */
#define MA_dur_regem 5
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_regem
 * @brief Custo em pontos de mana da magia "regeneração".*/
#define MA_mpc_regem 6
/** --------------------------------------------------------------------------------------
 * @def MA_apc_regem
 * @brief Custo em pontos de movimento da magia "regeneração".*/
#define MA_apc_regem 4
// --------------------------------------------------------------------------------------


/*** ====== Congelar ==================================================================== */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_cong
 * @brief Número identificador (opção) da magia "Congelar". */
#define MA_ID_cong 7
/** --------------------------------------------------------------------------------------
 * @def MA_percent_cong
 * @brief  Chance da magia "Congelar" funcionar */
#define MA_percent_cong 60
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_cong
 * @brief Custo em pontos de mana da magia "Congelar".*/
#define MA_mpc_cong 8
/** --------------------------------------------------------------------------------------
 * @def MA_apc_cong
 * @brief Custo em pontos de movimento da magia "Congelar".*/
#define MA_apc_cong 4
// --------------------------------------------------------------------------------------


/*** ====== Concentração ================================================================ */
/** --------------------------------------------------------------------------------------
 * @def MA_ID_con
 * @brief Número identificador (opção) da habilidade "concentração". */
#define MA_ID_con 8
/** --------------------------------------------------------------------------------------
 * @def MA_MIN_dmg_con
 * @brief  Dano (efeito) mínimo da habilidade "concentração".*/
#define MA_MIN_dmg_con 4
/** --------------------------------------------------------------------------------------
 * @def MA_mod_con
 * @brief Modificador da habilidade "concentração", usado no calculo de dano (Número aleatório). */
#define MA_mod_con 9
/** --------------------------------------------------------------------------------------
 * @def MA_apc_con
 * @brief Custo em pontos de movimento da habilidade "concentração". */
#define MA_apc_con 4
// --------------------------------------------------------------------------------------

/*** === Charge ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MA_ID_pow
 * @brief Número identificador (opção) da magia "convocar circulo superior" */
#define MA_ID_pow 9
/** --------------------------------------------------------------------------------------
 * @def MA_mpc_pow
 * @brief Custo em pontos de mana do da magia "convocar circulo superior"*/
#define MA_mpc_pow 10
/** --------------------------------------------------------------------------------------
 * @def MA_apc_pow
 * @brief Custo em pontos de movimento da magia da magia "convocar circulo superior"*/
#define MA_apc_pow 4

/*** === Córrego da Juventude ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MA_ID_cj
 * @brief Número identificador (opção) da magia "córrego da juventude" */
#define MA_ID_cj 10
/** --------------------------------------------------------------------------------------
 * @def MA_mult_cj
 * @brief Multiplicador de Mana para HP da magia "córrego da juventude"*/
#define MA_mult_cj 2
/** --------------------------------------------------------------------------------------
 * @def MA_apc_cj
 * @brief Custo em pontos de movimento da magia da magia "córrego da juventude"*/
#define MA_apc_cj 4

int acao_azul(int aps, int jogs,int jogatual,vetor jogadores); // Essa função retorna quantos aps foram gastos
#endif
