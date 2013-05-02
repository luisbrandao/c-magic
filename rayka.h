#include "definicoes.h"
#ifndef H_AI_RAYKA_H
#define H_AI_RAYKA_H
/* ======================================================================================== */
/**
 * @file rayka.h
 * @brief Cabeçalhos da biblioteca da Maga vermelha: Rayka <br>
 * <b>Jogador artificial.</b><br>
 * <br>
 * v 0.1 » 13/11/2009 » Inicio. Rayka ataca com cajado o inimigo mais fraco.<br>
 * v 0.2 » 14/11/2009 » Rayka usa aleatoriamente cajado, labareda, bola de fogo ou explosão.<br>
 * v 1.0 » 13/05/2009 » Rayka não trapacea mais, usa funções globais de ataque, se cura e neutraliza seus stats quando nescessario, e escolhe suas ações baseando-se em dois modos de ataque.<br>
 * v 1.1 » 17/05/2009 » Ponto em que Rayka começa a usar cura agora é um define.<br>
 * v 1.2 » 18/05/2009 » Se no modo defensivo não acontece nada, agora Rayka realmente entra em modo agressivo.<br>
 * v 1.3 » 25/05/2009 » Adequação as novas bibliotecas genéricas.<br>
 *
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

/**  --------------------------------------------------------------------------------------
 * @def RAYKA_ver
 * @brief String com a versão atual da AI */
#define RAYKA_ver "1.3"
/**  --------------------------------------------------------------------------------------
 * @def RAYKA_date
 * @brief String com a data de lançamento da versão atual da AI */
#define RAYKA_date "25/05/2010"
/**  --------------------------------------------------------------------------------------
 * @def RaykaMinHP
 * @brief Definição de quando Rayka se considera fraca e começa a usar cura */
#define RaykaMinHP 35
//   --------------------------------------------------------------------------------------


int acao_rayka(int vivos, int aps, int jogs,int jogatual,vetor jogadores);

#endif
