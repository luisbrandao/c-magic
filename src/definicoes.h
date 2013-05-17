#ifndef H_DEFINICOES_H
#define H_DEFINICOES_H

/** @file definicoes.h
 * 
 * @brief definições principais do programa
 * Esse arquivo de cabeçalho implementa todas as definições globais, como o limite máximo e minimo de hp, o máximo de jogadores, o ID de cada classe e ai, o chão e o teto de apmod e hpmod e as estructs das fichas.
 */

/*** === Ataque: cajado =================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def GL_caj
 * @brief ID do ataque "cajadada" */
#define GL_caj 1
/** --------------------------------------------------------------------------------------
 * @def GL_MIN_dmg_caj
 * @brief Dano minimo causado pelo ataque "lança de agua". */
#define GL_MIN_dmg_caj 1
/** --------------------------------------------------------------------------------------
 * @def GL_mod_caj
 * @brief Modificador do ataque "lança de agua", usado no calculo de dano (Calculo de número aleatório). */
#define GL_mod_caj 3
/** --------------------------------------------------------------------------------------
 * @def GL_apc_caj
 * @brief Custo em pontos de movimento do ataque "lança de agua". */
#define GL_apc_caj 1
// --------------------------------------------------------------------------------------

/*** === Limites de jogo ================================================================== */
/**  --------------------------------------------------------------------------------------
 * @def GL_int_ap
 * @brief Número inicial de aps */
#define GL_int_ap 6
/**  --------------------------------------------------------------------------------------
 * @def minHP
 * @brief Limite inferior do hp inicial */
#define minHP 50
/**  --------------------------------------------------------------------------------------
 * @def maxHP
 * @brief Limite superior para o hp inicial */
#define maxHP 250
/**  --------------------------------------------------------------------------------------
 * @def maxJOGS
 * @brief Limite rigido do número máximo de jogadores */
#define maxJOGS 5		// Limite de jogadores

/*** === Definições de classes ============================================================ */
/**  --------------------------------------------------------------------------------------
 * @def M_azul
 * @brief Número identificador da classe "Mago Azul" */
#define M_azul 1
/**  --------------------------------------------------------------------------------------
 * @def M_branco
 * @brief Número identificador da classe "Mago Branco" */
#define M_branco 2
/**  --------------------------------------------------------------------------------------
 * @def M_verde
 * @brief Número identificador da classe "Mago verde" */
#define M_verde 3
/**  --------------------------------------------------------------------------------------
 * @def M_vermelho
 * @brief Número identificador da classe "Mago Vermelho" */
#define M_vermelho 4
/**  --------------------------------------------------------------------------------------
 * @def M_negro
 * @brief Número identificador da classe "Mago Negro" */
#define M_negro 5
/**  --------------------------------------------------------------------------------------
 * @def AI_rayka
 * @brief Número identificador do jogador do computador "Rayka" */
#define AI_rayka 6
/**  --------------------------------------------------------------------------------------
 * @def AI_monera
 * @brief Número identificador do jogador do computador "monera" */
#define AI_monera 7
/**  --------------------------------------------------------------------------------------
 * @def t_delay
 * @brief Tempo de delay padrão entre as mensagens */
#define t_delay 1


/*** === Condições especiais ============================================================== */
/**  --------------------------------------------------------------------------------------
 * @def GBL_hp_loss
 * @brief Dano máximo por turno do veneno */
#define GBL_hp_loss -10
/**  --------------------------------------------------------------------------------------
 * @def GBL_hp_loss_dur
 * @brief Duração máxima do veneno */
#define GBL_hp_loss_dur	-8
/**  --------------------------------------------------------------------------------------
 * @def GBL_hp_gain
 * @brief Regeneração máxima */
#define GBL_hp_gain 10
/**  --------------------------------------------------------------------------------------
 * @def GBL_hp_gain_dur
 * @brief Duração máxima da regeneração */
#define GBL_hp_gain_dur 8
/**  --------------------------------------------------------------------------------------
 * @def GBL_ap_loss
 * @brief Perda máxima de pontos de movimento */
#define GBL_ap_loss -4
/**  --------------------------------------------------------------------------------------
 * @def GBL_ap_loss_dur
 * @brief Duração máxima da lentidão */
#define GBL_ap_loss_dur	-8
/**  --------------------------------------------------------------------------------------
 * @def GBL_ap_gain
 * @brief Numero máximo pontos de movimento extras */
#define GBL_ap_gain 9
/**  --------------------------------------------------------------------------------------
 * @def GBL_ap_gain_dur
 * @brief Duração máxima dos pontos de movimento extras */
#define GBL_ap_gain_dur 12



/*** === Structs ========================================================================== */
/**  --------------------------------------------------------------------------------------
 * @struct <cond>
 * @brief Indicadores de condição
 * 
 * Esse par de indicadores registram o efeito de determinada condição e quanto tempo esse efeito perdurará:
 - mod:	Dano/Bonus sobre a condição
 - dur:	Tempo que a condição ainda persistirá
 - esp: condiçoes especiais */
typedef struct
{
	int mod; /*!< Força do efeito */
	int dur; /*!< Duração do efeito */
	int esp; /*!< Condições especiais */
} cond;


/**  --------------------------------------------------------------------------------------
 * @struct <ficha>
 * @brief Dados de um jogador
 * 
 * Essa é a estrutura que controla as condições de um jogador:
 - Nome: String com o nome do jogador
 - hp: Número de pontos de vida do jogador
 - mp: Número de "mana points" do jogador
 - place: Número de ordem do jogador
 - classe: Número que indica qual a classe (ou qual AI) o jogador pertence / é controlado
 - buffer: Indica se o jogador está com a magia intermediaria pronta (carregada)
 - paraliz: Indicador de paralizia normal
 - apmod: Indicador de velocidade alterada (rapidez ou lentidão)
 	condições especiais:
 	1 = trava ligada
 	10 = paralizado
 - hpmod: Indicador de pontos de vida alterada (veneno ou regeneração)
  	condições especiais:
 	1 = trava ligada
 - ptr: Ponteiro para nada. Desenhado para o uso em AIs */
typedef struct
{
	char nome[10]; /*!< String com o nome do jogador */
	int hp; /*!< Número de pontos de vida do jogador */
	int mp; /*!< Número de "mana points" do jogador */
	int place; /*!< Número de ordem do jogador */
	int classe; /*!< Número que indica qual a classe (ou qual AI) o jogador pertence / é controlado */
	int buffer; /*!< Indica se o jogador está com a magia intermediaria pronta (carregada) */
	cond apmod; /*!< Indicador de velocidade alterada (rapidez ou lentidão) */
	cond hpmod; /*!< Indicador de pontos de vida alterada (veneno ou regeneração) */
	void *ptr; /*!< Ponteiro para nada. Desenhado para o uso em AIs */
} ficha;


/**  --------------------------------------------------------------------------------------
 * @typedef vetor
 * @brief Cria um vetor de fichas */
typedef ficha vetor[maxJOGS];

#endif
