#include <stdio.h>	// inclui diretivas de entrada-saída
#include <math.h>	// inclui diretivas das funções matemáticas
#include <stdlib.h>     // Usa recursos do sistema
#include <time.h>	// Permite o uso do tempo do sistema 
#include <string.h>     // Bibliotecas de comandos com strings
#include <stdio_ext.h>  // Precisa para o fpurge
#include <unistd.h>	// Sleep sem syscall

#include "funcoesA.h"   // Modulos básicos do jogo
#include "definicoes.h" // Constantes e structs usados no jogo

/* ======================================================================================== */
/**
 * @file funcoesB.c
 * @brief Biblioteca de funções de combate genéricas.
 * Esta biblioteca cuida das funções básicas de combate, como a escolha de alvo, ataques genericos e a manipulação de ataques que criam condições especiais.
 * @author Luis Alexandre D. Brandao
 */
/* ======================================================================================== */

/* ----------------------------------------------------------------------------------------*/
/** @brief Target:
 * Esse função escolhe automaticamente um alvo e rotorna o seu número
 
 * @param jogs Número total de jogadores
 * @param jogatual Jogador atual
 * @param jogadores com as fichas dos jogadores
 * @param spec Modifica o funcionamento da função.<br>
 	<b>0:</b> Se só tem 2 vivos, ataca o outro. Caso contrario, pede alvo.<br>
 	<b>1:</b> Se só tem 2 jogadores, ataca o outro. Caso contrario, pede alvo.<br>
 	<b>2:</b> Se só tem 2 vivos, ataca a si mesmo. Caso contrario, pede alvo.<br>
 	<b>3:</b> Se só tem 2 jogadores, ataca a si mesmo. Caso contrario, pede alvo.<br>
	<b>4:</b> Pede por um alvo em qualquer circunstancia<br>
 *
 * @return int O ID do outro jogador */
/* ----------------------------------------------------------------------------------------*/
int target(int jogs, int jogatual, vetor jogadores, int spec)
{
int alvo,i, vivos;
vivos = conta_vivos(jogadores,jogs);

switch (spec)
{
//==== Se só tem 2 vivos, ataca o outro. Caso contrario, pede alvo.
	case 0:
	{
	if (vivos == 2)
		{ /* Caso só haja dois vivos, ataca o outro */
		for (i = 0; i <= jogs; i++)
			if ((jogadores[i].hp > 0) && (i != jogatual))
				return (i);
		}
	else
		{ /* Caso contrario pede um alvo */
		do
			{
			printf ("Diga o alvo: ");
			scanf ("%d",&alvo);
			__fpurge(stdin);
			alvo--;
			}
		while ((alvo < 0) || (alvo > jogs));
		//alvo-- ; Na realidade o jogador 1 é o jogador 0, etc.
		return (alvo);
		}
	}
//==== Se só tem 2 jogadores, ataca o outro. Caso contrario, pede alvo.
	case 1:
	{ /*Sempre pede por um alvo, a não ser que o jogo todo só tenha 2 pessoas*/
	if (jogs == 2)
		{ /* Caso só haja dois vivos, ataca o outro */
		for (i = 0; i <= jogs; i++)
			if ((jogadores[i].hp > 0) && (i != jogatual))
				return (i);
		}
	else
		{
		do
			{
			printf ("Diga o alvo: ");
			scanf ("%d",&alvo);
			__fpurge(stdin);
			alvo--;
			}
		while ((alvo < 0) || (alvo > jogs));
		//alvo-- ; Na realidade o jogador 1 é o jogador 0, etc.
		return (alvo);
		}
	}
//==== Se só tem 2 vivos, ataca a si mesmo. Caso contrario, pede alvo.
	case 2:
	{
	if (vivos == 2)
		{ /* Caso só haja dois vivos, ataca você mesmo */
		return (jogatual);
		}
	else
		{ /* Caso contrario pede um alvo */
		do
			{
			printf ("Diga o alvo: ");
			scanf ("%d",&alvo);
			__fpurge(stdin);
			alvo--;
			}
		while ((alvo < 0) || (alvo > jogs));
		//alvo-- ; Na realidade o jogador 1 é o jogador 0, etc.
		return (alvo);
		}
	}
//==== Se só tem 2 jogadores, ataca a si mesmo. Caso contrario, pede alvo.
	case 3:
	{
	if (jogs == 2)
		{ /* Caso só haja dois vivos, ataca você mesmo */
		return (jogatual);
		}
	else
		{ /* Caso contrario pede um alvo */
		do
			{
			printf ("Diga o alvo: ");
			scanf ("%d",&alvo);
			__fpurge(stdin);
			alvo--;
			}
		while ((alvo < 0) || (alvo > jogs));
		//alvo-- ; Na realidade o jogador 1 é o jogador 0, etc.
		return (alvo);
		}
	}
//==== Pede por um alvo em qualquer circunstancia
	case 4:
	{
	do
		{
		printf ("Diga o alvo: ");
		scanf ("%d",&alvo);
		__fpurge(stdin);
		alvo--;
		}
	while ((alvo < 0) || (alvo > jogs));
	//alvo-- ; Na realidade o jogador 1 é o jogador 0, etc.
	return (alvo);
	}
} /* Fim do switch */

printf ("Erro critíco na função \"target\". spec inválido! \n Checar a chamada a está função \n spec recebido: %d",spec);
sleep(10);
exit(1);
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de ataque:
 * Essa função recebe um alvo, calcula um dano aleatorio usando o dano minimo e modificador  passados para a função e aplica este dano ao alvo.
 * 
 * @param alvo Indice do jogador a receber o dano
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param min dano mínimo do movimento
 * @param mod modificador de dano do movimento
 * @param custo Custo de mana do ataque
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_base_ataque(int alvo,int jogatual, vetor jogadores,int min, int mod, int custo)
{
int dmg;
// Calcula o dano	
dmg = rand()%(mod); dmg += min;
// Aplica o dano e decrementa o mp
jogadores[alvo].hp -= dmg;
jogadores[jogatual].mp -= custo;

// Imprime o que foi feito.
printf ("%s recebeu %d pontos de dano.\n",jogadores[alvo].nome, dmg);
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de ataque de área:
 * Esta função recebe o modificador e o dano mínimo de uma magia de àrea e calcula um dano
 * aleatório e o aplica a todos os jogadores exeto ao que executou a magia.
 * 
 * @param jogs Número total de jogadores
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param min Dano mínimo do ataque
 * @param mod Modificador de dano
 * @param custo Custo de mana do ataque
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_area_ataque(int jogs, int jogatual, vetor jogadores, int min, int mod, int custo)
{
int alvo,dmg;

// Se o alvo não é o próprio jogador, calcula um dano pra ele
for (alvo=0; alvo < jogs ; alvo ++)
	if (alvo != jogatual)
		{
		dmg = (rand()%mod)+min;
		jogadores[alvo].hp -= dmg;
		printf ("%s recebeu %d de dano.\n",jogadores[alvo].nome,dmg);
		}

// Desconta a mana utilizada
jogadores[jogatual].mp -= custo;
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de roubo de mana (mp):
 * Esta função recebe o modificador e o dano mínimo de uma magia de roubo de mana e, após 
 * invocar uma das funções "target", calcula um dano aleatório e o aplica ao alvo, dando
 * ao conjurador parte da mana roubada.
 * 
 * @param alvo Jogador a sofrer os efeitos do movimento
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param min Dano mínimo do ataque
 * @param mod Modificador de dano
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_mp_drain(int alvo, int jogatual, vetor jogadores, int min, int mod)
{
int temp,dmg,resp1;

// Calcula o quanto vai ser sugado
dmg = rand()%(mod);
dmg += min;

if ( jogadores[alvo].mp >= dmg )
	{
	jogadores[jogatual].mp += dmg-1;
	jogadores[alvo].mp -= dmg;
	printf ("%d Mps sugados, %d Mps absorvidos.\n", dmg,dmg-1);
	}
else
	{
	temp = dmg - jogadores[alvo].mp;
	if (temp < 0)
		{
		printf ("\nProblema no mp drain\n");
		sleep(10);
		exit (1);
		}
	resp1 = jogadores[alvo].mp;
	jogadores[jogatual].mp += jogadores[alvo].mp;
	jogadores[jogatual].mp += temp/2;
	jogadores[alvo].mp = 0;
	printf ("%s teve %d mps sugados. Destes %d Mps foram absorvidos.\n",jogadores[alvo].nome, resp1,resp1+temp/2);
	}
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de roubo de vida (hp):
 * Esta função recebe o modificador e o dano mínimo de uma magia de roubo de vida e, após 
 * invocar uma das funções "target", calcula um dano aleatório e o aplica ao alvo, dando
 * ao conjurador parte da vida roubada.
 * 
 * @param alvo Jogador a sofrer os efeitos do movimento
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param min Dano mínimo do ataque
 * @param mod Modificador de dano
 * @param custo Custo de mana do ataque
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_hp_drain(int alvo, int jogatual, vetor jogadores, int min, int mod, int custo)
{
int dmg;

// Calcula o quanto vai ser sugado
dmg = rand()%(mod);
dmg += min;

jogadores[alvo].hp -= dmg;
jogadores[jogatual].hp += dmg - 1;
jogadores[jogatual].mp -= custo;

printf ("%s teve %d hps sugados. Destes %d hps foram absorvidos.\n",jogadores[alvo].nome,dmg,dmg-1);
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de concentração:
 * Esta função recebe o modificador e o mínimo que um jogador pode recuperar de mana com
 * a concentração, calcula uma recuperação e adiciona o resultado a mana atual
 * 
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param min Dano mínimo do ataque
 * @param mod Modificador de dano
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_concentra(int jogatual, vetor jogadores, int min, int mod)
{
int dmg;
dmg = rand()%(mod);
dmg += min;
printf ("%d Mps recuperados\n", dmg);
jogadores[jogatual].mp += dmg;
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de efeito no hp:
 * Esta função aplica ao alvo os efeitos de hp, como regeneração e veneno, desde que a trava
 * do jogador alvo não estja ativada. O funcionamento dela é igual a da função global de
 * efeitos, exceto que ela espera já receber o alvo.
 * 
 * @param alvo ID do jogador a ser atingido
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param efeito dano/acresimo de hp por rodada
 * @param tempo modificador de tempo da magia
 * @param custo custo da execução da magia
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_hp_effect(int alvo, int jogatual, vetor jogadores,int efeito,int tempo,int custo)
{
int trava, esp= jogadores[alvo].hpmod.esp;

// decompoe o especial
trava = esp % 10; esp = esp / 10;

// Se a trava de hp mod está ativada, não faz nada
if (trava == 1)
	{
	printf ("Sem efeito!\n");
	return;
	}

// Caso o tempo de efeito seja menor que o máximo global, aumenta esse tempo
if ((jogadores[alvo].hpmod.dur < GBL_hp_gain_dur) && (jogadores[alvo].hpmod.dur > GBL_hp_loss_dur))
	jogadores[alvo].hpmod.dur += tempo;

// Caso a regeneração seja menor que o máximo global, aumenta o efeito
if ((jogadores[alvo].hpmod.mod < GBL_hp_gain) && (jogadores[alvo].hpmod.mod > GBL_hp_loss))
	jogadores[alvo].hpmod.mod += efeito;

	printf ("Para %s, o efeito durará %d rodadas\n",jogadores[alvo].nome,jogadores[alvo].hpmod.dur); 
	printf ("Hp será modificado a taxa de %d por rodada\n",jogadores[alvo].hpmod.mod);
jogadores[jogatual].mp -= custo;
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Função básica de efeito nos aps:
 * Esta função aplica ao alvo os efeitos de ap, como lentidão e velocidade, desde que a trava
 * do jogador alvo não estja ativada. O funcionamento dela é igual a da função global de
 * efeitos, exceto que ela espera já receber o alvo.
 * 
 * @param alvo ID do jogador a ser atingido
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param efeito dano/acresimo de ap por rodada
 * @param tempo modificador de tempo da magia
 * @param custo custo da execução da magia
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_ap_effect(int alvo, int jogatual, vetor jogadores,int efeito,int tempo, int custo)
{
int trava, esp= jogadores[alvo].apmod.esp;

// decompoe o especial
trava = esp % 10; esp = esp / 10;

// Se a trava de hp mod está ativada, não faz nada
if (trava == 1)
	{
	printf ("Sem efeito!\n");
	return;
	}

// Caso o tempo de efeito seja menor que o máximo global, aumenta esse tempo
if ((jogadores[alvo].apmod.dur < GBL_ap_gain_dur) && (jogadores[alvo].apmod.dur > GBL_ap_loss_dur))
	jogadores[alvo].apmod.dur += tempo;

// Caso a regeneração seja menor que o máximo global, aumenta o efeito
if ((jogadores[alvo].apmod.mod < GBL_ap_gain) && (jogadores[alvo].apmod.mod > GBL_ap_loss))
	jogadores[alvo].apmod.mod += efeito;

	printf ("Para %s, o efeito durará %d rodadas\n",jogadores[alvo].nome,jogadores[alvo].apmod.dur); 
	printf ("Ap será modificado a taxa de %d por rodada\n",jogadores[alvo].apmod.mod);
jogadores[jogatual].mp -= custo;
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Magia de cura
 * Está função executa um movimento de cura para o jogador indicado.
 * 
 * @param alvo Indice do jogador a receber a cura
 * @param jogadores Vetor com as fichas dos jogadores
 * @param min dano mínimo do movimento
 * @param mod midificador de dano do moviment
 * @param custo custo de mana do movimento
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_cura(int alvo, vetor jogadores, int min, int mod, int custo)
{
int dmg;
dmg = rand()%(mod);
dmg += min;
jogadores[alvo].hp += dmg;
jogadores[alvo].mp -= custo;

printf ("%d curados\n", dmg);
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Criar circulo mágico
 * Está função adiciona um nivel no circulo de magia para o jogador que o invoca, e desconta a mana utilizada para tanto.
 * 
 * @param jogatual Jogador atual
 * @param jogadores Vetor com as fichas dos jogadores
 * @param custo custo da execução da magia
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_charge(int jogatual,vetor jogadores, int custo)
{
jogadores[jogatual].buffer +=1;
jogadores[jogatual].mp -= custo;
printf("\n");
printf("                    =\n");
printf("                   = =\n");
printf("                  =   =\n");
printf("        = = = = =       = = = = =\n");
printf("         =                    =\n");
printf("           =                =\n");
printf("             =            =\n");
printf("           =                =\n");
printf("         =                    =\n");
printf("        = = = = =       = = = = =\n");
printf("                  =   =\n");
printf("                   = =\n");
printf("                    =\n");
return;
}

/* ----------------------------------------------------------------------------------------*/
/** @brief Ataque especial: Negatis
 * Esse é o ataque especial do mago vermelho. Ele cancela todos os buffs do alvo.
 * 
 * @param alvo Jogador que sofrerá os efeitos da magia
 * @param jogadores Vetor com as fichas dos jogadores
 *
 * @return nada */
/* ----------------------------------------------------------------------------------------*/
void GL_negatis(int alvo,vetor jogadores)
{
jogadores[alvo].buffer = 0;
jogadores[alvo].apmod.mod = 0;
jogadores[alvo].apmod.dur = 0;
jogadores[alvo].apmod.esp = 0;
jogadores[alvo].hpmod.mod = 0;
jogadores[alvo].hpmod.dur = 0;
jogadores[alvo].hpmod.esp = 0;
printf ("Condições neutralizadas!\n");
}
