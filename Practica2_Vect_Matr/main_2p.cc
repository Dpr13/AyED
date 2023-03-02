// AUTOR: Daniel Pérez Rodríguez
// FECHA: 2/02/2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2

#include <iostream>
#include <cmath>

#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

using namespace std;

int main() {
  // Inicializamos dos números racionales
  rational_t a(1, 2), b(3);

  // FASE I
  // Se realizan ciertas operaciones con estos números, que se imprimen
  cout << "a + b: ";
  (a+b).write();
  cout << "b - a: ";
  (b-a).write();
  cout << "a * b: ";
  (a*b).write();
  cout << "a / b: ";
  (a/b).write();
  cout << endl;
  
  // FASE II
  // Se inicializan dos vectores
  vector_t<double> v, w;
  v.read(), v.write(); 
  w.read(), w.write();
  // Producto escalar de los vectores creados anteriormente
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  // Se crea vector de números racionales
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  // Producto escalar de los vectores de números racionales
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;
  
  // FASE III
  // Se crean tres matrices
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  // Producto matricial de las dos primeras matrices queda en la matriz C
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write(); 
  return 0;
}
