// AUTOR: Antonio Ramos Castilla
// FECHA: 25/03/2022
// EMAIL: alu0101480367@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Formato Doxygen
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class vector_t {
 public:
  /// Constructores
  vector_t(const int = 0);
  vector_t(const vector_t&); // constructor de copia
  /// Sobrecarga del operador de asignación
  vector_t<T>& operator=(const vector_t<T>&);
  // Destructor
  ~vector_t();
  /// Getters
  T get_val(const int) const;
  int get_size(void) const;
  /// Setters
  void set_val(const int, const T);
  // Getters-setters
  T& at(const int);
  T& operator[](const int);
  /// Getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;
  /// Redimensionado del vector
  void resize(const int);
  // Métodos de escritura y lectura del vector
  void read(std::istream& = std::cin);
  void write(std::ostream& = std::cout) const;
 private:
  /// Atributos privados
  T *v_;
  int sz_;
  /// Métodos privados
  void build(void);
  void destroy(void);
};

/**
 * @brief Constructor de la clase vector
 * @param n
 * @return void
 */
template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

/**
 * @brief Constructor de copia
 * @param w
 * @return void
 */
template<class T> vector_t<T>::vector_t(const vector_t<T>& w)
    : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

/**
 * @brief Operador de asignación
 * @param w
 * @return *this
 */
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

/**
 * @brief Destructor de la clase
 * @param void
 * @return void
 */
template<class T> vector_t<T>::~vector_t() {
  destroy();
}

/**
 * @brief Metodo de construcción de vectores
 * @param void
 * @return void
 */
template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

/**
 * @brief Método para eliminar vectores
 * @param void
 * @return void
 */
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

/**
 * @brief Método para redimensionar vectores
 * @param n
 * @return void
 */
template<class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

/**
 * @brief Getter del valor de un elemento en cierta posición (i).
 * @param i
 * @return v_[i]
 */
template<class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Getter del tamaño del vector
 * @param void
 * @return sz_
 */
template<class T> inline int vector_t<T>::get_size() const {
  return sz_;
}

/**
 * @brief Setter del valor de un elemento
 * @param i
 * @param d
 * @return void
 */
template<class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/**
 * @brief Método para referirse a la posición de un elemento
 * @param i
 * @return v_[i]
 */
template<class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Sobrecarga del operador []
 * @param i
 * @return at(i)
 */
template<class T> T& vector_t<T>::operator[](const int i) {
  return at(i);
}

/**
 * @brief Método constante para referirse a la posición de un elemento
 * @param i
 * @return v_[i]
 */
template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Sobrecarga constante del operador []
 * @param i
 * @return at(i)
 */
template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

/**
 * @brief Método de lectura de vectores
 * @param is
 * @return void
 */
template<class T> void vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

/**
 * @brief Método de escritura de vectores
 * @param os
 * @return void
 */
template<class T> void vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

/**
 * @brief Sobrecarga del operador >>
 * @param is
 * @param v
 * @return is
 */
template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) {
  v.read(is);
  return is;
}

/**
 * @brief Sobrecarga del operador <<
 * @param os
 * @param v
 * @return os
 */
template<class T> std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) {
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
