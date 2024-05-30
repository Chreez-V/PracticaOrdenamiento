#include "Ordenamiento.hpp"

int main() {
  Ordenamiento obj;

  obj.initOrdenado();
  int *array = obj.getArray();
  cout << "Array en orden ascendente: ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  obj.initDesordenado();
  array = obj.getArray();
  cout << "Array en orden aleatorio: ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
  obj.initOrdenadoInv();
  array = obj.getArray();
  cout << "Array en orden descendente: ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
  obj.initDesordenado();
  array = obj.getArray();
  cout << "Array en orden aleatorio: ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
}
