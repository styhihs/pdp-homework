PDP Homework #2: Matrix multiplication in MPI
=============================================

How to compile and run the program
----------------------------------

* Compile:

        mpicc mat.mpi.c -o mat.mpi


* Run:

        mpirun -n [num_of_processors] ./mat.mpi input11.dat 1 1  
        mpirun -n [num_of_processors] ./mat.mpi input22.dat 2 2  


* Run with hostfile:

        mpirun -n [num_of_processors] -hostfile hosts ./mat.mpi input11.dat 1 1  
        mpirun -n [num_of_processors] -hostfile hosts ./mat.mpi input22.dat 2 2  

