#include <chrono>
#include <iostream>

#define MAX 30000
using namespace std;
class Ordenamiento {

private:
  void quickSortHelper(int coleccion[], int inicio, int fin);
  int partition(int coleccion[], int inicio, int fin);

public:
  Ordenamiento();
  /**
   * @brief
   * Metodos de ordenamiento.
   * @param coleccion
   * @return std::chrono::duration<float,milli>
   */
  std::chrono::duration<float, milli> insercion(int coleccion[]);
  std::chrono::duration<float, milli> burbuja(int coleccion[]);
  std::chrono::duration<float, milli> seleccion(int coleccion[]);
  std::chrono::duration<float, milli> shellSort(int coleccion[]);
  std::chrono::duration<float, milli> quickSort(int coleccion[], int inicio,
                                                int fin);
  std::chrono::duration<float, milli> burbujaModificado(int coleccion[]);
  /**
   * @brief
   * metodos para ordenar,desordenar e invertir los arreglos.
   * @param array
   */
  void initDesordenado(int array[]);
  void initOrdenado(int array[]);
  void initOrdenadoInv(int array[]);
  void swap(int &a, int &b);

  /**
   * @brief
   * metodos para mostrar los mejores resultados.
   */
  void tablaTiempos();
  void tablaOrdenada();
  void tablaComparaciones();
  void listaOrdenada();
};
