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
#include <utility>

#include "excecao.h"

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

using namespace std;

/*
template <typename T> class ArvoreBinaria;
template <typename T> ostream &operator<< (ostream &, const ArvoreBinaria<T> &);
*/
/*-------------------------------------------------------------------------------*/

template <class T>
class ArvoreBinaria{

/*  template <class U>
  friend ostream &operator<< (ostream &, const ArvoreBinaria<U> &);
*/
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

    void setNo(T * n){no = n;}
    T *getNo(){return no;}

    void setFilhoEsq(ArvoreBinaria *esq){esqPtr = esq;}
    ArvoreBinaria *getFilhoEsq(){return esqPtr;}

    void setFilhoDir(ArvoreBinaria *dir){dirPtr = dir;}
    ArvoreBinaria *getFilhoDir(){return dirPtr;}

    ArvoreBinaria *operator+=(T *);
    ArvoreBinaria *operator()(const string);

    template <class U>
    friend ostream &operator<< (ostream &, const ArvoreBinaria<U> &);

  private:
    T *no;
    ArvoreBinaria *esqPtr;
    ArvoreBinaria *dirPtr;
};

/*-------------------------------------------------------------------------------*/

template <class U>
ostream &operator<<(ostream &out, const ArvoreBinaria<U> &n){
    //if (n.getFilhoEsq() != NULL){
    if (n.esqPtr != NULL){
      out << *(n.esqPtr);
    }
    //out << *(n.getNo());

    out << *(n.no);
    //if (n.getFilhoDir() != NULL){
    if (n.dirPtr != NULL){
      out << *(n.dirPtr);
    }

    return out;
}

/*-------------------------------------------------------------------------------*/

template <class T>
ArvoreBinaria<T> *ArvoreBinaria<T>::operator+=(T *novoNo){
  ArvoreBinaria *av = NULL;
  if (no == NULL){
    no = novoNo;
    av = this;
    return av;
  }
  else{
    if(novoNo->getNome() == (no->getNome())){
      throw PacienteCadastradoException();
    }

    else if(novoNo->getNome() < (no->getNome())){
      if(dirPtr == NULL){
        dirPtr = new ArvoreBinaria<T>(novoNo);
        return (av = dirPtr);
      }else{
        //this = (*dirPtr) += novoNo;
        av = (*dirPtr)+= novoNo;
        return av;
      }
    }
    else{
      if (esqPtr == NULL){
        esqPtr = new ArvoreBinaria<T>(novoNo);
        return (av = esqPtr);
      }else{
        //this = (*esqPtr) += novoNo;
        av = (*esqPtr) += novoNo;
        return av;
      }
    }
  }
}

/*-------------------------------------------------------------------------------*/

template <class T>
ArvoreBinaria<T> *ArvoreBinaria<T>::operator()(const string nomeBusca){
  while((no != NULL) && (nomeBusca != no->getNome())){
    if(nomeBusca < (no->getNome())){
      if(dirPtr == NULL){return NULL;}
      return (*dirPtr)(nomeBusca);
    }
    else{
      if(esqPtr == NULL){return NULL;}
      return (*esqPtr)(nomeBusca);
    }
  }
  if (no == NULL){
    throw PacienteNaoEncontradoException();
  }
  return this;
}

#endif
