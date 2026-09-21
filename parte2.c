#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Rank %d: Etapa 1, antes de la barrera\n", rank);
    fflush(stdout);

    sleep(rank);

    MPI_Barrier(MPI_COMM_WORLD);

    printf("Rank %d: Etapa 2, después de la barrera\n", rank);
    fflush(stdout);

    MPI_Finalize();
    return 0;
}
