// AUTOR: Daniel Pérez Rodríguez
// FECHA: 2/02/2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

// Clase matrix_t
// Crea objetos al estilo de una matriz, con columnas y filas
template<class T> class matrix_t {
 public:
  // Constructores
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  // Cambiar la medida del vector 
  void resize(const int, const int);
  // Getters
  int get_m(void) const; //Obtiene el número de filas
  int get_n(void) const; //Obtiene el númerod de columnas
  // Getters-setters
  T& at(const int, const int); // Retorna el valor del elemento seleccionado
  T& operator()(const int, const int); // Retorna el valor del elemento seleccionado
  // Getters constantes
  const T& at(const int, const int) const; // Retorna el valor del elemento seleccionado
  const T& operator()(const int, const int) const; // Retorna el valor del elemento seleccionado
  // Operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&); // Multiplicación de matrices
  void write(ostream& = cout) const; // Imprime la matriz
  void read(istream& = cin); // Redefine la matriz

 private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const; // Retorna la posición del elemento
};

// Constructor dándose el número de filas y columnas
// Parámetros: número de filas y de columnas
template<class T> matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

// Destructor de la matriz
template<class T> matrix_t<T>::~matrix_t() {}

// Redefine el número de filas y columnas
// Parámetros: número de filas y de columnas
template<class T> void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

// Devuelve el número de filas
template<class T> inline int matrix_t<T>::get_m() const {
  return m_;
}

// Devuelve el número de columnas
template<class T> inline int matrix_t<T>::get_n() const {
  return n_;
}

// Devuelve el valor del elemento que se pide
// Parámetros: númro de filas y de columnas
template<class T> T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

// Devuelve el valor del elemento
// Parámetros: fila y columna
template<class T> T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}

// Devuelve el valor del elemento
// Parámetros: fila y columna
template<class T> const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

// Devuelve el valor del elemento
// Parámetros: fila y columna
template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

// Imprime la matriz con todos sus valores
// Parámetro: flujo de salida
template<class T> void matrix_t<T>::write(ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

// Modifica una matriz dándose los valores
// Parámetro: flujo de entrada
template<class T> void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

// Devuelve la posición en la que se encuentra el elemento
// Parámetros: fila y columna
template<class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}

// FASE III: producto matricial
// Multiplicación de matrices 
// Parámetros: dos matrices a multiplicar
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_m() == B.get_n()); // Comprobamos que la matriz A tiene el mismo número de filas que la B de columnas
  resize(A.get_m(), B.get_n());
  double producto{0};
  for (int k{1}; k <= A.get_m(); ++k){
    for (int i{1}; i <= A.get_m(); ++i) {
      for (int j{1}; j <= A.get_n(); ++j) {
        producto = producto + A.at(i,j) * B.at(j,k);       
      }
      at(i, k) = producto;
      producto = 0;
    }
  }
}
// 28 14 
// 79 44