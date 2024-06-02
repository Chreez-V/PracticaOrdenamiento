#include <iostream>
#include <chrono>

#define MAX 10
using namespace std;
class Ordenamiento
 {

private:
public:
  Ordenamiento();
  /**
   * @brief 
   * Metodos de ordenamiento.
   * @param coleccion 
   * @return std::chrono::duration<float,milli> 
   */
  std::chrono::duration<float,milli> insercion(int coleccion[]);
  std::chrono::duration<float,milli> burbuja(int coleccion[]);
  std::chrono::duration<float,milli> seleccion(int coleccion[]);
  std::chrono::duration<float,milli> shellSort(int coleccion[]);
  std::chrono::duration<float,milli> quickSort(int coleccion[],int inicio,int fin);
  std::chrono::duration<float,milli> burbujaModificado(int coleccion[]);
  /**
   * @brief 
   * metodos para ordenar,desordenar e invertir los arreglos.
   * @param array 
   */
  void initDesordenado(int array[]);
  void initOrdenado(int array[]);
  void initOrdenadoInv(int array[]);

  /**
   * @brief 
   * metodos para mostrar los mejores resultados.
   */
  void tablaTiempos();
  void tablaIntercambios();
  void tablaComparaciones();
  void listaOrdenada();
};
