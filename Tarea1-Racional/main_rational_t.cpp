// AUTOR: Daniel Pérez Rodríguez
// FECHA: 16-02-2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

using namespace std;

int main() {
  RationalT numero_a(1, 2), numero_b(3), numero_c;
  // Imprimimos los valores de los números racionales que tenemos
  cout << "numero_a.value() = " << numero_a.Value() << endl;
  cout << "numero_b.value() = " << numero_b.Value() << endl;
  cout << "numero_c.value() = " << numero_c.Value() << endl;
  cout << "numero_a: ";
  numero_a.Write();
  cout << "numero_b: ";
  // Aportamos el numerador y denominador que queremos que tenga nuestro número c
  numero_b.Write();
  numero_c.Read();
  cout << "numero_c: ";
  numero_c.Write();

  // FASE II
  RationalT numero_x(1, 3), numero_y(1, 3);
  numero_x.Write();
  numero_y.Write();
  // Comparamos los numeros racionales conocidos como numero_x y numero_y
  cout << "numero_x == numero_y? " << (numero_x.IsEqual(numero_y) ? "true" : "false") << endl;
  cout << "numero_x < numero_y? " << (numero_x.IsGreater(numero_y) ? "true" : "false") << endl;
  cout << "numero_x > numero_y? " << (numero_x.IsLess(numero_y) ? "true" : "false") << endl;

  // FASE III
  // Realizamos ciertas operaciones con los números que teníamos desde el principio
  cout << "numero_a + numero_b = ";
  numero_a.Add(numero_b).Write();
  cout << "numero_b - numero_a = ";
  numero_b.Substract(numero_a).Write();
  cout << "numero_a * numero_b = ";
  numero_a.Multiply(numero_b).Write();
  cout << "numero_a / numero_b = ";
  numero_a.Divide(numero_b).Write();

  // Probamos la funcionalidad de la modificación
  numero_c.Write();
  cout << "¿El número es entero? " << (numero_c.is_integer() ? "Sí" : "No") << endl;
  return 0;
}