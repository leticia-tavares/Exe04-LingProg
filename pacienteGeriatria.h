/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - header da classe herdeira pacienteGeriatria
 *
 */

#include <string>
#include "paciente.h"

#ifndef PACIENTEGERIATRIA_H
#define PACIENTEGERIATRIA_H

using namespace std;

class PacienteGeriatria: public Paciente{
  public:
    PacienteGeriatria(const string, const string, const string, const int, const string, const string);
    //PacienteGeriatria(const string, const string, const int, const string, const string);
    virtual void getInformacao() const;

 private:
   string nomeAcompanhante, tipoAcompanhante;
};

#endif
