/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 9 - estrutura da árvore binária
 * implementada como uma classe template
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <ostream>

#include "excecao.h"

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

using namespace std;

/*-------------------------------------------------------------------------------*/

template <class T>
class ArvoreBinaria{

  template <class T>
  friend ostream &operator<< (ostream &, const ArvoreBinaria<T> &);

  public:
    ArvoreBinaria(T * n = NULL, ArvoreBinaria *esq = NULL, ArvoreBinaria *dir = NULL){
      setNo(n);
      setFilhoEsq(esq);
      setFilhoDir(dir);
    }
    ~ArvoreBinaria(){
      delete no;
      delete esqPtr;
      delete dirPtr;
    }

    void ArvoreBinaria *setNo(T * n){no = n;}
    T *getNo(){return no;}

    void setFilhoEsq(ArvoreBinaria *esq){esqPtr = esq;}
    ArvoreBinaria *getFilhoEsq(){return esqPtr;}

    void setFilhoDir(ArvoreBinaria *dir){dirPtr = dir;}
    ArvoreBinaria *getFilhoDir(){return dirPtr;}

    ArvoreBinaria *operator+=(T *);
    ArvoreBinaria *operator()(const string);

  private:
    T *no;
    ArvoreBinaria *esqPtr;
    ArvoreBinaria *dirPtr;
};

/*-------------------------------------------------------------------------------*/

template <class T>
ostream &operator<<(ostream &out, const ArvoreBinaria<T> &n){
    if (n->esqPtr != NULL){
      out << *(n->esqPtr);
    }

    out << *(n->no);

    if (n->dirPtr != NULL){
      out << *(n->dirPtr);
    }

    return out;
};

/*-------------------------------------------------------------------------------*/

template <class T>
ArvoreBinaria *ArvoreBinaria<T>::operator+=(T *novoNo){
  if ((this->no) == NULL){
    (this->no) = novoNo;
  }
  else{
    if(novoNo->getName == (this->no->getNome())){
      throw PacienteCadastradoException();
    }
    else if(novoNo->getNome() < (this->no->getNome())){
      if(this->dirPtr == NULL){
        (this->dirPtr) = new ArvoreBinaria<T>(novoNo);
      }else{
        this = (*this->dirPtr) += novoNo;
      }
    }
    else{
      if ((this->esqPtr)== NULL){
        (this->esqPtr) = new ArvoreBinaria<T>(novoNo);
      }else{
        this = (*this->esqPtr) += novoNo;
      }
    }
  }
  return this;
}

/*-------------------------------------------------------------------------------*/

template <class T>
ArvoreBinaria *ArvoreBinaria<T>::operator()(const string nomeBusca){

  while(((this->no) =! NULL && nomeBusca =! this->no->getNome())){
    if(nomeBusca < (this->no->getNome())){
      this = (this->esqPtr);
    }
    else {
      this = (this->dirPtr);
    }
  }

  if ((this)== NULL){
    throw PacienteNaoEncontradoException();
  }

  return this;
}

#endif
