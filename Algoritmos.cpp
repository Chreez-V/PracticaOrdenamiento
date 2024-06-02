#include <iostream>
#include <chrono>

#include "Algoritmos.hpp"

Algoritmos::Algoritmos(){}

   std::chrono::duration<float,milli>Algoritmos::BubbleShort(int array[],int n)
    {
    int aux;
    int cont =0; 
    auto start = std::chrono::system_clock::now();
  
for (int i = 0; i < n-1; i++)
{
    for (int j = 0; j < n-i-1; j++)
    {
        if (array[j] > array[j+1] )
        {
            aux = array[j];
            array[j] = array[j+1];
            array[j+1] = aux;
            cont++;
        }
    }
}

cout<<endl;
auto end = std::chrono::system_clock::now();
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);

std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
return elapsed_seconds;
    }
     

  std::chrono::duration<float,milli>Algoritmos::seleccion(int array[],int n)
  {
    int i, j;
    int iteracion=0;
 auto start = std::chrono::system_clock::now();

  for (i = 0; i < n - 1; i++) 
  {
    int select = i;
    for (j = i + 1; j < n; j++)
     {
      if (array[select] > array[j]) 
      {
        select = j;
      }
    }

    int t = array[i];
    array[i] = array[select];
    array[select] = t;
     iteracion++;
  }

  auto end = std::chrono::system_clock::now();
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);

std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
return elapsed_seconds;
  }


std::chrono::duration<float,milli>Algoritmos::InsertionSort(int array[],int n )
{
     
    auto start = std::chrono::system_clock::now();
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

cout<<endl;
auto end = std::chrono::system_clock::now();
 std::chrono::duration<float,milli>elapsed_seconds = (end - start);

std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;
    
    return elapsed_seconds;
}
        
std::chrono::duration<float,milli>Algoritmos::shellSort(int array[],int n)
{
 int gap, i, j;
  int iteracion=0;

 auto start = std::chrono::system_clock::now();
  for (gap = n / 2; gap > 0; gap /= 2) {
     
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap) {
       
        int t = array[j];
        array[j] = array[j + gap];
        array[j + gap] = t;
        
      }
        }
        
  }

  auto end = std::chrono::system_clock::now();
 std::chrono::duration<float,milli> elapsed_seconds = (end - start);
std::cout << "Tiempo transcurrido dentro del algoritmo: " << elapsed_seconds.count() << " segundos" << std::endl;

return elapsed_seconds;
}

