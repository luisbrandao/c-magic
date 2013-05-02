#include "definicoes.h"
#ifndef H_MAGO_VERDE_H
#define H_MAGO_VERDE_H

/** @file MagoVerde.h
 * 
 * @brief Cabeçalhos e definições da biblioteca "Mago verde"
 Biblioteca de funções, procedimentos e definições referentes a classe "Mago verde."<br>
 * Este arquivo de cabeçalhos contém a função global usada para a execução de uma ação de um Mago verde e as definições de dano, custos de aps e custos de mps das magias dessa classe.
 */

/*** === Tempestade de folhas ======================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_tdf
 * @brief Número identificador (opção) da magia "Tempestade de folhas" */
#define MG_ID_tdf 2
/** --------------------------------------------------------------------------------------
 * @def MG_MIN_dmg_tdf
 * @brief Dano minimo causado pela magia "Tempestade de folhas". */
#define MG_MIN_dmg_tdf 1
/** --------------------------------------------------------------------------------------
 * @def MG_mod_tdf
 * @brief Modificador da magia "Tempestade de folhas".*/
#define MG_mod_tdf 4
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_tdf
 * @brief Custo em pontos de mana da magia "Tempestade de folhas". */
#define MG_mpc_tdf 3
/** --------------------------------------------------------------------------------------
 * @def MG_apc_tdf
 * @brief Custo em pontos de movimento da magia "Tempestade de folhas". */
#define MG_apc_tdf 2
// --------------------------------------------------------------------------------------


/*** === Esporos corrosivos ========================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_ec
 * @brief Número identificador (opção) da magia "Esporos corrosivos". */
#define MG_ID_ec 3
/** --------------------------------------------------------------------------------------
 * @def MG_dmg_ec
 * @brief Dano inflgido por turno pelo ataque "Esporos corrosivos". */
#define MG_dmg_ec -3
/** --------------------------------------------------------------------------------------
 * @def MG_dur_ec
 * @brief Duração que a magia "Esporos corrosivos" irá continuar fazendo efeito. */
#define MG_dur_ec -2
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_ec
 * @brief Custo em pontos de mana da magia "Esporos corrosivos". */
#define MG_mpc_ec 4
/** --------------------------------------------------------------------------------------
 * @def MG_apc_pow
 * @brief Custo em pontos de movimento da magia "Esporos corrosivos". */
#define MG_apc_ec 3
// --------------------------------------------------------------------------------------


/*** === Veneno ====================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_ven
 * @brief Número identificador (opção) da magia "veneno". */
#define MG_ID_ven 4
/** --------------------------------------------------------------------------------------
 * @def MG_dmg_ven
 * @brief  Dano inflgido por turno pela magia "veneno". */
#define MG_dmg_ven -4
/** --------------------------------------------------------------------------------------
 * @def MG_dur_ven
 * @brief Duração que a magia "veneno" irá continuar fazendo efeito.. */
#define MG_dur_ven -5
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_ven
 * @brief Custo em pontos de mana da magia "veneno". */
#define MG_mpc_ven 6
/** --------------------------------------------------------------------------------------
 * @def MG_apc_ven
 * @brief Custo em pontos de movimento da magia "veneno". */
#define MG_apc_ven 4
// --------------------------------------------------------------------------------------


/*** === Drenar hp =================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_hpd
 * @brief Número identificador (opção) da magia "Drenar hp". */
#define MG_ID_hpd 5
/** --------------------------------------------------------------------------------------
 * @def MG_MIN_dmg_hpd
 * @brief Dano minimo causado pelo ataque "Drenar hp". */
#define MG_MIN_dmg_hpd 5
/** --------------------------------------------------------------------------------------
 * @def MG_mod_hpd
 * @brief Modificador do ataque "Drenar hp". */
#define MG_mod_hpd 6
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_hpd
 * @brief Custo em pontos de mana da magia "Drenar hp". */
#define MG_mpc_hpd 5
/** --------------------------------------------------------------------------------------
 * @def MG_apc_hpd
 * @brief Custo em pontos de movimento da magia "Drenar hp". */
#define MG_apc_hpd 4
// --------------------------------------------------------------------------------------


/*** === Enrolar ===================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_enrol
 * @brief Número identificador (opção) da magia "convocar circulo superior". */
#define MG_ID_enrol 6
/** --------------------------------------------------------------------------------------
 * @def MG_dmg_enrol
 * @brief Penalidade em potos de AP que a magia "Enrolar" inflinge. */
#define MG_dmg_enrol -2
/** --------------------------------------------------------------------------------------
 * @def MG_dur_enrol
 * @brief Duração por uso da magia "Enrolar". */
#define MG_dur_enrol -3
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_enrol
 * @brief Custo em pontos de mana da magia "Enrolar". */
#define MG_mpc_enrol 6
/** --------------------------------------------------------------------------------------
 * @def MG_apc_enrol
 * @brief Custo em pontos de movimento da magia "Enrolar". */
#define MG_apc_enrol 4
// --------------------------------------------------------------------------------------


/*** === Drenar MP =================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_pow
 * @brief Número identificador (opção) da magia "Drenar MP". */
#define MG_ID_mpd 7
/** --------------------------------------------------------------------------------------
 * @def MG_MIN_dmg_mpd
 * @brief Dano minimo causado pelo ataque "Drenar MP". */
#define MG_MIN_dmg_mpd 3
/** --------------------------------------------------------------------------------------
 * @def MG_mod_mpd
 * @brief Modificador do ataque "Drenar MP". */
#define MG_mod_mpd 9
/** --------------------------------------------------------------------------------------
 * @def MG_apc_pow
 * @brief Custo em pontos de movimento do ataque Drenar MP. */
#define MG_apc_mpd 3
// --------------------------------------------------------------------------------------


/*** === Convocar círculo superior =================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_pow
 * @brief Número identificador (opção) da magia "convocar circulo superior" */
#define MG_ID_pow 8
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_pow
 * @brief Custo em pontos de mana do da magia "convocar circulo superior"*/
#define MG_mpc_pow 10
/** --------------------------------------------------------------------------------------
 * @def MG_apc_pow
 * @brief Custo em pontos de movimento da magia da magia "convocar circulo superior"*/
#define MG_apc_pow 4
// --------------------------------------------------------------------------------------]


/*** === Mana Void =================================================================*/
/**  --------------------------------------------------------------------------------------
 * @def MG_ID_mv
 * @brief Número identificador (opção) da magia "". */
#define MG_ID_mv 9
/** --------------------------------------------------------------------------------------
 * @def MG_MIN_dmg_mv
 * @brief Dano minimo causado pelo ataque "". */
#define MG_MIN_dmg_mv 3
/** --------------------------------------------------------------------------------------
 * @def MG_mod_mv
 * @brief Modificador do ataque "Drenar MP". */
#define MG_mod_mv 9
/** --------------------------------------------------------------------------------------
 * @def MG_mpc_mv
 * @brief Custo em pontos de mana do da magia "convocar circulo superior"*/
#define MG_mpc_mv 0 
/** --------------------------------------------------------------------------------------
 * @def MG_apc_mv
 * @brief Custo em pontos de movimento do ataque Drenar MP. */
#define MG_apc_mv 3
// --------------------------------------------------------------------------------------


int acao_verde(int aps, int jogs,int jogatual,vetor jogadores); // Essa função retorna quantos aps foram gastos

#endif
