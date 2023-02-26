// AUTOR: Daniel Pérez Rodríguez
// FECHA: 16-02-2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

// Clase RacionalT
// Crea objetos tipo número racional, a/b, donde a y b son números reales
// Contiene operaciones de comparación y aritméticas entre objetos de la clase
class RationalT {
 public:
  // Constructores
  RationalT(const int = 0, const int = 1);
  ~RationalT() {} 
  // Getters
  int GetNumerador() const;   // Retorna el valor del numerador
  int GetDenominador() const;   // Retorna el valor del denominador  
  // Setters
  void SetNumerador(const int);   // Modifica el valor del numerador
  void SetDenominador(const int);   //Modifica el valor del denominador
  // Método para obtener el valor del número en decimal
  double Value(void) const;

  // FASE II
  bool IsEqual(const RationalT&, const double kPrecision = EPSILON) const;  // Números iguales
  bool IsGreater(const RationalT&, const double kPrecision = EPSILON) const; // Número mayor que el otro demandado
  bool IsLess(const RationalT&, const double kPrecision = EPSILON) const;  // Número menor que el otro demandado
  
  // FASE III
  RationalT Add(const RationalT&);    // Suma de racionales
  RationalT Substract(const RationalT&);    //Resta de racionales
  RationalT Multiply(const RationalT&);     // Multiplicación de racionales
  RationalT Divide(const RationalT&);   // División de racionales

  // Comprobación de entero
  bool is_integer(void) const;
  
  // Métodos de entrada / salida
  void Write(ostream& = cout) const;    // Imprime un número racional y su valor en tipo double
  void Read(istream& = cin);    // Cambia el valor de un número racional mediante el flujo de entrada
 private:
  int numerador_, denominador_;
};