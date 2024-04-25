#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un art�culo
struct Item {
    int profit; // Beneficio
    int weight; // Peso
    float ratio; // Raz�n beneficio/peso
};

// Funci�n de comparaci�n para qsort
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    float ratio1 = item1->ratio;
    float ratio2 = item2->ratio;
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

// Funci�n para resolver el problema de la mochila fraccionaria
float fractional_knapsack(struct Item arr[], int n, int W) {
    // Calcular el ratio (beneficio/peso) para cada art�culo
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    // Ordenar los art�culos en orden no creciente de ratio
    qsort(arr, n, sizeof(arr[0]), compare);

    float total_profit = 0; // Inicializar el beneficio total
    int weight_remaining = W; // Peso restante en la mochila

    // Iterar sobre los art�culos ordenados
    for (int i = 0; i < n; i++) {
        // Si el peso del art�culo es menor o igual al peso restante en la mochila
        if (arr[i].weight <= weight_remaining) {
            total_profit += arr[i].profit; // Agregar el beneficio del art�culo al total
            weight_remaining -= arr[i].weight; // Restar el peso del art�culo al peso restante
        } else {
            // Si no, tomar una fracci�n del art�culo para llenar la mochila
            total_profit += arr[i].ratio * weight_remaining;
            break; // Romper el ciclo
        }
    }

    return total_profit; // Devolver el beneficio total
}

int main() {
    // Ejemplo de entrada
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]); // N�mero de art�culos
    int W = 50; // Capacidad de la mochila

    // Llamar a la funci�n fractional_knapsack y mostrar el resultado
    float max_profit = fractional_knapsack(arr, n, W);
    printf("El beneficio maximo obtenido es: %.2f\n", max_profit);
    
    // Caso adicional 1: Mochila chica
    struct Item arr1[] = {{10, 5}, {20, 10}, {15, 7}};
    n = sizeof(arr1) / sizeof(arr1[0]);
    W = 15;

    max_profit = fractional_knapsack(arr1, n, W);
    printf("El beneficio maximo obtenido para la mochila chica es: %.2f\n", max_profit);

    // Caso adicional 2: Mochila grande
    struct Item arr2[] = {{50, 20}, {30, 20}, {40, 20}, {60, 20}};
    n = sizeof(arr2) / sizeof(arr2[0]);
    W = 60;

    max_profit = fractional_knapsack(arr2, n, W);
    printf("El beneficio maximo obtenido para la mochila grande es: %.2f\n", max_profit);

    // Caso adicional 3: Art�culos con ratios diferentes
    struct Item arr3[] = {{20, 10}, {15, 5}, {30, 15}, {25, 8}};
    n = sizeof(arr3) / sizeof(arr3[0]);
    W = 20;

    max_profit = fractional_knapsack(arr3, n, W);
    printf("El beneficio maximo obtenido para los articulos con ratios diferentes es: %.2f\n", max_profit);

    return 0;
    
    
}
