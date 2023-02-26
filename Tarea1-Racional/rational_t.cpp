// AUTOR: Daniel Pérez Rodríguez
// FECHA: 16-02-2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1

#include "rational_t.hpp"

// Constructor dado numerador y denominador
// Parámetros: numerador y denominador
RationalT::RationalT(const int numerador, const int denominador) {
  assert(denominador != 0);
  numerador_ = numerador, denominador_ = denominador;
}

// Getter de obtención de numerador
int RationalT::GetNumerador() const {
  return numerador_;
}

// Getter de obtención de denominador
int RationalT::GetDenominador() const {
  return denominador_;
}

// Setter del numerador
// Parámetro: numerador del número racional
void RationalT::SetNumerador(const int numerador) {
  numerador_ = numerador;
}

// Setter del denominador
// Parámetro: denominador del número racional, que no puede ser 0
void RationalT::SetDenominador(const int denominador) {
  assert(denominador != 0);
  denominador_ = denominador;
}

// Método para la obtención del valor en tipo double del número racional
double RationalT::Value() const { 
  return double(GetNumerador()) / GetDenominador();
}

// Comparaciones
// Compara si el valor de un número racional a es igual a uno b
// Se debe dar que |a−b|<ϵ 
// Parámetros: número racional a evaluar y ϵ
bool RationalT::IsEqual(const RationalT& racional, const double kPrecision) const { 
  if (fabs(Value() - racional.Value()) < kPrecision) {
    return true;
  }
  return false;
}

// Compara si el valor de un número racional a es mayor que uno b
// Se debe dar que a−b>ϵ
// Parámetros: número racional a evaluar y ϵ
bool RationalT::IsGreater(const RationalT& racional, const double kPrecision) const {
  if ((Value() - racional.Value()) > kPrecision) {
    return true;
  }
  return false;
}

// Compara si el valor de un número racional a es menor que uno b
// Se debe dar que b−a>ϵ
// Parámetros: número racional a evaluar y ϵ
bool RationalT::IsLess(const RationalT& racional, const double kPrecision) const {
  if ((racional.Value() - (Value())) > kPrecision) {
    return true;
  }
  return false;
}

// Operaciones
// Suma de racionales
// Parámetro: número que se suma
RationalT RationalT::Add(const RationalT& racional) {
  return racional.GetNumerador() + numerador_, racional.GetDenominador() + denominador_;
}

// Resta de racionales
// Parámetro: número que se resta
RationalT RationalT::Substract(const RationalT& racional) {
  return racional.GetNumerador() - numerador_, racional.GetDenominador() - denominador_;
}

// Multiplicación de racionales
// Parámetro: número que se multiplica
RationalT RationalT::Multiply(const RationalT& racional) {
  return racional.GetNumerador() * numerador_, racional.GetDenominador() * denominador_;
}

// División de racionales
// Parámetro: número por el que se divide
RationalT RationalT::Divide(const RationalT& racional) {
  return racional.GetNumerador() * denominador_, racional.GetDenominador() * numerador_;
}

// Comprobación si el número racional es entero
// Si el resto del numerador entre el denominador es 0, se comprobaría que es entero
bool RationalT::is_integer() const {
  return (GetNumerador() % GetDenominador() == 0);
}

// Método para imprimir el número racional y su valor en tipo double
// Parámetro: flujo de salida
void RationalT::Write(ostream& out) const {
  out << GetNumerador() << " / " << GetDenominador() << " = " << Value() << endl;
}

// Método para insertar los valores de un número racional
// Parámetro: flujo de entrada
void RationalT::Read(istream& in) {
  cout << "Numerador? ";
  in >> numerador_;
  cout << "Denominador? ";
  in >> denominador_;
  assert(denominador_ != 0);    // Se comprueba que el denominador no es 0
}