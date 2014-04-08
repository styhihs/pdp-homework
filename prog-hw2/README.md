PDP Homework #2: Matrix multiplication in MPI
=============================================
by B98705049 Ting-Yu Lu

How to run the program
----------------------
mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input11.dat 1 1  
mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input22.dat 2 2  
mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input32.dat 3 2  
mpirun -n [num_of_procs] -hostfile hosts ./mat.mpi input42.dat 4 2  

* [num_of_procs]: You can assign any # of processors you like. :-)
