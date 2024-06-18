#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);   // Obtener el número de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   // Obtener el rango (ID) de este proceso

    int *sendbuf = malloc(size * sizeof(int));   // Buffer para datos a enviar
    int *recvbuf = malloc(size * sizeof(int));   // Buffer para datos recibidos

    // Inicializar datos en sendbuf basado en el rango de cada proceso
    for (int i = 0; i < size; i++) {
        sendbuf[i] = rank + i;
    }

    // Operaciones no bloqueantes: enviar y recibir datos
    MPI_Request reqs[2];   // Arreglo para almacenar las solicitudes de comunicación

    // Enviar datos desde sendbuf al proceso siguiente (en anillo)
    MPI_Isend(sendbuf, size, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD, &reqs[0]);

    // Recibir datos desde el proceso anterior (en anillo) en recvbuf
    MPI_Irecv(recvbuf, size, MPI_INT, (rank - 1 + size) % size, 0, MPI_COMM_WORLD, &reqs[1]);

    // Esperar a que todas las operaciones de envío y recepción se completen
    MPI_Waitall(2, reqs, MPI_STATUSES_IGNORE);

    // Realizar la operación de suma prefix en recvbuf
    for (int i = 1; i < size; i++) {
        recvbuf[i] += recvbuf[i-1];
    }

    // Imprimir los resultados obtenidos por cada proceso
    printf("Proceso %d: ", rank);
    for (int i = 0; i < size; i++) {
        printf("%d ", recvbuf[i]);
    }
    printf("\n");

    // Liberar la memoria de los buffers
    free(sendbuf);
    free(recvbuf);

    MPI_Finalize();   // Finalizar MPI

    return 0;
}
