#include "Ordenamiento.hpp"
#include <cstdlib>
#include <ctime>

Ordenamiento::Ordenamiento() {}

void Ordenamiento::initOrdenado(int array[]) {
  for (int i = 0; i < MAX; i++) {
    array[i] = i;
  }
}

void Ordenamiento::initDesordenado(int array[]) {
  initOrdenado(array);

  srand(static_cast<unsigned>(time(0)));
  for (int i = MAX - 1; i > 0; i--) {
    int j = rand() % (i + 1); // Selecciona un indice aleatorio entre 0 y i
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void Ordenamiento::initOrdenadoInv(int array[]) {
  for (int i = 0; i < MAX; i++) {
    array[i] = MAX - 1 - i;
  }
}

void Ordenamiento::insercion(int coleccion[]) {
  int i, j;

  for (i = 1; i < MAX; i++) {
    int temp = coleccion[i];
    j = i - 1;

    while (j >= 0 && coleccion[j] > temp) {
      coleccion[j + 1] = coleccion[j];
      j--;
    }
    coleccion[j + 1] = temp;
  }
}
void Ordenamiento::burbuja(int array[]) {
  int i, j;

  for (i = 0; i < MAX - 1; i++) {
    for (j = 0; j < MAX - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int t = array[j];
        array[j] = array[j + 1];
        array[j + 1] = t;
      }
    }
  }
}

void Ordenamiento::seleccion(int coleccion[]) {
  int i, j;

  for (i = 0; i < MAX - 1; i++) {
    int select = i;
    for (j = i + 1; j < MAX; j++) {
      if (coleccion[select] > coleccion[j]) {
        select = j;
      }
    }

    int t = coleccion[i];
    coleccion[i] = coleccion[select];
    coleccion[select] = t;
  }
}

void Ordenamiento::shellSort(int coleccion[]) {
  int gap, i, j;

  for (gap = MAX / 2; gap > 0; gap /= 2) {
    for (i = gap; i < MAX; i++) {
      for (j = i - gap; j >= 0 && coleccion[j] > coleccion[j + gap]; j -= gap) {
        int t = coleccion[j];
        coleccion[j] = coleccion[j + gap];
        coleccion[j + gap] = t;
      }
    }
  }
}

void Ordenamiento::quickSort(int coleccion[]) {}
