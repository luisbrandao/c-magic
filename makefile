all: c-magic
# ======================================================================
c-magic: c-magic.o funcoesA.o funcoesB.o MagoAzul.o MagoBranco.o MagoNegro.o MagoVerde.o MagoVermelho.o Rayka.o Monera.o
	gcc -Wall -Wextra *.o -o c-magic.out
# ======================================================================
c-magic.o: src/c-magic.c src/definicoes.h
	gcc -Wall -Wextra -c -o c-magic.o src/c-magic.c 
# ======================================================================
funcoesA.o: src/funcoesA.c src/definicoes.h
	gcc -Wall -Wextra -c -o funcoesA.o src/funcoesA.c
# ======================================================================
funcoesB.o: funcoesA.o src/funcoesB.c src/definicoes.h
	gcc -Wall -Wextra -c -o funcoesB.o src/funcoesB.c
# ======================================================================
MagoAzul.o: funcoesA.o funcoesB.o src/MagoAzul.c src/MagoAzul.h src/definicoes.h
	gcc -Wall -Wextra -c -o MagoAzul.o src/MagoAzul.c
# ======================================================================
MagoBranco.o: funcoesA.o funcoesB.o src/MagoBranco.c src/MagoBranco.h src/definicoes.h
	gcc -Wall -Wextra -c -o MagoBranco.o src/MagoBranco.c
# ======================================================================
MagoNegro.o: funcoesA.o funcoesB.o src/MagoNegro.c src/MagoNegro.h src/definicoes.h
	gcc -Wall -Wextra -c -o MagoNegro.o src/MagoNegro.c
# ======================================================================
MagoVerde.o: funcoesA.o funcoesB.o src/MagoVerde.c src/MagoVerde.h src/definicoes.h
	gcc -Wall -Wextra -c -o MagoVerde.o src/MagoVerde.c
# ======================================================================
MagoVermelho.o: funcoesA.o funcoesB.o src/MagoVermelho.c src/MagoVermelho.h src/definicoes.h
	gcc -Wall -Wextra -c -o MagoVermelho.o src/MagoVermelho.c
# ======================================================================
Rayka.o: funcoesB.o src/rayka.c src/rayka.h src/MagoVermelho.h src/definicoes.h
	gcc -Wall -Wextra -c -o Rayka.o src/rayka.c
# ======================================================================
Monera.o: funcoesB.o src/monera.c src/monera.h src/MagoVerde.h src/definicoes.h
	gcc -Wall -Wextra -c -o Monera.o src/monera.c
# ======================================================================
clean:
	rm *.o
# ======================================================================
faxina:
	rm -rf c-magic.out
	rm -rf *.o
	rm -rf html
# ======================================================================
tudo: 
	gcc -O3 -Wall -Wextra c-magic.c funcoesA.c funcoesB.c MagoNegro.c MagoAzul.c MagoBranco.c MagoVerde.c MagoVermelho.c rayka.c monera.c -o c-magic.out
# ======================================================================
doc:
	doxygen Doxyfile
# ======================================================================
help:
	@echo make
	@echo make clean
	@echo make faxina
	@echo make tudo
	@echo make doc
