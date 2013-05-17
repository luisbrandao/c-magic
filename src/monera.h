#ifndef H_AI_MONERA_H
#define H_AI_MONERA_H
#include "definicoes.h"
/* ======================================================================================== */

/**
 * @file monera.h
 * @brief Mago verde: Monera <br>
 * V 0.1 » 16/11/2009 » Inicio. Monera usa movimentos de acordo com uma sequencia de prioridades
 * do seguinte modo: se a condição for cumprida e for possivel usar o movimento, usa-se o movimento
 * caso contrario vai para o proximo if<br>
 * <br>
 * V 0.2 » 15/12/2009 » Refinamento do código. Código usa funções globais genéricas criadas para
 * propósitos de ataque em área e ataque com cajado. Remoção de parâmetros desnecessários em 
 * funções existentes e remoção de funções que podiam ser substituidas por genéricas. <br>
 * <br>
 * V 0.3 » 15/12/2009 » Refinamento do código. Utilização total de funções genéricas, e parei de reclamar do Luis na documentação. <br>
 * @author Fabricio Schiavon Kolberg
 */
/* ======================================================================================== */

// Solução temporaria pro código copilar.

/** --------------------------------------------------------------------------------------
 * @def monera_FOLHA
 * @brief Índice de TEMPESTADE DE FOLHAS no vetor auxiliar do Monera */
#define monera_FOLHA 1
/** --------------------------------------------------------------------------------------
 * @def monera_ESPOROS
 * @brief Índice de ESPOROS CORROSIVOS no vetor auxiliar do Monera */
#define monera_ESPOROS 2
/** --------------------------------------------------------------------------------------
 * @def monera_VENENO
 * @brief Índice de VENENO no vetor auxiliar do Monera */
#define monera_VENENO 3
/** --------------------------------------------------------------------------------------
 * @def monera_HPDRAIN
 * @brief Índice de HP DRAIN no vetor auxiliar do Monera */
#define monera_HPDRAIN 4
/** --------------------------------------------------------------------------------------
 * @def monera_ENROLAR
 * @brief Índice de ENROLAR no vetor auxiliar do Monera */
#define monera_ENROLAR 5
/** --------------------------------------------------------------------------------------
 * @def monera_MPDRAIN
 * @brief Índice de MP DRAIN no vetor auxiliar do Monera */
#define monera_MPDRAIN 6
/** --------------------------------------------------------------------------------------
 * @def MONERA_ver
 * @brief Número da última versão no código do AI Monera */
#define MONERA_ver "0.3"
/** --------------------------------------------------------------------------------------
 * @def MONERA_date
 * @brief Data da última modificação do código do AI Monera */
#define MONERA_date "28/05/2010"
// --------------------------------------------------------------------------------------

int acao_monera(int vivos, int aps, int jogs,int jogatual,vetor jogadores);

#endif 
