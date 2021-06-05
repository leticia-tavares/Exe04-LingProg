/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - impletamentação da classe herdeira pacienteGenetica
 *
 */

#include "pacienteGenetica.h"

using namespace std;


/*-------------------------------------------------------------------------------*/

PacienteGenetica::PacienteGenetica(const string nomeGen, const string generoGen, const string numeroGen, const int idadeGen, const string tipoABO):
  Paciente(nomeGen, generoGen, numeroGen, idadeGen){
    tipoSanguineo = tipoABO;
  }


  /*-------------------------------------------------------------------------------*/
  
virtual void PacienteGenetica::getInformacao() const{
  cout << "Tipo sanguíneo do paciente: " << tipoSanguineo << endl;
}
