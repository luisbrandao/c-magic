 # c-magic » x-magic em c!

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



Módulos.txt
Detalhe de cada arquivo

Luis Alexandre
v 1.0 » 28/10/2009 » Primeira versão


## Base
c-magic.c
	- Função main
	- Loop principal
	- tratador de condiçoes especiais

definicoes.h
	- Variaveis e definições genéricas
## Genérico

funcoesA.h
 » funcoesA.c
	- Funções principais
		- Limpa_tudo (Inicia jogadores)
		- Placar
		- conta_vivos (Descobre quantos jogadores ainda estão em cena)
		- cold_start (Prove toda a configuração inicial do jogo e devolve o número de jogadores)

funcoesB.h
 » funcoesB.c
	- Funções auxiliares
		- auto_target (escolhe um alvo automaticamente caso só haja 2 jogadores)
		- target (pede para o jogador escolher um alvo e garante que a escolha seja válida)
	- Ataques genéricos
		- cajado
		- GL_base_ataque
		- GL_area_ataque
		- GL_mp_drain
		- GL_concentra

## Classes
MagoAzul.h
	- consantes específicas
 » MagoAzul.c
	- Funcões relacionadas
		- acao_azul
		- opcoes_azul
	- Ataques específicos
		- MA_regeneracao
		- MA_congelar
		- MA_concentrar

MagoBranco.h
	- consantes específicas
 » MagoBranco.c
	- Funcões relacionadas
		- acao_azul
		- opcoes_azul
	- Ataques específicos
		- MB_cura
		- MB_haste
		- MB_conc

MagoVerde.h
	- consantes específicas
 » MagoVerde.c
	- Funcões relacionadas
		- acao_verde
		- opcoes_verde
	- Ataques específicos
		- MG_esporos
		- MG_veneno
		- MG_hpdrain
		- MG_enrolar
		- MG_mpdrain

MagoVermelho.h
	- consantes específicas
 » MagoVermelho.c
	- Funcões relacionadas
		- acao_vermelho
		- opcoes_vermelho
	- Ataques específicos
		- MV_cura_leve
		- MV_negatis
		- MV_concentrar

MagoNegro.h
	- consantes específicas
 » MagoNegro.c
	- Funcões relacionadas
		- acao_negro
		- opcoes_negro
	- Ataques específicos
		- MN_estigma
		- MN_maldicao
		- MN_hpdrain
		- MN_mpdrain
		- MN_charge

## AIs
rayka.h
	- Constantes especificas
	- informações de versão
 » rayka.c
	- Função principal
		- rayka_acoes
	- Ataques específicos
	 	- Ataques específicos

monera.h
	- Constantes especificas
	- Informaçoes da versão
 » monera.c
 	- Função princial
 		- monera_acoes

## Documentação
classes.ods
	- Relação de ataques/danos de cada classe

makefile
	- Automatizador de copilação

Modulos.txt
	- Este aquivo.
	- Descrição de todas as partes do jogo
