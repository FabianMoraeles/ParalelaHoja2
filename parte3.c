#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int valor;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        valor = 42;
    }

    MPI_Bcast(&valor, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Proceso %d recibió el valor: %d\n", rank, valor);

    MPI_Finalize();
    return 0;
}
