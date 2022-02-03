#include <mpi.h>
#include <iostream>
using namespace std;

int main()
{

	const int PING_PONG_LIMIT = 10;

	//initualize MPI
	MPI_Init(NULL, NULL);

	int world_rank;
	int world_size;

	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if(world_size != 2)
	{
		cout << "num processors must be two" <<endl;
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int ping_pong_count = 0;
	int opp_rank = (world_rank + 1)%2;

	while(1)
	{
		if(world_rank == ping_pong_count%2)
		{
			ping_pong_count++;
			MPI_Send(&ping_pong_count, 1, MPI_INT, opp_rank, 0, MPI_COMM_WORLD);
			cout << world_rank << " sent and incremented ping_pong_count " << ping_pong_count << " to " << opp_rank << endl;
		}
		else
		{
			MPI_Recv(&ping_pong_count, 1, MPI_INT, opp_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			cout << world_rank << " recieved ping_pong_count " << ping_pong_count << " from " << opp_rank << endl;
		}
	}

	MPI_Finalize();
	return 0;

}
