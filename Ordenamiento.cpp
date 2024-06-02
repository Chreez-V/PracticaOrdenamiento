#include "Ordenamiento.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>

/**
 * Esta clase esta constituida por todos los algoritmos de ordenamiento
 */

Ordenamiento::Ordenamiento() {}

/**
 * @brief 
 * Este metodo Ordena el array
 * @param array 
 */
void Ordenamiento::initOrdenado(int array[]) 
{
  for (int i = 0; i < MAX; i++) {
    array[i] = i;
  }
}
/**
 * @brief 
 * Este metodo desordena el array
 * @param array 
 */
void Ordenamiento::initDesordenado(int array[]) 
{
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
void Ordenamiento::initOrdenadoInv(int array[]) 
{
  for (int i = 0; i < MAX; i++) {
    array[i] = MAX - 1 - i;
  }
}

/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::insercion object
 * Ordenamiento por el algoritmo de insercion
 * @param coleccion 
 * @return std::chrono::duration<float,milli> 
 */
std::chrono::duration<float,milli>Ordenamiento::insercion(int coleccion[]) 
{
  int i, j;
  auto start = std::chrono::system_clock::now();
  
  for (i = 1; i < MAX; i++) 
  {
    int temp = coleccion[i];
    j = i - 1;

    while (j >= 0 && coleccion[j] > temp) 
    {
      coleccion[j + 1] = coleccion[j];
      j--;
    }
    coleccion[j + 1] = temp;
  }

 auto end = std::chrono::system_clock::now();
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);
 std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;

return elapsed_seconds;
}

/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::burbuja object
 * Ordenamiento por el algoritmo de burbuja
 * @param array 
 * @return std::chrono::duration<float,milli> 
 */
std::chrono::duration<float,milli>Ordenamiento::burbuja(int array[])
{
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
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);
 std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
 return elapsed_seconds;
}

/**
 * @brief 
 * Ordenamiento por el algoritmo de seleccion
 * @param coleccion 
 * @return std::chrono::duration<float,milli> 
 */
std::chrono::duration<float,milli> Ordenamiento::seleccion(int coleccion[]) 
{
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
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);
 std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
 return elapsed_seconds;
}

/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::shell Sort object
 * Ordenamiento por el algoritmo de shellshort 
 * @param coleccion 
 * @return std::chrono::duration<float,milli> 
 */
std::chrono::duration<float,milli>Ordenamiento::shellSort(int coleccion[])
 {
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
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);
 std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
 return elapsed_seconds;
}

/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::burbuja Modificado object
 * Ordenamiento por el algoritmo de burbuja mejorado
 * @param coleccion 
 * @return std::chrono::duration<float,milli> 
 */
std::chrono::duration<float,milli>Ordenamiento::burbujaModificado(int coleccion[])
{
  auto start = std::chrono::system_clock::now();
int comparaciones,intercambios;
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
  std::chrono::duration<float,milli> elapsed_seconds = (end - start);
  std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
   return elapsed_seconds;
}
/**
 * @brief Construct a new std::chrono::duration<float,milli>Ordenamiento::quick Sort object
 * ordenamiento por el algoritmo de quickSort
 * @param coleccion 
 * @param inicio 
 * @param fin 
 * @return std::chrono::duration<float,milli> 
 */
std::chrono::duration<float,milli>Ordenamiento::quickSort(int coleccion[],int inicio,int fin)
 {
  auto start = std::chrono::system_clock::now();
  int izq,der,pivote,aux;
    izq = inicio;
    der = fin;
    pivote = coleccion[(izq+der)/2];

    do{
      while(coleccion[izq]< pivote && izq<fin)
      {
          izq++;
      }
      while(coleccion[der]> pivote && der>inicio)
      {
          der--;
      }
      if (izq<=der)
      {
        aux =coleccion[izq];
        coleccion[izq] = coleccion[der];
        coleccion[der] = aux;
        izq++;
      }
    } while (izq<=der);

    if (inicio <= der)
    {
      quickSort(coleccion,inicio,der);
    }
    if (fin > izq)
    {
      quickSort(coleccion,izq,fin);
    }
       auto end = std::chrono::system_clock::now();
  std::chrono::duration<float,milli> elapsed_seconds = (end - start);
  std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
   return elapsed_seconds;
}
