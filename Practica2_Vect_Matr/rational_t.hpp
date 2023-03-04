// AUTOR: Daniel Pérez Rodríguez
// FECHA: 2/02/2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

// Clase rational_t
// Crea objetos tipo número racional, a/b, donde a y b son números reales
// Contiene operaciones de comparación y aritméticas entre objetos de la clase
class rational_t {
  // pautas de estilos [44] y [73]: primero "public" y después "private"
 public:
  // Constructores
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  // Getters
  int get_num() const;  // Retorna el valor del numerador
  int get_den() const;  // Retorna el valor del denominador  
  // Setters
  void set_num(const int);  // Modifica el valor del numerador
  void set_den(const int);  //Modifica el valor del denominador
  // Métodos para obtener el valor del número en decimal
  double value(void) const; // Método para obtener el valor del número en decimal
  rational_t opposite(void) const; // Método para obetener el opuesto
  rational_t reciprocal(void) const;    // Método para obtener el recíproco

  bool is_equal(const rational_t&, const double precision = EPSILON) const; // Números iguales
  bool is_greater(const rational_t&, const double precision = EPSILON) const; // Número mayor que el otro demandado
  bool is_less(const rational_t&, const double precision = EPSILON) const; // Número menor que el otro demandado

  rational_t add(const rational_t&) const; // Suma de racionales
  rational_t substract(const rational_t&) const; //Resta de racionales
  rational_t multiply(const rational_t&) const; // Multiplicación de racionales
  rational_t divide(const rational_t&) const; // División de racionales

  void write(ostream& os = cout) const; // Imprime un número racional y su valor en tipo double
  void read(istream& is = cin); // Cambia el valor de un número racional mediante el flujo de entrada
  
 private:
  int num_, den_;
};

// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&); // Sobrecarga del operador de flujo de salida
istream& operator>>(istream& is, rational_t&); // Sobrecarga de operador de entrada

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&); // Sobrecargar operador de suma
rational_t operator-(const rational_t&, const rational_t&); // Sobrecargar operador de resta
rational_t operator*(const rational_t&, const rational_t&); // Sobrecargar operador de multiplicación
rational_t operator/(const rational_t&, const rational_t&); // Sobrecargar operador de división