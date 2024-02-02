#include <mpi.h>
#include <stdio.h>

#define MASTER_RANK 0

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size, world_rank;

    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Print from each process
    printf("Hello world from rank %d out of %d processors\n", world_rank, world_size);

    // Additional action by the master process
    if (world_rank == MASTER_RANK) {
        printf("This is the master process (Rank %d)\n", MASTER_RANK);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
