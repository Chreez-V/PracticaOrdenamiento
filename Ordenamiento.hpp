#include <iostream>
#define MAX 10
using namespace std;
class Ordenamiento {

private:
  

public:
  Ordenamiento();
  // metodos de ordenamiento
  void insercion(int coleccion[]);
  void burbuja(int coleccion[]);
  void seleccion(int coleccion[]);
  void shellSort(int coleccion[]);
  void quickSort(int coleccion[]);
  void burbujaModificado(int coleccion[]);

  // metodos de ejecutar el arreglo
  void initDesordenado(int array[]);
  void initOrdenado(int array[]);
  void initOrdenadoInv(int array[]);

  // metodos para imprimir datos
  void tablaTiempos();
  void tablaIntercambios();
  void tablaComparaciones();
  void listaOrdenada();
};
