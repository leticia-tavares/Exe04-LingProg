/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - implementação da classe paciente
 *
 */

#include <iostream>
#include <string>
#include "paciente.h"

using namespace std;

/*****************************************************************************/

friend ostream &operator<<(ostream &out, const Paciente &humano){
  out << "---Dados do Paciente---" << endl;
  out << "Nome: " << humano.getNome() << endl << "Gênero: " << humano.getGenero() << endl
  << "Idade: " <<humano.getIdade() << endl <<"Número: " << humano.getNumero() << endl;

  humano.getInformacaoPessoal();
  return out;
}

/*****************************************************************************/

Paciente::Paciente(string n, string g, string num, int id){
  setNome(n);
  setGenero(g);
  setNumero(num);
  setIdade(id);
}

/*****************************************************************************/

void Paciente::setNome(string n){nome = n;}
string Paciente::getNome(){return nome;}

/*****************************************************************************/

void Paciente::setGenero(string g){genero = g;}
string Paciente::getGenero(){return genero;}

/*****************************************************************************/

void Paciente::setNumero(string num){numero = num;}
string Paciente::getNumero(){return numero;}

/*****************************************************************************/

void Paciente::setIdade(int id){idade = id;}
int Paciente::getIdade(){return idade;}

/*****************************************************************************/

//virtual void getInformacaoPessoal() const;

/*****************************************************************************/

bool Paciente::operator<(const Paciente &humano){return (this->nome < humano.getNome());}

bool Paciente::operator>(const Paciente &humano){return (this->nome > humano.getNome());}

bool Paciente::operator==(const Paciente &humano){return (this->nome == humano.getNome());}
