/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - header da classe herdeira pacienteGenetica
 *
 */

#include <string>
#include "paciente.h"

#ifndef PACIENTEGENETICA_H
#define PACIENTEGENETICA_H

using namespace std;

class PacienteGenetica: public Paciente{
  public:
    PacienteGenetica(const string, const string, const string, const int, const string);
    //PacienteGenetica(const string, const string, const int, const string)
    virtual void getInformacaoPessoal() const;

 private:
   string tipoSanguineo;
};

#endif
