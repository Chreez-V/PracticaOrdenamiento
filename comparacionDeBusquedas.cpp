#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Prototipos de las funciones de ordenamiento
void insercion(int arr[], int n, int &comparaciones, int &intercambios);
void seleccion(int arr[], int n, int &comparaciones, int &intercambios);
void burbuja(int arr[], int n, int &comparaciones, int &intercambios);
void burbujaModificado(int arr[], int n, int &comparaciones, int &intercambios);
void shellSort(int arr[], int n, int &comparaciones, int &intercambios);
void quickSort(int arr[], int low, int high, int &comparaciones, int &intercambios);

// Función auxiliar para imprimir el array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Función para medir el tiempo de ejecución
template<typename Func>
void medirTiempo(Func funcion, int arr[], int n, int &comparaciones, int &intercambios) {
    auto start = high_resolution_clock::now();
    funcion(arr, n, comparaciones, intercambios);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
}

// Función de ordenamiento por inserción
void insercion(int arr[], int n, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparaciones++;
            arr[j + 1] = arr[j];
            j = j - 1;
            intercambios++;
        }
        comparaciones++;
        arr[j + 1] = key;
        intercambios++;
    }
}

// Función de ordenamiento por selección
void seleccion(int arr[], int n, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
        intercambios++;
    }
}

// Función de ordenamiento por burbuja
void burbuja(int arr[], int n, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
            }
        }
    }
}

// Función de ordenamiento por burbuja modificado
void burbujaModificado(int arr[], int n, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Función de ordenamiento Shell Sort
void shellSort(int arr[], int n, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparaciones++;
                arr[j] = arr[j - gap];
                intercambios++;
            }
            comparaciones++;
            arr[j] = temp;
            intercambios++;
        }
    }
}

// Función auxiliar para Quick Sort (partición)
int partition(int arr[], int low, int high, int &comparaciones, int &intercambios) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        comparaciones++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            intercambios++;
        }
    }
    swap(arr[i + 1], arr[high]);
    intercambios++;
    return (i + 1);
}

// Función de ordenamiento Quick Sort
void quickSort(int arr[], int low, int high, int &comparaciones, int &intercambios) {
    if (low < high) {
        int pi = partition(arr, low, high, comparaciones, intercambios);
        quickSort(arr, low, pi - 1, comparaciones, intercambios);
        quickSort(arr, pi + 1, high, comparaciones, intercambios);
    }
}

// Función principal
int main() {
    srand(time(0));  // Inicializa la semilla para números aleatorios
    const int N = 10;  // Tamaño del array
    int arr[N];

    // Llenar el array con números aleatorios
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;  // Números aleatorios entre 0 y 99
    }

    cout << "Array original: ";
    printArray(arr, N);

    int comparaciones, intercambios;

    // Puedes probar cualquiera de los métodos de ordenamiento comentando y descomentando las siguientes líneas:
    
    //cout << "Ordenado por inserción: ";
    //medirTiempo(insercion, arr, N, comparaciones, intercambios);
    //printArray(arr, N);
    //cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;

    //cout << "Ordenado por selección: ";
    //medirTiempo(seleccion, arr, N, comparaciones, intercambios);
    //printArray(arr, N);
    //cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;

    //cout << "Ordenado por burbuja: ";
    //medirTiempo(burbuja, arr, N, comparaciones, intercambios);
    //printArray(arr, N);
    //cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;

    //cout << "Ordenado por burbuja modificada: ";
    //medirTiempo(burbujaModificado, arr, N, comparaciones, intercambios);
    //printArray(arr, N);
    //cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;

    //cout << "Ordenado por Shell Sort: ";
    //medirTiempo(shellSort, arr, N, comparaciones, intercambios);
    //printArray(arr, N);
    //cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;

    cout << "Ordenado por Quick Sort: ";
    medirTiempo([&](int arr[], int n, int &comparaciones, int &intercambios) {
        quickSort(arr, 0, n - 1, comparaciones, intercambios);
    }, arr, N, comparaciones, intercambios);
    printArray(arr, N);
    cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;

    return 0;
}
