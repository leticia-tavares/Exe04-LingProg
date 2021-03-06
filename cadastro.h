/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - header da classe cadastro
 *
 */

#include <iostream>
#include <string>
#include "arvoreBinaria.h"
#include "paciente.h"

#ifndef CADASTRO_H
#define CADASTRO_H

using namespace std;

class Cadastro{

  //friend ostream &operator<< (ostream &, Cadastro &);

  public:
    Cadastro(ArvoreBinaria <Paciente> *novoNo):arvoreCadastro(novoNo){}

    void inserirPaciente(Paciente &);
    void buscarPaciente(const string);
    void imprimirCadastro() const;

    ArvoreBinaria <Paciente> *getArvoreCadastro();

  private:
    ArvoreBinaria <Paciente> *arvoreCadastro;
};

#endif
