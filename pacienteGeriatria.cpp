/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - impletamentação da classe herdeira pacienteGeriatria
 *
 */

#include "pacienteGeriatria.h"

using namespace std;

/*-------------------------------------------------------------------------------*/

PacienteGeriatria::PacienteGeriatria(const string nomeGer, const string genGer, const string numGer, const int idadeGer, const string nomeAc, const string tipoAc):
  Paciente(nomeGer, genGer, numGer, idadeGer){
    nomeAcompanhante = nomeAc;
    tipoAcompanhante = tipoAc;
  }


/*-------------------------------------------------------------------------------*/

void PacienteGeriatria::getInformacaoPessoal() const{
  cout << "Acompanhante do Paciente: " << nomeAcompanhante << "| Relação com o Paciente: " << tipoAcompanhante << endl;
}
