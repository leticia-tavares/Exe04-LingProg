/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - implementação da classe cadastro
 *
 */

#include <iostream>
#include <string>
#include "cadastro.h"

using namespace std;

/*****************************************************************************/

void Cadastro::inserirPaciente(Paciente &humano){
  arvoreCadastro->operator+=(&humano);
}

/*****************************************************************************/

void Cadastro::buscarPaciente(const string nomeP){
  ArvoreBinaria <Paciente> *pacientePtr = (*arvoreCadastro)(nomeP);

  if (pacientePtr != NULL){
    cout << (*pacientePtr->getNo()) << endl;
  }
}

/*****************************************************************************/

void Cadastro::imprimirCadastro()const{
  cout << *(arvoreCadastro);
}

/*****************************************************************************/

ArvoreBinaria <Paciente> *Cadastro::getArvoreCadastro(){return arvoreCadastro;}
