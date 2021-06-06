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

ostream &operator<<(ostream &out, const Paciente &humano){
  out << "---Dados do Paciente---" << endl;
  out << "Nome: " << humano.getNome() << endl << "Gênero: " << humano.getGenero() << endl
  << "Idade: " <<humano.getIdade() << endl <<"Número: " << humano.getNumero() << endl;

  humano.getInformacaoPessoal();
  return out;
}

/*****************************************************************************/

Paciente::Paciente(const string n, const string g, const string num, const int id){
  setNome(n);
  setGenero(g);
  setNumero(num);
  setIdade(id);
}

/*****************************************************************************/

void Paciente::setNome(const string n){nome = n;}
string Paciente::getNome() const{return nome;}

/*****************************************************************************/

void Paciente::setGenero(const string g){genero = g;}
string Paciente::getGenero() const{return genero;}

/*****************************************************************************/

void Paciente::setNumero(const string num){numero = num;}
string Paciente::getNumero()const {return numero;}

/*****************************************************************************/

void Paciente::setIdade(const int id){idade = id;}
int Paciente::getIdade() const {return idade;}

/*****************************************************************************/

void Paciente::getInformacaoPessoal() const{;}

/*****************************************************************************/

bool Paciente::operator<(const Paciente &humano){return (this->nome < humano.getNome());}

bool Paciente::operator>(const Paciente &humano){return (this->nome > humano.getNome());}

bool Paciente::operator==(const Paciente &humano){return (this->nome == humano.getNome());}
