// AUTOR: Daniel Pérez Rodríguez
// FECHA: 2/02/2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2

#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// Clase vector_t
// Contiene vector y su medida
template<class T> class vector_t {
 public:
  // Constructores
  vector_t(const int = 0);
  ~vector_t();
  // Cambiar la medida del vector 
  void resize(const int);
  // Getters
  T get_val(const int) const; // Obtiene el valor del elemento seleccionado
  int get_size(void) const; // Obtiene la medida del vector
  // Setters
  void set_val(const int, const T); // Cambia el valor del elemento seleccionado
  // Getters-Setters
  T& at(const int); // Retorna el valor del elemento seleccionado
  T& operator[](const int); // Retorna el valor del elemento seleccionado
  // Getters constantes
  const T& at(const int) const; // Retorna el valor del elemento seleccionado
  const T& operator[](const int) const; // Retorna el valor del elemento seleccionado
  void write(ostream& = cout) const; // Imprime el vector
  void read(istream& = cin); // Redefine el vector

 private:
  T *v_;
  int sz_;
  
  void build(void); // Creación del vector
  void destroy(void); // Destrucción del vector
};

// Constructor dándose la medida
template<class T> vector_t<T>::vector_t(const int numero) { 
  sz_ = numero;
  build();
}

// Destructor del vector
template<class T> vector_t<T>::~vector_t() {
  destroy();
}

// Creación del vector
template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

//  Destrucción del vector
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

// Redefinición de la medida del vector
template<class T> void vector_t<T>::resize(const int numero) {
  destroy();    // Se destruye primero el vector
  sz_ = numero;
  build();      // Se crea de nuevo con la nueva medida
}

// Obtención del valor de un elemento del vector
template<class T> inline T vector_t<T>::get_val(const int elemento) const {
  assert(elemento >= 0 && elemento < get_size());
  return v_[elemento];
}

// Obtención de la medida de un elemento del vector
template<class T> inline int vector_t<T>::get_size() const {
  return sz_;
}

// Se actualiza el valor seleccionado
template<class T> void vector_t<T>::set_val(const int elemento, const T valor) {
  assert(elemento >= 0 && elemento < get_size());
  v_[elemento] = valor;
}

// Se actualiza el valor del elemento
template<class T> T& vector_t<T>::at(const int elemento) {
  assert(elemento >= 0 && elemento < get_size());
  return v_[elemento];
}

// Se actualiza el valor del elemento
template<class T> T& vector_t<T>::operator[](const int elemento) {
  return at(elemento);
}

// Se actualiza el valor del elemento
template<class T> const T& vector_t<T>::at(const int elemento) const {
  assert(elemento >= 0 && elemento < get_size());
  return v_[elemento];
}

// Se actualiza el valor del elemento
template<class T> const T& vector_t<T>::operator[](const int elemento) const {
  return at(elemento);
}

// Se imprime el vector
template<class T> void vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

// Se modifica el vector aportándose los valores
template<class T> void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
// Producto escalar de dos vectores
// Parámetros: dos vectores a usar
template<class T> T scal_prod(const vector_t<T>& vector_v, const vector_t<T>& vector_w) {
  assert(vector_v.get_size() == vector_w.get_size()); // Comprobamos que las medidas de ambos vectores son iguales
  double producto_escalar{0};
  for (int i{0}; i < vector_v.get_size(); ++i) {
    producto_escalar = producto_escalar + vector_v[i] * vector_w[i];
  }
  return producto_escalar;
}

// Prodcuto escalar de dos vectpres
// Parámetros: dos vectores a usar
double scal_prod(const vector_t<rational_t>& vector_v, const vector_t<rational_t>& vector_w) {
  assert(vector_v.get_size() == vector_w.get_size()); // Comprobamos que las medidas de ambos vectores son iguales
  double producto_escalar{0};
  for (int i{0}; i < vector_v.get_size(); ++i) {
    rational_t total{0,1};
    total = vector_v[i] * vector_w[i];
    producto_escalar = producto_escalar + total.value();
  }
  return producto_escalar;
}
