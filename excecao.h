/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - tratamento de exceções
 *
 */

#include <stdexcept>

#ifndef EXCECAO_H
#define EXCECAO_H

using namespace std;

class PacienteCadastradoException: public runtime_error{
    public:
        PacienteCadastradoException()
        : runtime_error("Este paciente já existe no cadastro.") {}
};

class PacienteNaoEncontradoException: public runtime_error{
    public:
        PacienteNaoEncontradoException()
        : runtime_error("Este paciente não existe no cadastro.") {}
};

#endif
