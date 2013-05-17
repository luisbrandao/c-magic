#include <stdio.h>		// inclui diretivas de entrada-saída
#include <stdlib.h>     // Usa recursos do sistema
#include <stdio_ext.h>  // Precisa para o fpurge
#include <unistd.h>		// Sleep sem syscall

#include "MagoAzul.h"
#include "funcoesA.h"   // Modulos básicos do jogo
#include "funcoesB.h"   // Modulos básicos do jogo
#include "definicoes.h" // Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file MagoAzul.c
 * @brief Biblioteca de procedimentos do mago azul
 * Esta bliblioteca tem como objetivo implementar a classe "mago azul", exibindo na tela o menu de ações possíveis do mago, e tratando a entrada do jogador, decidindo se o movimento é válido ou não.<br>
 * Essa função também cuida dos ataques especiais do mago azul.
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */
//------------------------------------ Protótipos ----------------------------------------
int opcoes_azul(int ap,int atual,int powstat);
void MA_congelar(int jogs, int jogatual, vetor jogadores);
void MA_corrego(int jogatual, vetor jogadores);

/* ----------------------------------------------------------------------------------------*/
/** @brief Ações do mago azul
 * Está é a função que invoca o painel de ações do mago azul, trata a entrada do jogador, chama respectiva função do movimento escolhido e retorna o número de mps gastos na rodada.
 * 
 * @param aps Número de pontos de movimento disponiveis ao jogador
 * @param jogs Número total de jogadores
 * @param jogatual indice do jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int apc_<ação> Caso a entrada do jogador seja válida
 * @return 0 Caso a entrada do jogador seja inválida  */
/* ----------------------------------------------------------------------------------------*/
int acao_azul(int aps, int jogs,int jogatual,vetor jogadores)
{
int acao;
placar (jogs, jogatual, jogadores);
acao = opcoes_azul(aps,jogadores[jogatual].mp,jogadores[jogatual].buffer);

/* Tratador da ação do jagador. Note que, como ao entrar no case o valor da váriavel "acao" deixa de ser importante, ela é reutilizada para servir como a váriavel "alvo" */
switch (acao) 
	{
// ==== Cajado =======================================================================
	case GL_caj:
		{
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, GL_MIN_dmg_caj, GL_mod_caj, 0);
		sleep(t_delay);
		return GL_apc_caj;
		}
// ==== Lança de água  ===============================================================
	case MA_ID_lda: // Lança de água
		{
		if ((jogadores[jogatual].mp < MA_mpc_lda) || (aps < MA_apc_lda))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MA_MIN_dmg_lda, MA_mod_lda, MA_mpc_lda);
		sleep(t_delay);
		return MA_apc_lda; // Custo de aps da magia
		}
// ==== Pedras de gelo ===============================================================
	case MA_ID_pdg: // Pedras de gelo
		{
		if ((jogadores[jogatual].mp < MA_mpc_pdg) || (aps < MA_apc_pdg))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores, MA_MIN_dmg_pdg, MA_mod_pdg, MA_mpc_pdg);
		sleep(t_delay);
		return MA_apc_pdg; // Custo de aps da magia
		}
// ==== Tempestade de gelo ============================================================
	case MA_ID_temn:
		{
		if ((jogadores[jogatual].mp < MA_mpc_temn) || (aps < MA_apc_temn))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao, jogatual, jogadores,MA_MIN_dmg_temn,MA_mod_temn, MA_mpc_temn);
		sleep(t_delay);
		return MA_apc_temn; // Custo de aps da magia
		}
// ==== Zero absoluto =================================================================
	case MA_ID_zeroa:
		{
		if ((jogadores[jogatual].mp < MA_mpc_zeroa) || (aps < MA_apc_zeroa))
			return 0;
		acao = target(jogs,jogatual,jogadores,0);
		GL_base_ataque(acao,jogatual,jogadores,MA_MIN_dmg_zeroa,MA_mod_zeroa,MA_mpc_zeroa);
		sleep(t_delay);
		return MA_apc_zeroa; // Custo de aps da magia
		}
// ==== Regeneração ===================================================================
	case MA_ID_regem:
		{
		if ((jogadores[jogatual].mp < MA_mpc_regem) || (aps < MA_apc_regem))
			return 0;
		acao = target(jogs,jogatual,jogadores,3);
		GL_hp_effect(acao,jogatual,jogadores,MA_dmg_regem,MA_dur_regem, MA_mpc_regem);
		sleep(t_delay);
		return MA_apc_regem; // Custo de aps da magia
		}
// ==== Congelar ======================================================================
	case MA_ID_cong:
		{
		if ((jogadores[jogatual].mp < MA_mpc_cong) || (aps < MA_apc_cong))
			return 0;
		MA_congelar(jogs,jogatual,jogadores);
		sleep(t_delay);
		return MA_apc_cong; // Custo de aps da magia
		}
// ==== Concentração ==================================================================
	case MA_ID_con: 
		{
		if (aps < MA_apc_con)
			return 0;
		GL_concentra(jogatual,jogadores, MA_MIN_dmg_con,MA_mod_con);
		sleep(t_delay);
		return MA_apc_con; // Custo de aps da magia
		}
// ==== Conjurar Magia Superior ========================================================
	case MA_ID_pow:
		{
		if(jogadores[jogatual].mp >= MA_mpc_pow && aps >= MA_apc_pow && !jogadores[jogatual].buffer){
				GL_charge(jogatual,jogadores,MA_mpc_pow);
				return MA_apc_pow;

			}
		break;
		}
// ==== Magia Superior: Córrego da Juventude ==========================================
	case MA_ID_cj:
		{
		if(aps >= MA_apc_cj && jogadores[jogatual].buffer){
				MA_corrego(jogatual,jogadores);
				return MA_apc_cj;

			}
		break;
		}
	}
return 0; // Não foi uma escolha válida então não gasta ap.
}

// --------------------------------------------------------------------------------------
// -------------------------------- Funções internas ------------------------------------
// --------------------------------------------------------------------------------------

/* ----------------------------------------------------------------------------------------*/
/** @brief Painel de ações do mago azul
 * 
 * @param ap Número de pontos de movimento disponiveis ao jogador
 * @param mpAtual Mana atual do jogador
 * @param powstat Status do indicador de magia superior
 *
 * @return int opção digitada pelo jogador */
/* ----------------------------------------------------------------------------------------*/
int opcoes_azul(int ap,int mpAtual,int powstat)
{
int temp;
printf ("Voce ainda tem %d pontos de movimento.\n", ap);
printf ("<%d> para atacar com o seu cajado.\n",GL_caj);
printf ("	1-3 attack, 1 ap, 0 mp\n"); //revisar aqui constantes > variaveis
if (mpAtual >= MA_mpc_lda)
	{
	printf ("===============================================================\n");
	printf ("<%d> para atacar com uma lança de água.\n",MA_ID_lda);
	printf ("	%d-%d attack, %d ap, %d mp\n",MA_MIN_dmg_lda, MA_MIN_dmg_lda+MA_mod_lda-1, MA_apc_lda, MA_mpc_lda);
	}

if ((mpAtual >= MA_mpc_pdg) && (ap >= MA_apc_pdg))
	{
	printf ("===============================================================\n");
	printf ("<%d> para lançar pedras de gelo.\n",MA_ID_pdg);
	printf ("	%d-%d attack, %d ap, %d mp\n", MA_MIN_dmg_pdg, MA_MIN_dmg_pdg+MA_mod_pdg-1, MA_apc_pdg, MA_mpc_pdg);
	}

if ((mpAtual >= MA_mpc_temn) && (ap >= MA_apc_temn))
	{
	printf ("===============================================================\n");
	printf ("<%d> para conjurar uma tempestade de gelo.\n",MA_ID_temn);
	printf ("	%d-%d area attack, %d ap, %d mp\n", MA_MIN_dmg_temn, MA_MIN_dmg_temn+MA_mod_temn-1, MA_apc_temn, MA_mpc_temn);
	}

if ((mpAtual >= MA_mpc_zeroa) && (ap >= MA_apc_zeroa))
	{
	printf ("===============================================================\n");
	printf ("<%d> Para submeter seu inimigo ao zero absoluto\n",MA_ID_zeroa);
	printf ("	%d-%d attack, %d ap, %d mp\n", MA_MIN_dmg_zeroa, MA_MIN_dmg_zeroa+MA_mod_zeroa-1, MA_apc_zeroa, MA_mpc_zeroa);
	}

if ((mpAtual >= MA_mpc_regem) && (ap >= MA_apc_regem))
	{
	printf ("===============================================================\n");
	printf ("<%d> Para conjurar a regeneração.\n",MA_ID_regem);
	printf ("	%d hps restaurados, %d duração, %d ap, %d mp\n", MA_dmg_regem, MA_dur_regem, MA_apc_regem, MA_mpc_regem);
	}

if ((mpAtual >= MA_mpc_cong) && (ap >= MA_apc_cong))
	{
	printf ("===============================================================\n");
	printf ("<%d> Congelar o seu adversário.\n",MA_ID_cong);
	printf ("	Probabilidade: %d%%, %d ap, %d mp\n",MA_percent_cong, MA_apc_cong, MA_mpc_cong);
	}

if (ap >= MA_apc_con)
	{
	printf ("===============================================================\n");
	printf ("<%d> para se concentrar e restaurar parte de seu poder.\n",MA_ID_con);
	printf ("	%d-%d mps recuperados, %d ap\n", MA_MIN_dmg_con, MA_MIN_dmg_con+MA_mod_con-1, MA_apc_con);
	}

if (ap >= MA_apc_pow && mpAtual >= MA_mpc_pow && !powstat)
	{
	printf ("===============================================================\n");
	printf ("<%d> para conjurar círculo de magia superior.\n",MA_ID_pow);
	printf ("	%d ap, %d mp\n", MA_apc_pow, MA_mpc_pow);
	}

if (ap >= MA_apc_cj && powstat)
	{
	printf ("===============================================================\n");
	printf ("<%d> para mergulhar no córrego da juventude.\n",MA_ID_cj);
	printf ("	%d ap, recupera %dx do mp em HP, drenando todo mp\n", MA_apc_cj, MA_mult_cj);
	}

printf ("Ação: ");
scanf ("%d", &temp);
__fpurge(stdin);
return(temp);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Ataque especial: Congelar
 * Esse é o ataque especial do mago azul. A função seta o status "congelado" caso haja um sucesso no ataque. A taxa de sucesso é definida pela porcentagem MA_percent_cong
 * 
 * @param jogs Número total de jogadores
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void MA_congelar(int jogs, int jogatual, vetor jogadores)
{
int alvo,dmg, trava, esp, paral;
alvo = target(jogs,jogatual,jogadores,0);

// decompoe o especial de ap
esp = jogadores[jogatual].apmod.esp;
trava = esp % 10; esp = esp / 10;
paral = esp % 10;
	
dmg = rand()%(100); dmg ++;
if (dmg < MA_percent_cong)
	{
	// Se já não está paralizado, então paraliza.
	if (paral == 1)
		jogadores[jogatual].apmod.esp += 10;
	printf ("%s está congelado!\n", jogadores[alvo].nome);
	sleep(t_delay);
	}
else
	{
	printf ("Falha!\n");
	sleep(t_delay);
	}
jogadores[jogatual].mp -= MA_mpc_cong;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Magia superior: Córrego da Juventude
 * Essa é a magia superior de nível 1 do mago azul, que recupera 2x o mp atual em hp, e drena todo o mp
 * 
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/

void MA_corrego(int jogatual, vetor jogadores){
	printf("%d mp drenado, %d HP recuperado\n", jogadores[jogatual].mp, jogadores[jogatual].mp*MA_mult_cj);
	jogadores[jogatual].hp += jogadores[jogatual].mp*MA_mult_cj;
	jogadores[jogatual].mp = 0;
	sleep(t_delay);
}
