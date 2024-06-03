#include "Ordenamiento.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

// Prototipos de las funciones del menú
void mostrarMenu();
void mostrarResultadosPorTiempo(Ordenamiento &ordenamiento, int array[]);
void compararOrdenamientos(Ordenamiento &ordenamiento, int array[],
                           bool primerosMil);

int main() {
  Ordenamiento ordenamiento;
  int array[MAX];
  bool salir = false;

  while (!salir) {
    mostrarMenu();
    int opcion;
    std::cin >> opcion;

    switch (opcion) {
    case 1:
      ordenamiento.tablaTiempos();
      break;
    case 2:
      compararOrdenamientos(ordenamiento, array, false);
      break;
    case 3:
      compararOrdenamientos(ordenamiento, array, true);
      break;
    case 4:
      salir = true;
      break;
    default:
      std::cout << "Opción no válida. Por favor, intente de nuevo."
                << std::endl;
      break;
    }
  }

  return 0;
}

void mostrarMenu() {
  std::cout << "\n--- Menú de Opciones ---" << std::endl;
  std::cout << "1. Mostrar resultados por tiempo" << std::endl;
  std::cout << "2. Comparar ordenamientos en arreglo completo" << std::endl;
  std::cout << "3. Comparar ordenamientos en primeros 1000 elementos de un "
               "arreglo de 30000"
            << std::endl;
  std::cout << "4. Salir" << std::endl;
  std::cout << "Seleccione una opción: ";
}

void compararOrdenamientos(Ordenamiento &ordenamiento, int array[],
                           bool primerosMil) {
  std::vector<std::pair<std::string, std::chrono::duration<float, std::milli>>>
      resultados;

  if (primerosMil) {
    const int numElementos = 1000;
    int tempArray[numElementos];

    ordenamiento.initDesordenado(array);
    std::copy(array, array + numElementos, tempArray);
    resultados.emplace_back("Insercion", ordenamiento.insercion(tempArray));

    ordenamiento.initDesordenado(array);
    std::copy(array, array + numElementos, tempArray);
    resultados.emplace_back("Burbuja", ordenamiento.burbuja(tempArray));

    ordenamiento.initDesordenado(array);
    std::copy(array, array + numElementos, tempArray);
    resultados.emplace_back("Seleccion", ordenamiento.seleccion(tempArray));

    ordenamiento.initDesordenado(array);
    std::copy(array, array + numElementos, tempArray);
    resultados.emplace_back("Shell Sort", ordenamiento.shellSort(tempArray));

    ordenamiento.initDesordenado(array);
    std::copy(array, array + numElementos, tempArray);
    resultados.emplace_back("Burbuja Modificado",
                            ordenamiento.burbujaModificado(tempArray));

    ordenamiento.initDesordenado(array);
    std::copy(array, array + numElementos, tempArray);
    resultados.emplace_back(
        "Quick Sort", ordenamiento.quickSort(tempArray, 0, numElementos - 1));

    std::cout
        << "\n--- Comparación de Ordenamientos (Primeros 1000 Elementos) ---"
        << std::endl;
  } else {
    ordenamiento.initDesordenado(array);
    resultados.emplace_back("Insercion", ordenamiento.insercion(array));

    ordenamiento.initDesordenado(array);
    resultados.emplace_back("Burbuja", ordenamiento.burbuja(array));

    ordenamiento.initDesordenado(array);
    resultados.emplace_back("Seleccion", ordenamiento.seleccion(array));

    ordenamiento.initDesordenado(array);
    resultados.emplace_back("Shell Sort", ordenamiento.shellSort(array));

    ordenamiento.initDesordenado(array);
    resultados.emplace_back("Burbuja Modificado",
                            ordenamiento.burbujaModificado(array));

    ordenamiento.initDesordenado(array);
    resultados.emplace_back("Quick Sort",
                            ordenamiento.quickSort(array, 0, MAX - 1));

    std::cout << "\n--- Comparación de Ordenamientos (Arreglo Completo) ---"
              << std::endl;
  }

  std::sort(resultados.begin(), resultados.end(),
            [](auto &left, auto &right) { return left.second < right.second; });

  for (const auto &resultado : resultados) {
    std::cout << resultado.first << ": " << resultado.second.count() << " ms"
              << std::endl;
  }
}

