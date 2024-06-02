#include "Ordenamiento.hpp"
#define MAX 10

int main() {
  Ordenamiento obj;
  int array[MAX];

  obj.initOrdenado(array);
  cout << "Array en orden ascendente: ";
  for (int i = 0; i < MAX; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  obj.initDesordenado(array);
  cout << "Array en orden aleatorio: ";
  for (int i = 0; i < MAX; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
  obj.burbuja(array);
  cout << "array ordenado en burbuja: ";
  for (int i = 0; i < MAX; i++) {

    cout << array[i] << " ";
  }
  cout << endl;

  cout << endl;
  obj.initOrdenadoInv(array);
  cout << "Array en orden descendente: ";
  for (int i = 0; i < MAX; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
  obj.insercion(array);
  cout << "array ordenado en insercion: ";
  for (int i = 0; i < MAX; i++) {

    cout << array[i] << " ";
  }
  cout << endl;
  obj.initDesordenado(array);
  cout << "Array en orden aleatorio: ";
  for (int i = 0; i < MAX; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  obj.insercion(array);
  cout << "array ordenado en insercion: ";
  for (int i = 0; i < MAX; i++) {

    cout << array[i] << " ";
  }

  cout << endl;
}
