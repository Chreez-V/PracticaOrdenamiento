#include "Ordenamiento.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <ostream>

/**
 * Esta clase esta constituida por todos los algoritmos de ordenamiento
 */

Ordenamiento::Ordenamiento() {}

/**
 * @brief
 * Este metodo Ordena el array
 * @param array
 */
void Ordenamiento::initOrdenado(int array[]) {
  for (int i = 0; i < MAX; i++) {
    array[i] = i;
  }
}
/**
 * @brief
 * Este metodo desordena el array
 * @param array
 */
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

/**
 * @brief
 * Este metodo invierte el array ordenado
 * @param array
 */
void Ordenamiento::initOrdenadoInv(int array[]) {
  for (int i = 0; i < MAX; i++) {
    array[i] = MAX - 1 - i;
  }
}

/**
 * @brief Construct a new
 * std::chrono::duration<float,milli>Ordenamiento::insercion object Ordenamiento
 * por el algoritmo de insercion
 * @param coleccion
 * @return std::chrono::duration<float,milli>
 */
std::chrono::duration<float, milli> Ordenamiento::insercion(int coleccion[]) {
  int i, j;
  auto start = std::chrono::system_clock::now();

  for (i = 1; i < MAX; i++) {
    int temp = coleccion[i];
    j = i - 1;

    while (j >= 0 && coleccion[j] > temp) {
      coleccion[j + 1] = coleccion[j];
      j--;
    }
    coleccion[j + 1] = temp;
  }

  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, milli> elapsed_seconds = (end - start);

  return elapsed_seconds;
}

/**
 * @brief Construct a new
 * std::chrono::duration<float,milli>Ordenamiento::burbuja object Ordenamiento
 * por el algoritmo de burbuja
 * @param array
 * @return std::chrono::duration<float,milli>
 */
std::chrono::duration<float, milli> Ordenamiento::burbuja(int array[]) {
  int i, j;
  auto start = std::chrono::system_clock::now();

  for (i = 0; i < MAX - 1; i++) {
    for (j = 0; j < MAX - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int t = array[j];
        array[j] = array[j + 1];
        array[j + 1] = t;
      }
    }
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, milli> elapsed_seconds = (end - start);
  return elapsed_seconds;
}

/**
 * @brief
 * Ordenamiento por el algoritmo de seleccion
 * @param coleccion
 * @return std::chrono::duration<float,milli>
 */
std::chrono::duration<float, milli> Ordenamiento::seleccion(int coleccion[]) {
  int i, j;
  auto start = std::chrono::system_clock::now();
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
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, milli> elapsed_seconds = (end - start);
  return elapsed_seconds;
}

/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::shell
 * Sort object Ordenamiento por el algoritmo de shellshort
 * @param coleccion
 * @return std::chrono::duration<float,milli>
 */
std::chrono::duration<float, milli> Ordenamiento::shellSort(int coleccion[]) {
  int gap, i, j;

  auto start = std::chrono::system_clock::now();
  for (gap = MAX / 2; gap > 0; gap /= 2) {
    for (i = gap; i < MAX; i++) {
      for (j = i - gap; j >= 0 && coleccion[j] > coleccion[j + gap]; j -= gap) {
        int t = coleccion[j];
        coleccion[j] = coleccion[j + gap];
        coleccion[j + gap] = t;
      }
    }
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, milli> elapsed_seconds = (end - start);
  return elapsed_seconds;
}

/**
 * @brief Construct a new
 * std::chrono::duration<float,milli>Ordenamiento::burbuja Modificado object
 * Ordenamiento por el algoritmo de burbuja mejorado
 * @param coleccion
 * @return std::chrono::duration<float,milli>
 */
std::chrono::duration<float, milli>
Ordenamiento::burbujaModificado(int coleccion[]) {
  auto start = std::chrono::system_clock::now();
  int comparaciones, intercambios;
  comparaciones = 0;
  intercambios = 0;
  bool swapped;
  for (int i = 0; i < MAX - 1; i++) {
    swapped = false;
    for (int j = 0; j < MAX - i - 1; j++) {
      comparaciones++;
      if (coleccion[j] > coleccion[j + 1]) {
        swap(coleccion[j], coleccion[j + 1]);
        intercambios++;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, milli> elapsed_seconds = (end - start);
  return elapsed_seconds;
}
/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::quick
 * Sort object ordenamiento por el algoritmo de quickSort
 * @param coleccion
 * @param inicio
 * @param fin
 * @return std::chrono::duration<float,milli>
 */
/*
std::chrono::duration<float, milli>
Ordenamiento::quickSort(int coleccion[], int inicio, int fin) {
  auto start = std::chrono::system_clock::now();
  int izq, der, pivote, aux;
  izq = inicio;
  der = fin;
  pivote = coleccion[(izq + der) / 2];

  do {
    while (coleccion[izq] < pivote && izq < fin) {
      izq++;
    }
    while (coleccion[der] > pivote && der > inicio) {
      der--;
    }
    if (izq <= der) {
      aux = coleccion[izq];
      coleccion[izq] = coleccion[der];
      coleccion[der] = aux;
      izq++;
    }
  } while (izq <= der);

  if (inicio <= der) {
    quickSort(coleccion, inicio, der);
  }
  if (fin > izq) {
    quickSort(coleccion, izq, fin);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, milli> elapsed_seconds = (end - start);
  std::cout << "Tiempo transcurrido en el metodo quicksort: "
            << elapsed_seconds.count() << " segundos" << std::endl;
  return elapsed_seconds;
}*/

std::chrono::duration<float, std::milli>
Ordenamiento::quickSort(int coleccion[], int inicio, int fin) {
  auto start = std::chrono::system_clock::now();
  quickSortHelper(coleccion, inicio, fin);
  auto end = std::chrono::system_clock::now();
  return end - start;
}

void Ordenamiento::quickSortHelper(int coleccion[], int inicio, int fin) {
  if (inicio < fin) {
    int pivote = partition(coleccion, inicio, fin);
    quickSortHelper(coleccion, inicio, pivote - 1);
    quickSortHelper(coleccion, pivote + 1, fin);
  }
}

int Ordenamiento::partition(int coleccion[], int inicio, int fin) {
  int pivote = coleccion[fin];
  int i = inicio - 1;
  for (int j = inicio; j < fin; j++) {
    if (coleccion[j] < pivote) {
      i++;
      swap(coleccion[i], coleccion[j]);
    }
  }
  swap(coleccion[i + 1], coleccion[fin]);
  return i + 1;
}

void Ordenamiento::swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void Ordenamiento::tablaTiempos() {
  int array[MAX];
  std::chrono::duration<float, std::milli> tiempoDesordenado[6],
      tiempoOrdenado[6], tiempoInvertido[6];

  cout << "Calculando tiempos Insercion" << endl;
  initDesordenado(array);
  tiempoDesordenado[0] = insercion(array);
  initOrdenado(array);
  tiempoOrdenado[0] = insercion(array);
  initOrdenadoInv(array);
  tiempoInvertido[0] = insercion(array);

  cout << "Calculando tiempos Seleccion" << endl;
  initDesordenado(array);
  tiempoDesordenado[1] = seleccion(array);
  initOrdenado(array);
  tiempoOrdenado[1] = seleccion(array);
  initOrdenadoInv(array);
  tiempoInvertido[1] = seleccion(array);

  cout << "Calculando tiempos Burbuja" << endl;
  initDesordenado(array);
  tiempoDesordenado[2] = burbuja(array);
  initOrdenado(array);
  tiempoOrdenado[2] = burbuja(array);
  initOrdenadoInv(array);
  tiempoInvertido[2] = burbuja(array);

  cout << "Calculando tiempos burbujaModificado" << endl;
  initDesordenado(array);
  tiempoDesordenado[3] = burbujaModificado(array);
  initOrdenado(array);
  tiempoOrdenado[3] = burbujaModificado(array);
  initOrdenadoInv(array);
  tiempoInvertido[3] = burbujaModificado(array);

  cout << "Calculando tiempos ShellSort" << endl;
  initDesordenado(array);
  tiempoDesordenado[4] = shellSort(array);
  initOrdenado(array);
  tiempoOrdenado[4] = shellSort(array);
  initOrdenadoInv(array);
  tiempoInvertido[4] = shellSort(array);

  cout << "Calculando tiempos quickSort" << endl;
  initDesordenado(array);
  tiempoDesordenado[5] = quickSort(array, 0, MAX - 1);
  initOrdenado(array);
  tiempoOrdenado[5] = quickSort(array, 0, MAX - 1);
  initOrdenadoInv(array);
  tiempoInvertido[5] = quickSort(array, 0, MAX - 1);

  std::cout << std::setw(15) << " " << std::setw(15) << "Desordenado"
            << std::setw(15) << "Ordenado" << std::setw(15) << "Invertido"
            << std::endl;
  std::cout << std::setw(15) << "Insercion" << std::setw(15)
            << tiempoDesordenado[0].count() << std::setw(15)
            << tiempoOrdenado[0].count() << std::setw(15)
            << tiempoInvertido[0].count() << std::endl;
  std::cout << std::setw(15) << "Seleccion" << std::setw(15)
            << tiempoDesordenado[1].count() << std::setw(15)
            << tiempoOrdenado[1].count() << std::setw(15)
            << tiempoInvertido[1].count() << std::endl;
  std::cout << std::setw(15) << "Burbuja" << std::setw(15)
            << tiempoDesordenado[2].count() << std::setw(15)
            << tiempoOrdenado[2].count() << std::setw(15)
            << tiempoInvertido[2].count() << std::endl;
  std::cout << std::setw(15) << "Burbuja Mod" << std::setw(15)
            << tiempoDesordenado[3].count() << std::setw(15)
            << tiempoOrdenado[3].count() << std::setw(15)
            << tiempoInvertido[3].count() << std::endl;
  std::cout << std::setw(15) << "Shell Sort" << std::setw(15)
            << tiempoDesordenado[4].count() << std::setw(15)
            << tiempoOrdenado[4].count() << std::setw(15)
            << tiempoInvertido[4].count() << std::endl;
  std::cout << std::setw(15) << "Quick Sort" << std::setw(15)
            << tiempoDesordenado[5].count() << std::setw(15)
            << tiempoOrdenado[5].count() << std::setw(15)
            << tiempoInvertido[5].count() << std::endl;
}
