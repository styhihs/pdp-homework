#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define WORKTAG 1
#define DIETAG 0

int *array;
int n, len;

int mult(int *_array, int *args) {
  int i, j, k;
  int sum = 0;
  
  for (i = args[0]; i < len; i += args[1]){
    for (j = 0; j < len; j++){
      for (k= 0; k < len; k++){
        sum += _array[i * len + k] * _array[k * len + j];
      }
    }
  }

  return sum;
}

int main(int argc, char *argv[]) {
  int i, j;
  int sum, partial_sum, use_comm_size, args[2];
  int comm_size, rank;
  MPI_Status status;
  FILE *fp = fopen(argv[1],"rb");

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  sscanf(argv[2], "%d", &n);
  sscanf(argv[3], "%d", &len);
  n = pow(10, n);
  len = pow(10, len);

  array = (int*)malloc(sizeof(int) * n * len * len);
  fread(array, (sizeof(int)), (n * len * len), fp);

  for (i = 0; i < n; i++) {
    sum = 0;
    if (rank != 0) {  // slaves
      MPI_Recv(args, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      if (status.MPI_TAG == WORKTAG) {
        partial_sum = mult(array + (i * len * len), args);
        MPI_Send(&partial_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
      }
    } else {  // master
      use_comm_size = (comm_size <= len) ? comm_size : len;
      for (j = 1; j < comm_size; j++) {
        args[0] = j;
        args[1] = use_comm_size;
        if (j < use_comm_size)
          MPI_Send(args, 2, MPI_INT, j, WORKTAG, MPI_COMM_WORLD);
        else MPI_Send(args, 2, MPI_INT, j, DIETAG, MPI_COMM_WORLD);
      }

      args[0] = 0;
      args[1] = use_comm_size;
      sum += mult(array + (i * len * len), args);
      
      for (j = 1; j < use_comm_size; j++) {
        MPI_Recv(&partial_sum, 1, MPI_INT, j, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum += partial_sum;
      }

      printf("%d\n", sum);
    }
  }

  MPI_Finalize();

  return 0;
}
