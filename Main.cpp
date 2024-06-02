#include <iostream>
#include <chrono>
#include <thread>
#include "Algoritmos.hpp"

#define size  12
using namespace std;

void Menu(Algoritmos orden,int array[], int n);
void TiemposOrdenados( chrono::duration<float,milli> tiempos[]);

int main() 
{
Algoritmos orden; // crea una instancia de la clase Algoritmos

    int array[] = {22,3,3,10,14,15,1,2,4,5,6,55,23};
    int n = sizeof(array)/sizeof(int);

    Menu(orden,array,n);

    return 0;
}

void Menu(Algoritmos orden,int array[], int n)
{
    chrono::duration<float,milli> tiempos[4];
  cout<<"\t\t\tBIENVENIDO AL TESTER DE ALGORITMOS DE ORDENAMIENTO\nElija un estilo de array para poder medir el tiempo de cada algoritmo.\n";
  cout<<"1. Array Desordenado.\n";
  cout<<"2. Array Ordenado.\n";
  cout<<"3. Array Ordenado-invertido.\n";
  cout<<"\t\t\tPresione la tecla de Escape para salir.\n";
  int option;
  cin>>option;
switch (option)
{
case 1:
      cout<<"InsertionSort:\n";
     tiempos[0] = orden.InsertionSort(array,n);

     cout<<"shellSort:\n";
     tiempos[1] = orden.shellSort(array,n);

     cout<<"seleccion:\n";
     tiempos[2] = orden.seleccion(array,n);

    cout<<"Bubble:\n";
     tiempos[3] = orden.BubbleShort(array,n);
  break;
case 2:

  for (int i = 0; i < n; i++)
{
    int pos = i;
    int aux = array[i];

        while ((pos>0) && (array[pos-1])>aux)
        {
            array[pos] = array[pos-1];
            pos--;
        }
        array[pos] = aux;
}
     cout<<"InsertionSort:\n";
     tiempos[0] = orden.InsertionSort(array,n);

     cout<<"shellSort:\n";
     tiempos[1] = orden.shellSort(array,n);

     cout<<"seleccion:\n";
     tiempos[2] = orden.seleccion(array,n);

    cout<<"Bubble:\n";
     tiempos[3] = orden.BubbleShort(array,n);

  break;
  case 3:
    for (int i = 0; i < n; i++)
{
    int pos = i;
    int aux = array[i];

        while ((pos>0) && (array[pos-1])>aux)
        {
            array[pos] = array[pos-1];
            pos--;
        }
        array[pos] = aux;
}
     for (int  i = n-1; i >= 0; i--)
    {
        array[i];
    }
       cout<<"InsertionSort:\n";
     tiempos[0] = orden.InsertionSort(array,n);

     cout<<"shellSort:\n";
     tiempos[1] = orden.shellSort(array,n);

     cout<<"seleccion:\n";
     tiempos[2] = orden.seleccion(array,n);

    cout<<"Bubble:\n";
     tiempos[3] = orden.BubbleShort(array,n);
  break;

  case 27:
      system("exit");
  break;
default:
  break;
}
}


void TiemposOrdenados( chrono::duration<float,milli> tiempos[])
{

cout<<"\n\n\t\tTiempos ordenados\n";
for (int i = 0; i < 4; i++) {
    int min_index = i;
    for (int j = i + 1; j < 4; j++) {
        if (tiempos[j] < tiempos[min_index]) {
            min_index = j;
        }
    }
    chrono::duration<float, milli> temp = tiempos[i];
    tiempos[i] = tiempos[min_index];
    tiempos[min_index] = temp;
}
for (int i = 0; i < 4; i++) {
    cout << "Tiempo " << i + 1 << ": " << tiempos[i].count() << " seg" << endl;
}
}