
#ifndef Algoritmos_HPP
#define Algoritmos_HPP
#include <iostream>
#include <chrono>
using namespace std;

class Algoritmos 
{

public:
       Algoritmos();
        /**
         * @brief 
         * Algoritmos de ordenamiento
         * @param array 
         * @param n 
         * @return chrono::duration<float,milli> 
         */
         chrono::duration<float,milli>  seleccion(int array[],int n);
         chrono::duration<float,milli>  InsertionSort(int array[],int n);
         chrono::duration<float,milli>  BubbleShort(int array[],int n);
         chrono::duration<float,milli>  shellSort(int array[],int n);
         chrono::duration<float,milli>  quickSort(int array[],int n);
            int*  ArrayOrdenDesecedente(int array[],int n);
           void ArrayOrdenado(int array[],int n);
        /**
         * @brief 
         * metodos para mostrar una lista ordenada
         *  1. Una lista basada en el tiempo
         *  2. Una lista basa en el numero de orden
         */
         void tablaTiempos();
         void listaOrdenada();
};

#endif 