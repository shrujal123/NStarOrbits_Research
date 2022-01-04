#include "header.h"
using namespace std;

int math()
{
	int a = 2;
	int b = 4;
	int c = product(sum(a, b), difference(b, a));
	cout<<"answer: " <<quotient(c, b)<<endl;	
	return 0;
}
