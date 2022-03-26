// AUTOR: Antonio Ramos Castilla
// FECHA: 25/03/2022
// EMAIL: alu0101480367@ull.edu.es 
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Formato Doxygen
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t {
 public:
  // Constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&,
		  const double = EPS); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  // Sobrecarga del operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);
  // Destructor
  ~sparse_vector_t();
  // Getters
  int get_nz(void) const;
  int get_n(void) const;
  // Getters-Setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  // Getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;
  // Método de escritura de vectores escasos
  void write(std::ostream& = std::cout) const;
 private:
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};

/**
 * @brief Método para comparar que no sea 0
 * @param val
 * @param eps
 * @return true/false
 */
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

/**
 * @brief Constructor por defecto de la clase
 * @param n
 * @return void
 */
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {
}

// FASE II

/**
 * @brief Constructor con parámetros de la clase
 * @param v
 * @param eps
 * @return void
 */
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps)
    : pv_(), nz_(0), n_(0) {
  // poner el código aquí
}

/**
 * @brief Constructor de copia
 * @param w
 * @return void
 */
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

/**
 * @brief Operador de asignación
 * @param w
 * @return *this
 */
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

/**
 * @brief Destructor de la clase
 * @param void
 * @return void
 */
sparse_vector_t::~sparse_vector_t() {
}

/**
 * @brief Getter del número de valores distintos a 0
 * @param void
 * @return nz_
 */
inline int sparse_vector_t::get_nz() const {
  return nz_;
}

/**
 * @brief Getter del número de elementos del vector
 * @param void
 * @return n_
 */
inline int sparse_vector_t::get_n() const {
  return n_;
}

/**
 * @brief Método para referirse a la posición de un elemento
 * @param i 
 * @return pv_[i]
 */
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Sobrecarga del operador []
 * @param i
 * @return at(i)
 */
pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

/**
 * @brief Método constante para referirse a la posición de un elemento
 * @param i
 * @return pv_[i]
 */
const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Sobrecarga constante del operador []
 * @param i
 * @return at(i)
 */
const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

// Métodos de entrada/salida

/**
 * @brief Método de escritura de vectores escasos
 * @param os
 * @return void
 */
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

/**
 * @brief Sobrecarga del operador << 
 * @param os
 * @param sv
 * @return os
 */
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
