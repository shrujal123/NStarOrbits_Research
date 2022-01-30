//#include
#include <mpi.h>
#include <iostream>
using namespace std;

int send_recv()
{
	MPI_Init(NULL, NULL);

	int world_rank;
	int world_size;
	int number;

	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if(world_rank == 0)
	{
		number = -1;
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

	}else if (world_rank == 1){

		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "Process 1 recieved number " << number << " from process 0" << endl;

	}
	MPI_Finalize();
}
