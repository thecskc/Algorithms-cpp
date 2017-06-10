#include<iostream>
#include<fstream>
using namespace std;

template<class Object>
class Vector
{
private:
	Object* data;
	const int INITIAL_CAPACITY = 16;
	
public:
	Vector() :data(new Object[INITIAL_CAPACITY]) {};


	~Vector()
	{
		delete[] data;
	}







};


int main()
{



}
