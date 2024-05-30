#include <iostream>
#define MAX 30000
using namespace std;
class Ordenamiento {

private:
  int array[MAX];

public:
  Ordenamiento();
  // metodos de ordenamiento
  void insercion(int *array[]);
  void seleccion(int *array[]);
  void intercambio();
  void shellSort();
  void quickSort();
  void Queso();

  // metodos de ejecutar el arreglo
  void initDesordenado();
  void initOrdenado();
  void initOrdenadoInv();

  // metodos para imprimir datos
  void tablaTiempos();
  void tablaIntercambios();
  void tablaComparaciones();
  void listaOrdenada();

  // setters y getters
  int *getArray();
};
