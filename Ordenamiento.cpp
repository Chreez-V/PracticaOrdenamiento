#include "Ordenamiento.hpp"
#include <cstdlib>
#include <ctime>

Ordenamiento::Ordenamiento() {}

void Ordenamiento::initOrdenado() {
  for (int i = 0; i < MAX; i++) {
    array[i] = i;
  }
}

void Ordenamiento::initDesordenado() {
  initOrdenado();

  srand(static_cast<unsigned>(time(0)));
  for (int i = 29999; i > 0; i--) {
    int j = rand() % (i + 1); // Selecciona un indice aleatorio entre 0 y i
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void Ordenamiento::initOrdenadoInv() {
  for (int i = 0; i < MAX; i++) {
    array[i] = 29999 - i;
  }
}

void Ordenamiento::insercion(int *coleccion[]) {
  int i, j;

  for (i = 1; i < MAX; i++) {
    for (j = i; j > 0 && coleccion[j] < coleccion[j - i]; j--) {
      int *t; // intercambiar
      t = coleccion[j];
      coleccion[j] = coleccion[j - i];
      coleccion[j - i] = t;
    }
  }
}
void Ordenamiento::Queso() {
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
  cout << "telita" << endl;
}
void Ordenamiento::seleccion(int *coleccion[]) {
  int e, i, j;

  for (i = 0; i < MAX - 1; i++) {
    e = i;
    for (j = i + 1; j < MAX; i++) {
      if (coleccion[e] > coleccion[j]) {
        e = j;
      } else if (i != e) {
        int *t;
        t = coleccion[i];
        coleccion[i] = coleccion[e];
        coleccion[e] = t;
      }
    }
  }
}
int *Ordenamiento::getArray() { return array; }
