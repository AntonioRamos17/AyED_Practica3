// AUTOR: Antonio Ramos Castilla
// FECHA: 25/03/2022
// EMAIL: alu0101480367@ull.edu.es 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Formato Doxygen
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // Constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia
  // Destructor
  ~Polynomial() {};
  // Método de escritura de polinomios
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  // Operaciones y comparaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // Constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia
  // Destructor
  ~SparsePolynomial() {};
  // Método de escritura de polinomios
  void Write(std::ostream& = std::cout) const;
  // Operaciones y comparaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// Métodos de entrada/salida

/**
 * @brief Método de escritura de polinomios
 * @param os
 * @param eps
 * @return void
 */
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

/**
 * @brief Sobrecarga del operador <<
 * @param os
 * @param p
 * @return os
 */
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

/**
 * @brief Evaluación de un polinomio representado por vector denso
 * @param x
 * @return result
 */
double Polynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  return result;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vectores densos
 * @param pol
 * @param eps
 * @return !differents
 */
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  return !differents;
}

/**
 * @brief Constructor de copia
 * @param spol
 * @return void
 */
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// Métodos de entrada/salida polinomio escaso

/**
 * @brief Método de escritura de polinomios escasos
 * @param os
 * @return void
 */
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

/**
 * @brief Sobrecarga del operador de <<
 * @param os
 * @param p
 * @return os
 */
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios escasos

/**
 * @brief Evaluación de un polinomio representado por vector disperso 
 * @param x
 * @return result
 */
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  return result;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vectores dispersos
 * @param spol
 * @param eps
 * @return !differents
 */
// 
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false;
  // poner el código aquí
  return !differents;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vector disperso y vector denso.
 * @param pol
 * @param eps
 * @return !differents
 */
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  return !differents;
}


#endif  // POLYNOMIAL_H_
