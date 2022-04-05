// AUTOR: Antonio Ramos Castilla
// FECHA: 25/03/2022
// EMAIL: alu0101480367@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Formato Doxygen
// COMPILACIÓN: g++ -g main_polynomial.cc -o main_polynomial
// EJECUCIÓN: ./main_polynomial < data_polynomial.txt

#include <iostream>

#include "polynomial.h"


int main() {
  Polynomial p1, p2, p3;
  
  std::cin >> p1 >> p2 >> p3;
  std::cout << "p1= " << p1;
  std::cout << "p2= " << p2;
  std::cout << "p3= " << p3;
  std::cout << std::endl;

  /// Fase II
  SparsePolynomial sp1(p1), sp2(p2), sp3(p3);
  std::cout << "sp1= " << sp1;
  std::cout << "sp2= " << sp2;
  std::cout << "sp3= " << sp3;
  std::cout << std::endl;

  /// Fase III
  double x1, x2, x3;
  std::cin >> x1 >> x2 >> x3;
  std::cout << "p1(" << x1 << ")= " << p1.Eval(x1) << std::endl;
  std::cout << "p1(" << x2 << ")= " << p1.Eval(x2) << std::endl;
  std::cout << "p1(" << x3 << ")= " << p1.Eval(x3) << std::endl;
  std::cout << "p2(" << x1 << ")= " << p2.Eval(x1) << std::endl;
  std::cout << "p2(" << x2 << ")= " << p2.Eval(x2) << std::endl;
  std::cout << "p2(" << x3 << ")= " << p2.Eval(x3) << std::endl;
  std::cout << "p3(" << x1 << ")= " << p3.Eval(x1) << std::endl;
  std::cout << "p3(" << x2 << ")= " << p3.Eval(x2) << std::endl;
  std::cout << "p3(" << x3 << ")= " << p3.Eval(x3) << std::endl;
  std::cout << std::endl;

  std::cout << "sp1(" << x1 << ")= " << sp1.Eval(x1) << std::endl;
  std::cout << "sp1(" << x2 << ")= " << sp1.Eval(x2) << std::endl;
  std::cout << "sp1(" << x3 << ")= " << sp1.Eval(x3) << std::endl;
  std::cout << "sp2(" << x1 << ")= " << sp2.Eval(x1) << std::endl;
  std::cout << "sp2(" << x2 << ")= " << sp2.Eval(x2) << std::endl;
  std::cout << "sp2(" << x3 << ")= " << sp2.Eval(x3) << std::endl;
  std::cout << "sp3(" << x1 << ")= " << sp3.Eval(x1) << std::endl;
  std::cout << "sp3(" << x2 << ")= " << sp3.Eval(x2) << std::endl;
  std::cout << "sp3(" << x3 << ")= " << sp3.Eval(x3) << std::endl;
  std::cout << std::endl;

  /// Fase IV
  std::cout << "p1 == p1? " << (p1.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "p2 == p2? " << (p2.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "p3 == p3? " << (p3.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "p1 == p2? " << (p1.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "p2 == p1? " << (p2.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "p1 == p3? " << (p1.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "p3 == p1? " << (p3.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "p2 == p3? " << (p2.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "p3 == p2? " << (p3.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << std::endl;

  std::cout << "sp1 == sp1? " << (sp1.IsEqual(sp1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == sp2? " << (sp2.IsEqual(sp2) ? "true" : "false") << std::endl;
  std::cout << "sp3 == sp3? " << (sp3.IsEqual(sp3) ? "true" : "false") << std::endl;
  std::cout << "sp1 == sp2? " << (sp1.IsEqual(sp2) ? "true" : "false") << std::endl;
  std::cout << "sp2 == sp1? " << (sp2.IsEqual(sp1) ? "true" : "false") << std::endl;
  std::cout << "sp1 == sp3? " << (sp1.IsEqual(sp3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == sp1? " << (sp3.IsEqual(sp1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == sp3? " << (sp2.IsEqual(sp3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == sp2? " << (sp3.IsEqual(sp2) ? "true" : "false") << std::endl;
  std::cout << std::endl;

  std::cout << "sp1 == p1? " << (sp1.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == p2? " << (sp2.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "sp3 == p3? " << (sp3.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "sp1 == p2? " << (sp1.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "sp2 == p1? " << (sp2.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "sp1 == p3? " << (sp1.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == p1? " << (sp3.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == p3? " << (sp2.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == p2? " << (sp3.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << std::endl;

  /// MÉTODOS ADICIONALES

  std::cout << "MÉTODOS ADICIONALES" << std::endl;
  std::cout << std::endl;

  /// Suma de los índices de un sparse_polynomial
  std::cout << "Suma de los índices de sp1: " << sp1.SumaIndices() << std::endl;
  std::cout << "Suma de los índices de sp2: " << sp2.SumaIndices() << std::endl;
  std::cout << "Suma de los índices de sp3: " << sp3.SumaIndices() << std::endl;
  std::cout << std::endl;

  /// Suma de dos polynomios
  std::cout << "p1 + p2 = " << p1.SumaPolinomios(p2);
  std::cout << "p2 + p3 = " << p2.SumaPolinomios(p3);
  std::cout << "p1 + p3 = " << p1.SumaPolinomios(p3);
  std::cout << std::endl;

  /// Suma de coeficientes de polinomios
  std::cout << "La suma de los coeficientes de p1 es: " << p1.SumaCoeficientes() << std::endl;
  std::cout << "La suma de los coeficientes de p2 es: " << p2.SumaCoeficientes() << std::endl;
  std::cout << "La suma de los coeficientes de p3 es: " << p3.SumaCoeficientes() << std::endl;
  std::cout << std::endl;

  /// Mostrar el coeficiente dado el índice
  std::cout << "El coeficiente de sp1 cuyo índice es 5 es: " << sp1.MostrarCoeficiente(5) << std::endl;
  std::cout << "El coeficiente de sp2 cuyo índice es 8 es: " << sp2.MostrarCoeficiente(8) << std::endl;
  std::cout << "El coeficiente de sp3 cuyo índice es 9 es: " << sp3.MostrarCoeficiente(9) << std::endl;
  std::cout << std::endl;

  /// Resta de polinomios
  std::cout << "p1 - p2 = " << p1.RestaPolinomios(p2);
  std::cout << "p2 - p3 = " << p2.RestaPolinomios(p3);
  std::cout << std::endl;
  std::cout << std::endl;

  /// Multiplicación de un escalar por un polinomio
  std::cout << "p1 x 5 = " << p1.Multiplicacion(5) << std::endl;
  std::cout << "p2 x 6 = " << p2.Multiplicacion(6) << std::endl;
  std::cout << "p3 x 3 = " << p3.Multiplicacion(3) << std::endl;
  std::cout << std::endl;

  return 0;
}
