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
#include <math.h>  /// fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

/// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  /// Constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia
  /// Destructor
  ~Polynomial() {};
  /// Método de escritura de polinomios
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  /// Operaciones y comparaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  /// MÉTODOS ADICIONALES
  Polynomial SumaPolinomios(const Polynomial& pol);
  double SumaCoeficientes();
  Polynomial RestaPolinomios(const Polynomial& pol);
  Polynomial Multiplicacion(const int& escalar);
  void CadenaConsecutiva() const;
};


/// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  /// Constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia
  /// Destructor
  ~SparsePolynomial() {};
  /// Método de escritura de polinomios
  void Write(std::ostream& = std::cout) const;
  /// Operaciones y comparaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  /// MÉTODOS ADICIONALES
  int SumaIndices() const;
  double MostrarCoeficiente(const int& n);
  void MuestraCeros() const;
};

/// Métodos de entrada/salida

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

/// Operaciones con polinomios

/**
 * @brief Evaluación de un polinomio representado por vector denso
 * @param x
 * @return result
 */
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int contador = 0; contador < get_size(); contador++) {
    result = result + (at(contador) * (pow(x, contador)));
  }
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
  int suma{0};
  if (get_size() > pol.get_size()) {
    for (int contador = 0; contador < pol.get_size(); ++contador) {
      if (get_val(contador) != pol.get_val(contador)) {
        differents = true;
      }
    }
    for (int contador2 = pol.get_size(); contador2 < get_size(); ++contador2){
      suma += at(contador2);
      if (suma != 0) {
        differents = true;
        break;
      }
    }
  } else {
    for (int contador = 0; contador < get_size(); ++contador) {
      if (get_val(contador) != pol.get_val(contador)) {
        differents = true;
      }
    }
    for (int contador2 = get_size(); contador2 < pol.get_size(); ++contador2){
      suma += pol.at(contador2);
      if (suma != 0) {
        differents = true;
        break;
      }
    }
  }
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

/// Métodos de entrada/salida polinomio escaso

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

/// Operaciones con polinomios escasos

/**
 * @brief Evaluación de un polinomio representado por vector disperso 
 * @param x
 * @return result
 */
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int contador = 0; contador < get_nz(); contador++) {
    result = result + (at(contador).get_val() * (pow(x, at(contador).get_inx())));
  }
  return result;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vectores dispersos
 * @param spol
 * @param eps
 * @return !differents
 */
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  bool differents = false;
  if (fabs(get_nz() - spol.get_nz()) > eps) { return differents; }
  for (int contador = 0; contador < get_nz(); ++contador) {
    if (at(contador).get_val() != spol.at(contador).get_val()) {
      differents = true;
    }
  }
  return !differents;
}

int Conversor(const Polynomial& pol) {
  int tamanyo_real = 0;
  for (int i = 0; i < pol.get_size(); ++i) {
    if (pol.at(i) != 0) {
      ++tamanyo_real;
    }
  }
  return tamanyo_real;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vector disperso y vector denso.
 * @param pol
 * @param eps
 * @return !differents
 */
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  if (get_nz() != Conversor(pol)) {
    differents = true;
  } else { 
    for (int contador = 0; contador < get_nz(); ++contador) {
      if (at(contador).get_val() != pol[at(contador).get_inx()]) {
        differents = true;
      }
    }
  }
  return !differents;
}






/// MÉTODOS ADICIONALES

/**
 * @brief Suma los índices de un polinomio disperso
 * @param void
 * @return suma
 */
int SparsePolynomial::SumaIndices() const {
  int suma{0};
  for (int i = 0; i < get_nz(); ++i) {
    suma += at(i).get_inx();
  }
  return suma;
}

/**
 * @brief Suma dos polinomios
 * @param pol
 * @return result
 */
Polynomial Polynomial::SumaPolinomios(const Polynomial& pol) {
  Polynomial result;
  if (get_size() > pol.get_size()) {
    result = *this;
    for (int i = 0; i < pol.get_size(); ++i) {
      result.at(i) += pol.at(i);
    }
  } else {
    result = pol;
    for (int j = 0; j < get_size(); ++j) {
      result.at(j) += at(j);
    }
  }
  return result;
}

/**
 * @brief Suma los coeficientes de un polinomio
 * @param void
 * @return suma
 */
double Polynomial::SumaCoeficientes() {
  double suma{0.0};
  for (int i = 0; i < get_size(); ++i) {
    suma += at(i);
  }
  return suma;
}

/**
 * @brief Muestra el coeficiente de un polinomio disperso dado su índice
 * @param i
 * @return numero
 */
double SparsePolynomial::MostrarCoeficiente(const int& n) {
  double numero{0};
  for (int i = 0; i < get_nz(); ++i) {
    if (at(i).get_inx() == n) {
      numero = at(i).get_val();
    }
  }
  return numero;
}

/**
 * @brief Resta dos polinomios
 * @param pol
 * @return result
 */
Polynomial Polynomial::RestaPolinomios(const Polynomial& pol) {
  Polynomial result;
  if (get_size() >= pol.get_size()) {
    result.resize(get_size());
    int i{0};
    for (i = 0; i < pol.get_size(); ++i) {
      result.at(i) = at(i) - pol.at(i);
    }
    for (int k = i; k < get_size(); ++k) {
      result.at(k) = at(k);
    }
  } else if (pol.get_size() > get_size()) {
    result.resize(pol.get_size());
    int j{0};
    for ( j = 0; j < get_size(); ++j) {
      result.at(j) = at(j) - pol.at(j);
    }
    for (int z = j; z < get_size(); ++z) {
      result.at(z) = -pol.at(z);
    }
  }
  return result;
}

/**
 * @brief Multiplicación de un escalar por un polinomio
 * @param n
 * @return result
 */
Polynomial Polynomial::Multiplicacion(const int& escalar) {
  Polynomial result;
  result.resize(get_size());
  for (int i = 0; i < get_size(); ++i) {
    result.at(i) = escalar * at(i);
  }
  return result;
}

/**
 * @brief Método que muestra los 0 de un polinomio disperso
 * @param void
 * @return result
 */
void SparsePolynomial::MuestraCeros() const {
  vector_t<int> v;
  v.resize(get_n());
  for (int i = 0; i < get_nz(); ++i) {
    v.at(at(i).get_inx()) = 1;
  }
  for (int j = 0; j < v.get_size(); ++j) {
    if (v.at(j) == 0) {
      std::cout <<  "0x^" << j << " ";
    }
  }
}

/**
 * @brief Método que muestra índices consecutivos de un polinomio
 * @param void
 * @return void
 */
void Polynomial::CadenaConsecutiva() const {
  for (int i = 1; i < get_size(); ++i) {
    if (at(i - 1) != 0 && at(i) != 0) {
      std::cout << get_val(i - 1) << "x^" << i - 1 << "<-->";
      std::cout << get_val(i) << "x^" << i << std::endl;
    }
  }
}

#endif  /// POLYNOMIAL_H_
