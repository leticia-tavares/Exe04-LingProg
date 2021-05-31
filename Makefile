#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL670 - Linguagens de Programação
# Prof. Miguel
# Autor: Leticia Tavares
# Descricao: arquivo de Makefile
#
#
# g++ -Wall main.cpp excecao.cpp cadastro.cpp paciente.cpp pacienteGenetica.cpp pacienteGeriatria.cpp -o cadastroExe


#Compilar
CC = g++
LD = g++

#Linkeditar

CFLAGS = -Wall
LFLAGS = -Wall

#Dependencias
LAB09OBJS = main.o excecao.o cadastro.o paciente.o pacienteGenetica.o pacienteGeriatria.o

LAB09 = cadastroExe
EXECS = $(LAB09)

ALL = $(EXECS)

#Regra Implicita

.cpp.o:
	$(CC)  $(CFLAGS) -c $<

all: $(ALL)

cadastroExe: $(LAB09OBJS)
	$(LD) $(LFLAGS) -o $@ $(LAB09OBJS)

clean:
	rm -f *.o $(EXECS)

clean-all:
	rm -f *.o $(EXECS)
