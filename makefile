all: c-magic
# ======================================================================
c-magic: c-magic.o funcoesA.o funcoesB.o MagoNegro.o MagoAzul.o MagoBranco.o MagoVerde.o MagoVermelho.o Rayka.o Monera.o
	gcc -Wall -Wextra c-magic.o funcoesA.o funcoesB.o MagoNegro.o MagoAzul.o MagoBranco.o MagoVerde.o MagoVermelho.o Rayka.o Monera.o -o c-magic.out
# ======================================================================
funcoesA.o: funcoesA.c definicoes.h
	gcc -Wall -Wextra -c -o funcoesA.o funcoesA.c
# ======================================================================
funcoesB.o: funcoesA.o funcoesB.c definicoes.h
	gcc -Wall -Wextra -c -o funcoesB.o funcoesB.c
# ======================================================================
MagoAzul.o: funcoesA.o funcoesB.o MagoAzul.c MagoAzul.h definicoes.h
	gcc -Wall -Wextra -c -o MagoAzul.o MagoAzul.c
# ======================================================================
MagoBranco.o: funcoesA.o funcoesB.o MagoBranco.c MagoBranco.h definicoes.h
	gcc -Wall -Wextra -c -o MagoBranco.o MagoBranco.c
# ======================================================================
MagoNegro.o: funcoesA.o funcoesB.o MagoNegro.c MagoNegro.h definicoes.h
	gcc -Wall -Wextra -c -o MagoNegro.o MagoNegro.c
# ======================================================================
MagoVerde.o: funcoesA.o funcoesB.o MagoVerde.c MagoVerde.h definicoes.h
	gcc -Wall -Wextra -c -o MagoVerde.o MagoVerde.c
# ======================================================================
MagoVermelho.o: funcoesA.o funcoesB.o MagoVermelho.c MagoVermelho.h definicoes.h
	gcc -Wall -Wextra -c -o MagoVermelho.o MagoVermelho.c
# ======================================================================
Rayka.o: funcoesB.o rayka.c rayka.h MagoVermelho.h definicoes.h
	gcc -Wall -Wextra -c -o Rayka.o rayka.c
# ======================================================================
Monera.o: funcoesB.o monera.c monera.h MagoVerde.h definicoes.h
	gcc -Wall -Wextra -c -o Monera.o monera.c
# ======================================================================
clean:
	rm *.o
# ======================================================================
faxina:
	rm c-magic.out
	rm *.o
	rm -r html
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
