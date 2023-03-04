// AUTOR: Daniel Pérez Rodríguez
// FECHA: 2/02/2023
// EMAIL: alu0101541006@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2

#include "rational_t.hpp"

// Constructor dado numerador y denominador
// Parámetros: numerador y denominador
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

// Getter de obtención de numerador
inline int rational_t::get_num() const {
  return num_;
}

// Getter de obtención de denominador
inline int rational_t::get_den() const {
  return den_;
}

// Setter del numerador
// Parámetro: numerador del número racional
void rational_t::set_num(const int n) {
  num_ = n;
}

// Setter del denominador
// Parámetro: denominador del número racional, que no puede ser 0
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

// Método para la obtención del valor en tipo double del número racional
inline double rational_t::value() const { 
  return double(get_num()) / get_den();
}

// Método para comprobar retornar el número inverso
rational_t  rational_t::opposite() const { 
  return rational_t((-1)*get_num(), get_den());
}

// Método oara devolver el recíproco
rational_t rational_t::reciprocal() const { 
  return rational_t(get_den(), get_num());
}

// Comparaciones
// Compara si el valor de un número racional a es igual a uno b
// Se debe dar que |a−b|<ϵ 
// Parámetros: número racional a evaluar y ϵ
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}


// Compara si el valor de un número racional a es mayor que uno b
// Se debe dar que a−b>ϵ
// Parámetros: número racional a evaluar y ϵ
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}

// Compara si el valor de un número racional a es menor que uno b
// Se debe dar que b−a>ϵ
// Parámetros: número racional a evaluar y ϵ
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}

// Operaciones
// Suma de racionales
// Parámetro: número que se suma
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}

// Resta de racionales
// Parámetro: número que se resta
rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}

// Multiplicación de racionales
// Parámetro: número que se multiplica
rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}


// División de racionales
// Parámetro: número por el que se divide
rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}

// FASE I: operadores
// Sobrecarga de operador de suma
// Parámetros: dos números racionales a sumar
rational_t operator+(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_den() + b.get_num() * a.get_den(),
                    a.get_den() * b.get_den());
}

// Sobrecarga de operador de resta
// Parámetros: dos números racionales a restar
rational_t operator-(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_den() - b.get_num() * a.get_den(),
                    a.get_den() * b.get_den());
}

// Sobrecarga de operador de multiplicar
// Parámetros: dos números racionales a multiplicar
rational_t operator*(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_num(), a.get_den() * b.get_den());
}

// Sobrecarga de operador de dividir
// Parámetros: dos números racionales a dividir
rational_t operator/(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_den(), a.get_den() * b.get_num());
}

// E/S
// Método para imprimir el número racional y su valor en tipo double
// Parámetro: flujo de salida
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

// Método para insertar los valores de un número racional
// Parámetro: flujo de entrada
void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}

// Sobrecarga de operador de flujo de salida
// Parámetros: número racional a imprimir y flujo de salida
ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

// Sobrecarga de operador de flujo de entrada
// Parámetros: número racional a cambiar y flujo de entrada
istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}