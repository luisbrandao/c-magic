#include <stdio.h>			// inclui diretivas de entrada-saída
#include <stdlib.h>     	// Usa recursos do sistema
#include <time.h>			// Permite o uso do tempo do sistema 
#include <stdio_ext.h>		// Precisa para o fpurge
#include <unistd.h>			// Sleep sem syscall

#include "funcoesA.h"	   	// Modulos básicos do jogo
#include "definicoes.h" 	// Constantes e structs usados no jogo

#include "MagoAzul.h"   	// Biblioteca de ações e opções da classe "Mago Azul"
#include "MagoBranco.h"		// Biblioteca de ações e opções da classe "Mago Branco"
#include "MagoVerde.h"		// Biblioteca de ações e opções da classe "Mago Verde"
#include "MagoVermelho.h"	// Biblioteca de ações e opções da classe "Mago Vermelho"
#include "MagoNegro.h"		// Biblioteca de ações e opções da classe "Mago Negro"

#include "rayka.h"			// AI monera
#include "monera.h"			// AI monera

/**
 * @mainpage C-Magic
 * @section intro_sec c-magic » x-magic em c!
 *
 * Changelog
 - v < 1.? » 27/10/2008 » Pascal
 - v 2.0.00 » 01/09/2009 » Começo do projeto
 - v 2.0.01 » 22/09/2009 » Inicialização do programa pronto, funções placar, limpa tudo e opções pronta
 - v 2.0.02 » 01/10/2009 » Programa dividido em ataque.c e funcoesA.c, Função target,cajado
 - v 2.0 » 01/10/2009 » Todas as funções básicas prontas.
 - v 2.1 » 02/10/2009 » Função auto-target: funciona somente quando tem 2 jogadores,em algumas funções. Não usa mais gets()
 - v 2.2 » 09/10/2009 » Algumas modificações na saida de texto, completada a congratulação do vencedor.
 - v 2.3 » 23/10/2009 » Retirada a leitura de multiplos valores na ação, função bip.
 - v 2.4 » 27/10/2009 » Função bip retirada (não funciona), desfeitas as gambiarras (fpurge resolve o problema com gets)
 - v 3.0.01 » 28/10/2009 » Inicio do desenvolvimento da versão 3.0
 - v 3.0.02 » 29/10/2009 » Engine principal funcionando. Falta os ataques de cada classe
 - v 3.0.03 » 30/10/2009 » Mago vermelho pronto. Falta balancear. 
 - v 3.0.04 » 04/11/2009 » Mago negro pronto. Falta balancear.
 - v 3.0.05 » 08/11/2009 » Mago azul pronto, falta balancear. Novo makefile. (completo)
 - v 3.0.06 » 09/11/2009 » Mago verde e branco prontos e balanceados. Contrib do Fabrício
 - v 3.0.07 » 11/11/2009 » Primeiro balanceamento de tudo. ap padrão mudado pra 6.
 - v 3.0.08 » 12/11/2009 » Criada funções genericas GL_base_ataque, GL_area_ataque, que substituiem todas as funçoes de ataques simples.
 - v 3.0.09 » 13/11/2009 » Corrigidos alguns bugs, criação do ai rayka.
 - v 3.0.10 » 16/11/2009 » Criação do ai monera(Fabricio)
 - v 3.0.11 » 17/11/2009 » Corrigidos alguns bugs, desativado o mínimo do degrada, balanço do MN
 - v 3.0.12 » 13/12/2009 » Primeira versão funcional do monera (Fabricio)
 - v 3.0.13 » 15/12/2009 » Documentação em doxygen
 - v 3.1.00 » 16/05/2010 » A maior parte das funçoes de ataque agora é generica, adicionado lock de stat, condicões especiais agora são tratadas em função própria (degrada agora funciona direito). AI rayka atualizada, várias partes agora estão documentadas. 
 - v 3.1.01 » 24/05/2010 » Função cajado agora não existe mais (base atack assume também essa função), finalização da documentação do codigo, mago branco já possuiu sua magia superior implementada, AP inicial para cada rodada agora é definido por constante. Função target agora é única e trata vários casos especiais
 - v 3.2 » 25/05/2010 » Biblioteca "funcoesC" Excluida. Funcões do "funcoesB" adequadas para receberem o alvo de fora. Todo o codigo foi adequado aos novos parametros. Implementado a magia superior do mago vermelho, corrigido bug no target.*/
 
//==============================================================================================
/** ----------------------------------------------------------------------------------------------
 * @file c-magic.c
 * @brief Módulo central do programa. 
 * A Função main é responsavel por chamar as funções que preparam as fichas dos jogadores e pelo loop principal do jogo.<br>
 * O loop principal é encarregado de aplicar os esfeitos especiais, (veneno, regeneração, velocidade, lentidão e paralizia) de contar os pontos de movimento e decidir se o jogo acabou ou se ele deve continuar. (se ainda há vivos)<br>
 *          ---<br>
 * FIXME: As vezes, o loop principal devolve a ação para o jogador mesmo quando não há oponentes vivos. 
 * @author Luis Alexandre D. Brandao
 */
//==============================================================================================
int main ()
{
// ------------------------- Declaração de variáveis.--------------------------------
vetor jogadores;
int vivos,jogs,jogatual,i,ganhador,aps;

lipatudo (jogadores); // Limpa as fichas dos jogadores
jogs = time(NULL);    // Criar uma sed de para os números aleatórios
srand(jogs);

// ---------------------------------------------------------------------------------
// ------------------------ Preparação do jogo ---------------------------------------
// ----------------------------------------------------------------------------------
system("clear");
printf (" Bem vindo ao x-magic em c, ver 3.0.13\n");
printf ("     22/09/2009 » 17/11/2009\n\n");

jogs = cold_start(jogadores);
vivos = jogs;
jogatual = rand()%(jogs); // Define o primeiro jogador aléatoriamente.

printf ("\nPor favor, aguarde.\n");
while ( vivos > 1 )
	{
	sleep(t_delay+t_delay); // Teste
	jogatual = (jogatual + 1) % jogs ;	// Muda para o proximo jogador
	aps=GL_int_ap;                      // Pontos de ação padrão

// ---------------------------- Condições -----------------------------
	trata_condicoes(&aps,jogatual,jogadores);

// ------------------------------ Morto -------------------------------
// Se o jogador atual está morto, pula a vez dele.
	if (jogadores[jogatual].hp <= 0) continue;
		
// Testa se há sentido em continuar os ataques
	vivos = conta_vivos(jogadores,jogs);
	if (vivos <= 1)	break;

	// --------------------------- ações ---------------------------------------
	// Vai para o menu da classe específica
	system("clear");
	while (aps > 0)
		{
			switch (jogadores[jogatual].classe)
				{
		// Opçoes para a jogada de um mago azul
				case M_azul:
				aps -= acao_azul(aps, jogs,jogatual,jogadores);
				break;
		// Opçoes para a jogada de um mago branco
				case M_branco:
				aps -= acao_branco(aps, jogs,jogatual,jogadores);
				break;
		// Opçoes para a jogada de um mago verde
				case M_verde:
				aps -= acao_verde(aps, jogs,jogatual,jogadores);
				break;
		// Opçoes para a jogada de um mago vermelho
				case M_vermelho:
				aps -= acao_vermelho(aps, jogs,jogatual,jogadores);
				break;
		// Opçoes para a jogada de um mago negro
				case M_negro:
				aps -= acao_negro(aps, jogs,jogatual,jogadores);
				break;
		// AI rayka
				case AI_rayka:
				aps -= acao_rayka(vivos, aps,jogs,jogatual,jogadores);
				break;
		// AI monera
				case AI_monera:
				aps -= acao_monera(vivos, aps,jogs,jogatual,jogadores);
				break;
				}

	// Testa se há sentido em continuar os ataques
		vivos = conta_vivos(jogadores,jogs);
		if (vivos <= 1) break;

	// Começa o proximo movimento do jogador
		system("clear");
		}

	placar (jogs, jogatual, jogadores);
	printf ("===============================================================\n");
	printf ("======================== Próximo Turno ========================\n");
	printf ("===============================================================\n");
	}

// ----------------------------------- Finalização -----------------------------------
// Descobre quem ganhou:
ganhador = -1; // ninguem
for (i = 0; i <= jogs; i++)
	if (jogadores[i].hp > 0) ganhador=i;
system("clear");

if (ganhador == -1)
	{
	placar (jogs, jogatual, jogadores); // Só para mostrar a situação final
	printf ("\n\n\n");
	printf ("===============================================================\n");
	printf ("                              Acabou!\n");
	printf ("                            Ninguem ganhou!");
	printf ("                    Isso não deveria acontecer!\n");
	printf ("===============================================================\n");
	return(0);
	}
else
	{
	placar (jogs, jogatual, jogadores); // Só para mostrar a situação final
	printf ("\n\n\n");
	printf ("===============================================================\n");
	printf ("                              Acabou!\n");
	printf ("                        Ganhador: %s.\n", jogadores[ganhador].nome);
	printf ("                    Parabens para quem ganhou!\n");
	printf ("===============================================================\n");
	return(0);
	}

}
