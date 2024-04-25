#include <stdio.h>

// Estructura para representar un proceso
typedef struct {
    int id;
    int size;
    int allocated_block;  // ID del bloque de memoria asignado (-1 si no está asignado)
} Process;

// Estructura para representar un bloque de memoria
typedef struct {
    int id;
    int size;
    int available;  // Espacio disponible en el bloque
} MemoryBlock;

// Función para asignar un proceso a un bloque de memoria
void allocate(Process *process, MemoryBlock *blocks, int num_blocks) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (blocks[i].available >= process->size) {
            process->allocated_block = blocks[i].id;
            blocks[i].available -= process->size;
            break;
        }
    }
}

// Función para mostrar la asignación de memoria para cada proceso
void print_allocation(Process *processes, int num_processes) {
    int i;
    printf("Proceso\tTamano\tBloque asignado\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t", processes[i].id, processes[i].size);
        if (processes[i].allocated_block == -1) {
            printf("No asignado\n");
        } else {
            printf("%d\n", processes[i].allocated_block);
        }
    }
}

int main() {
    // Definir los procesos y bloques de memoria
    Process processes[] = {
        {1, 212, -1},
        {2, 417, -1},
        {3, 112, -1},
        {4, 426, -1}
    };

    MemoryBlock blocks[] = {
        {1, 100, 100},
        {2, 500, 500},
        {3, 200, 200},
        {4, 300, 300},
        {5, 600, 600}
    };

    int num_processes = sizeof(processes) / sizeof(Process);
    int num_blocks = sizeof(blocks) / sizeof(MemoryBlock);

    // Asignar memoria a los procesos
    int i;
    for (i = 0; i < num_processes; i++) {
        allocate(&processes[i], blocks, num_blocks);
    }
    
    // Agregar procesos adicionales
    Process additional_processes[] = {
        {5, 300, -1}, // Cambiado tamaño a 300
        {6, 400, -1}, // Cambiado tamaño a 400
        {7, 150, -1}, // Cambiado tamaño a 150
        {8, 200, -1}  // Cambiado tamaño a 200
    };

    // Asignar memoria a los procesos adicionales
    int num_additional_processes = sizeof(additional_processes) / sizeof(Process);
    for (i = 0; i < num_additional_processes; i++) {
        allocate(&additional_processes[i], blocks, num_blocks);
    }
    // Mostrar la asignación de memoria
    print_allocation(processes, num_processes);
    
    // Mostrar la asignación de memoria para los procesos adicionales
     printf("\nPROBLEMA ADICIONAL\n\n");
    print_allocation(additional_processes, num_additional_processes);

    return 0;
}
