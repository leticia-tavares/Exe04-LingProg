/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - programa principal
 *
 */

#include <iostream>
#include <string>

#include "excecao.h"
#include "cadastro.h"
#include "arvoreBinaria.h"
#include "paciente.h"
#include "pacienteGeriatria.h"
#include "pacienteGenetica.h"

using namespace std;

void inserirPaciente (Cadastro &c){
  int tipo, idade;
  string nome, genero, numero;
  cout << "1 - Cadastrar Paciente da Geriatria."<<endl;
  cout << "2 - Cadastrar Paciente da Genética."<<endl;
  cout << "Tipo: " ;
  cin >> tipo;

  //Paciente *paciente = NULL;
  cout << "Insira o nome do paciente: ";
  cin.ignore();
  getline(cin, nome);
  cout << endl;

  cout << "Insira o gênero do paciente: ";
  cin.ignore();
  getline(cin, genero);
  cout << endl;

  cout << "Insira telefone para contato (formato (xxx)xxxxx-xxxx): ";
  cin.ignore();
  getline(cin, numero);
  cout << endl;

  cout << "Insira a idade do paciente: ";
  cin >> idade;
  cout << endl;

  if(tipo == 1){
    string nomeAcomp, tipoAcomp;
    cout << "Insira o nome do acompanhante: ";
    cin.ignore();
    getline(cin, nomeAcomp);
    cout << endl;

    cout << "Insira a relação do acompanhante com o paciente: ";
    cin.ignore();
    getline(cin, tipoAcomp);
    cout << endl;
    PacienteGeriatria paciente(nome,genero, numero, idade, nomeAcomp, tipoAcomp);
  //  paciente = new PacienteGeriatria(nome, genero, numero, idade, nomeAcomp, tipoAcomp);
    c.inserirPaciente(paciente);
  }
  else if (tipo == 2){
    string tipoSangue;
    cout << "Insira tipo sanguíneo do paciente: ";
    cin.ignore();
    getline(cin, tipoSangue);
    cout << endl;

    PacienteGenetica paciente(nome, genero, numero, idade, tipoSangue);
    //paciente = new PacienteGenetica(nome, genero, numero, idade, tipoSangue);
    c.inserirPaciente(paciente);
  }
  else{
    cout << "Entrada inválida! Por favor, tente novamente: "<< endl;
    inserirPaciente(c);
  }
}

int main (){
  int opcao = 0; //default do switch

  ArvoreBinaria <Paciente> *raiz = new ArvoreBinaria <Paciente>();

  Cadastro cadastro(raiz);

  cout << "\n\n--------------- C A D A S T R O  H O S P I T A L A R ---------------" << endl;

  while(opcao != -1){
    try{

      cout << "\n1 - Inserir novo paciente." <<endl;
      cout << "\n2 - Buscar dados de um paciente." << endl;
      cout << "\n3 - Imprimir dados de todos os pacientes." << endl;
      cout << "\n-1 - Terminar programa" << endl;

      cout << "\nEntre com a opção desejada: ";
      cin >> opcao;

      switch(opcao){
        case -1:{ //terminar programa
          cout<< "Saindo do programa..."<<endl;
          cout<< "\n--------------- F I M ---------------" << endl;
        }
        return 0;
        case 1:{ //inserir paciente
          cout<< "\n--------------- INSERIR PACIENTE---------------"<<endl;
          inserirPaciente(cadastro);
          cout << "------------------------------" << endl;
          break;
        }
        case 2:{//busca de paciente
          cout<< "\n--------------- BUSCAR DADOS DE PACIENTE ---------------"<<endl;
          string nomeBusca;

          cout << "Insira o nome desejado: ";
          cin.ignore();
          getline(cin, nomeBusca);

          cadastro.buscarPaciente(nomeBusca);

          cout << "------------------------------" << endl;
          break;
        }
        case 3:{ //impressão
          cout<< "\n--------------- PACIENTES REGISTRADOS---------------"<<endl;

          cadastro.imprimirCadastro();

          cout << "------------------------------" << endl;
          break;
        }
        default:{
          cout << "Entrada inválida! Por favor, tente novamente:" << endl;
          cin >> opcao;
        }
      }
    }
    catch (PacienteCadastradoException &erro1) {
        cout << erro1.what();
    }

    catch (PacienteNaoEncontradoException &erro2) {
        cout << erro2.what();
    }

  }
  cout<< "\nTerminando programa..."<<endl;
  return 0; //OK
}
