// AUTOR: Antonio Ramos Castilla
// FECHA: 25/03/2022
// EMAIL: alu0101480367@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Formato Doxygen
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); 
  pair_t(T, int);
  // Destructor
  ~pair_t(void);
  // Getters
  T get_val(void) const;
  int get_inx(void) const;
  // Setters
  void set(T, int);
  // Métodos de escritura y lectura
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;
 private:
  // Atributos privados
  T val_;
  int inx_;
};

/**
 * @brief Constructor por defecto de la clase
 * @param void
 * @return void
 */
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

/**
 * @brief Constructor con parámetros de la clase
 * @param val
 * @param inx
 * @return void
 */
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

/**
 * @brief Destructor de la clase
 * @param void
 * @return void
 */
template<class T> pair_t<T>::~pair_t() {}

/**
 * @brief Setter de la clase
 * @param val
 * @param inx
 * @return void
 */
template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

/**
 * @brief Getter de inx_
 * @param void
 * @return inx_
 */
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

/**
 * @brief Getter de val_
 * @param void
 * @return val_
 */
template<class T> T pair_t<T>::get_val() const {
  return val_;
}

/**
 * @brief Método de lectura de pair_t
 * @param is
 * @return is
 */
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

/**
 * @brief Método de escritura de pair_t
 * @param os
 * @return os
 */
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

/**
 * @brief Sobrecarga del operador <<
 * @param os
 * @param p
 * @return os
 */
template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
