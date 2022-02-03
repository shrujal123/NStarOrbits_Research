#include <iostream>
#include <thread>
#include <mutex>
//#include <mpi.h>


using namespace std;

mutex mtx;

void print_thread_id (int id)
{

	while(true)
	{
	mtx.lock();
	cout << "thread #" << id << endl;
	mtx.unlock();
	}

	cout << "development branch comment" << endl;
}

int main ()
{

	//MPI_INIT(NULL, NULL);
	//int world_rank;
	//int world_size;

	//MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	//MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	

	thread threads[5];

	for(int i = 0; i < 5; i++)
	{
		threads[i] = thread(print_thread_id, i+1);
	}

	for(auto& th : threads) th.join();

	return 0;

}
