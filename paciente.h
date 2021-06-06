/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - header da classe paciente
 *
 */

#include <iostream>
#include <string>

#ifndef PACIENTE_H
#define PACIENTE_H

using namespace std;

class Paciente{
  friend ostream &operator<<(ostream&, const Paciente &);

  public:
    Paciente(const string, const string, const string, const int);

    void setNome(const string);
    string getNome() const;

    void setGenero(const string);
    string getGenero() const;

    void setNumero(const string);
    string getNumero() const;

    void setIdade(const int);
    int getIdade() const;

    virtual void getInformacaoPessoal() const;

    bool operator< (const Paciente &);
    bool operator> (const Paciente &);
    bool operator== (const Paciente &);

 private:
   string nome, genero, numero;
   int idade;
};

#endif
