PDP Homework #2: Matrix multiplication in MPI
=============================================
by B98705049 Ting-Yu Lu

How to compile run the program
------------------------------
$ mpicc mat.mpi.c -o mat.mpi

$ mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input11.dat 1 1  
$ mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input22.dat 2 2  
$ mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input32.dat 3 2  
$ mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input42.dat 4 2  
