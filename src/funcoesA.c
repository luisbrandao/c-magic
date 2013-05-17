#include <stdio.h>	// inclui diretivas de entrada-saída
#include <math.h>	// inclui diretivas das funções matemáticas
#include <stdlib.h>     // Usa recursos do sistema
#include <time.h>	// Permite o uso do tempo do sistema 
#include <string.h>     // Bibliotecas de comandos com strings
#include <stdio_ext.h>  // Precisa para o fpurge
#include <unistd.h>	// Sleep sem syscall

#include "monera.h"	//Constantes do Monera
#include "rayka.h"	//Constantes da rayka
#include "funcoesA.h"	   	// Modulos básicos do jogo
#include "definicoes.h" // Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file funcoesA.c
 * @brief Biblioteca de funções genéricas.
 * Esta biblioteca abriga as funções relacionadas a manipulação das fichas de jogador (limpeza, criação) e tratamento de condições especiais pré-movimento (apmod e hpmod)

 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

/* ----------------------------------------------------------------------------------------*/
/** @brief Procedimento para limpar as fichas
 *
 * Este procedimento recebe como parametro o vetor de fichas e as limpa, atribuindo-lhes valores nulos ou pre-determinados (como o numero de ordem.)
 *
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void lipatudo (vetor jogadores)
{
int i,j;
for (i = 0; i < maxJOGS; i++)
	{
	for (j = 0; j < 10 ; j++)
		jogadores[i].nome[j] = 0; // zera toda a string do nome
	jogadores[i].hp = -1;
	jogadores[i].mp = -1;
	jogadores[i].place = i+1;
	jogadores[i].buffer = 0;
	jogadores[i].apmod.mod = 0;
	jogadores[i].apmod.dur = 0;
	jogadores[i].apmod.esp = 0;
	jogadores[i].hpmod.mod = 0;
	jogadores[i].hpmod.dur = 0;
	jogadores[i].hpmod.esp = 0;
	}
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Procedimento para mostrar o placar
 *
 *
 * Este procedimento recebe como parametro o vetor de fichas, o número de pessoas que estão jogando e o jogador atual. Com essas informações, o procedimento mostra o placar para esse jogador, indicando as classes dos jogadores seus respectivos nomes, hps, mps e condições especiais.
 *
 * @param jogs Número de pessoas que estão jogando
 * @param atual Numero do jogador atual (indice no vetor)
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void placar (int jogs, int atual, vetor jogadores)
{
int i, espHP, travaHP, espAP, travaAP,paral;
printf ("============================================================================\n");
printf ("Jogador atual: %s.\n", jogadores[atual].nome);
for (i = 0; i < jogs; i++)
	if (jogadores[i].hp > 0)
		{
		printf ("%d: ",jogadores[i].place);
			switch (jogadores[i].classe)
				{
				case M_azul: printf ("MA: ");
				break;
				case M_branco: printf ("MB: ");
				break;
				case M_verde: printf ("MG: ");
				break;
				case M_vermelho: printf ("MV: ");
				break;
				case M_negro: printf ("MN: ");
				break;
				case AI_rayka: printf ("MV: ");
				break;
				case AI_monera: printf ("MG: ");
				break;
				}
				
	// decompoe o especial de AP
		espAP = jogadores[i].apmod.esp;
		travaAP = espAP % 10; espAP = espAP / 10;
		paral = espAP % 10; espAP = espAP / 10;
				
	// decompoe o especial de HP
		espAP = jogadores[i].apmod.esp;
		travaHP = espHP % 10; espHP = espHP / 10;
				
		printf ("%s: \t%d hp,\t %d mp|",jogadores[i].nome, jogadores[i].hp, jogadores[i].mp);
	// Mostra condições
		if (jogadores[i].buffer == 1)
			printf (" *");
		if (jogadores[i].buffer == 2)
			printf (" **");
		if (paral == 1)
			printf ("  Par|");
		if (jogadores[i].hpmod.dur != 0)
			printf (" Hp Dur %d| Hp dmg %d|",jogadores[i].hpmod.dur,jogadores[i].hpmod.mod);
		if (jogadores[i].apmod.dur != 0)
			printf (" Aps Dur %d| Aps dmg %d\n",jogadores[i].apmod.dur,jogadores[i].apmod.mod);
		else
			printf ("\n");
		}			
	else
		printf ("%d: %s: Morto.\n",jogadores[i].place,jogadores[i].nome);
printf ("============================================================================\n");
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função para determinar quantas pessoas ainda estão no jogo
 *
 * Está função recebe o vetor de fichas e o número de pessoas que estão jogando e retorna o número de jogadores que não estão mortos (o hp é maior que 0)
 *
 * @param jogs Número de pessoas que estão jogando
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int Número de jogadores que ainda estão vivos */
/* ----------------------------------------------------------------------------------------*/int conta_vivos(vetor jogadores,int jogs)
{
int i,vivos = 0;
for (i = 0; i <= jogs; i++)
	{
	if (jogadores[i].hp > 0)
		vivos++;
	}
return (vivos);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Procedimento para se criar jogadores
 *
 * Está função recebe um vetor de fichas limpo (iniciados pelo limpatudo()) e pergunta ao usuário quantas pessoas irão jogar, quanto de hp cada um irá começar, e qual é o nome de cada jogador. Também é aqui que uma AI pode ser escolhida (digitando seu respectivo nome em minusculas e sua classe)
 *
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return int Número de pessoas que criam fichas. */
/* ----------------------------------------------------------------------------------------*/int cold_start(vetor jogadores)
{
int jogs,temp,i,j;
// Pergunta quantas pessoas vão jogar
do
	{
	printf ("Quantas pessoas vão jogar? (2 a %d) ", maxJOGS);
	scanf ("%d", &jogs);
	__fpurge(stdin);
	}
while  ((jogs < 2) || (jogs > maxJOGS));

// Pergunta qual vai ser o hp usado no jogo
do
	{
	printf ("Quanto de hp? (%d < x < %d) ",minHP ,maxHP);
	scanf ("%d", &temp);
	__fpurge(stdin);
	}
while  ((temp < minHP) || (temp > maxHP));

// Prepara os jogadores
for (i = 0; i < jogs; i++)
	{
	// Lê o nome do jogador
	printf ("Diga o nome do jogador %d: ",i+1);
	fgets (jogadores[i].nome, 10, stdin);
	__fpurge(stdin);

	// Seleciona a classe do personagem
	printf ("Diga a classe do jogador:\n");
	printf ("1- Mago azul (Água)\n");
	printf ("2- Mago branco (Vento)\n");
	printf ("3- Mago verde (Vida)\n");
	printf ("4- Mago vermelho (Fogo)\n");
	do
		{
		printf (">> ");
		scanf ("%d", &jogadores[i].classe);
		__fpurge(stdin);
		}
	while(((jogadores[i].classe < 1) || (jogadores[i].classe > 4)) && !(jogadores[i].classe == 11));
	// do (...) while sempre funciona ao contrario!


	// Cond pra mago negro	
	if (jogadores[i].classe == 11)
		{
		jogadores[i].classe=M_negro;
		}
	// Cond para a AI rayka
	if ((strcmp (jogadores[i].nome, "rayka\n") == 0 ) && (jogadores[i].classe == M_vermelho))
		{
		strcpy(jogadores[i].nome, "Rayka\n");
		jogadores[i].classe=AI_rayka;
		printf (" Usando:\nRayka %s\n%s\n",RAYKA_ver,RAYKA_date);
		sleep(t_delay);
		}

	// Cond para a AI monera
	if ((strcmp (jogadores[i].nome, "monera\n") == 0 ) && (jogadores[i].classe == M_verde))
		{
		strcpy(jogadores[i].nome, "Monera\n");
		jogadores[i].classe=AI_monera;
		printf (" Usando:\nMonera %s\n%s\n",MONERA_ver,MONERA_date);
		sleep(t_delay);
		}

	// Troca a quebra de linha por /0
	for (j = 0; j < 10; j++)
		if (jogadores[i].nome[j] == '\n')
			jogadores[i].nome[j] = '\0';

	// Inicializa o hp e o mp
	jogadores[i].mp = temp / 2;
	jogadores[i].hp = temp;
	system("clear");
	}
return jogs;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief trata_condicoes
 * Essa função trata das condições especiais de cada jogador, como regeneração e veneno.
 * 
 * @param *aps Ponteiro para a variavel que guarda os pontos de movimento
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void trata_condicoes(int *aps,int jogatual,vetor jogadores)
{
int trava, esp, paral;
// ------------------------ Modificação de aps -------------------------
// decompoe o especial de ap
esp = jogadores[jogatual].apmod.esp;
trava = esp % 10; esp = esp / 10;
paral = esp % 10;

// se tem trava de ap, tira
if (trava == 1)
	jogadores[jogatual].apmod.esp -= 1;

// Se o jogador atual está enrolado ou veloz, mudar seus aps.
if (jogadores[jogatual].apmod.dur != 0)
	{
	*aps += jogadores[jogatual].apmod.mod;
	decrementa_apdur;
	// Se o jogador está ganhando mais que 2 pontos de ap por rodada, degrada o efeito
	if (jogadores[jogatual].apmod.mod > 2)
		{
		// Se a duração for par, degrada efeito
		if ((jogadores[jogatual].apmod.dur % 2) == 1)
			jogadores[jogatual].apmod.mod --;
		}

	// Se o jogador está perdendo mais que 2 pontos de ap por rodada, degrada o efeito
	if	(jogadores[jogatual].apmod.mod < -2)
		{
		// Se a duração for par, degrada efeito
		if ((jogadores[jogatual].apmod.dur % 2) == -1)
			jogadores[jogatual].apmod.mod ++; // degrada efeito
		}
	}

// ---------------------------- Paralizado ----------------------------
// Se o jogador atual está paralizado, desparaliza e pula para o próximo.
if (paral == 1)
	{
	jogadores[jogatual].apmod.esp -= 10;
	*aps = 0;
	}

// ----------------------- Modificação de hp ---------------------------
// decompoe o especial de hp
esp = jogadores[jogatual].hpmod.esp;
trava = esp % 10;
// Se tem trava, a retira
if (trava == 1)
	jogadores[jogatual].hpmod.esp -= 1;

// Se o jogador atual está coberto por ácido ou se regenerando, mudar o hp dele.
if (jogadores[jogatual].hpmod.dur != 0)
	{
	jogadores[jogatual].hp += jogadores[jogatual].hpmod.mod;
	decrementa_hpdur;

	// Se o jogador está ganhando mais que 3 pontos de hp por rodada, degrada o efeito
	if (jogadores[jogatual].hpmod.mod > 3)
		{
		// Se a duração for par, degrada efeito
		if ((jogadores[jogatual].hpmod.dur % 2) == 1)
			jogadores[jogatual].hpmod.mod --;		
		}

	// Se o jogador está perdendo mais que 3 pontos de hp por rodada, degrada o efeito
	if (jogadores[jogatual].hpmod.mod < -3)
		{
		// Se a duração for par, degrada efeito
		if ((jogadores[jogatual].hpmod.dur % 2) == -1)
			jogadores[jogatual].hpmod.mod ++; // Degrada efeito
		}
	}
// -------------------------- Reseta efeito --------------------------
	if (jogadores[jogatual].hpmod.dur == 0)
		jogadores[jogatual].hpmod.mod = 0; // zera efeito
	if (jogadores[jogatual].apmod.dur == 0)
		jogadores[jogatual].apmod.mod = 0; // zera efeito
}
