#include<iostream>
#include<fstream>
using namespace std;

template<class Object>
class Vector
{
private:
	Object* data;
	int size;
	int capacity;
	const int INITIAL_SIZE = 16;

	
public:

	static const int SPARE_CAPACITY = 16;
	Vector(int theSize=INITIAL_SIZE, int theCapacity= INITIAL_SIZE+SPARE_CAPACITY) :data(new Object[theCapacity]),
		size(theSize),capacity(theCapacity) {};


	~Vector()
	{
		delete[] data;
	}

	Vector<Object>& operator=(const Vector<Object>& rhs)
	{
		if (this != &rhs)
		{
			delete[] data;
			data = new Object[rhs.capacity];
			for (int counter = 0;counter < rhs.size;counter++)
			{
				data[counter] = rhs.data[counter];
			}
			size = rhs.size;
			capacity = rhs.capacity;

			

		}
		return this;


	}








};


int main()
{



}
