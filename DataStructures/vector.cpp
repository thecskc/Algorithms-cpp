#include<iostream>
#include<fstream>
using namespace std;


//The data is handled via an array that the Object pointer (termed data in private) is pointing to.
template<class Object>
class Vector
{
private:
	Object* data;
	int size;
	int capacity;
	const int INITIAL_SIZE = 16;

	void resize()
	{
		int newCapacity = 2 * size + SPARE_CAPACITY;
		Object *newData = new Object[newCapacity];
		for (int counter = 0;counter < size;counter++)
		{
			newData[counter] = data[counter];
		}

		capacity = newCapacity;

		delete[] data;
		data = newData;
		newData = nullptr;



	}

	
public:

	static const int SPARE_CAPACITY = 16;

	//Default Constructor
	Vector(int theSize=INITIAL_SIZE, int theCapacity= INITIAL_SIZE+SPARE_CAPACITY) :data(new Object[theCapacity]),
		size(theSize),capacity(theCapacity) {} 

	//Copy Constructor
	Vector(const Vector<Object>& rhs):data(new Object[rhs.capacity]),size(rhs.size),capacity(rhs.capacity)
	{
		for (int counter = 0;counter < size;counter++)
		{
			data[counter] = rhs.data[counter];
		}


	}

	//move copy constructor
	Vector(Vector&& rhs) :size(rhs.size), capacity(rhs.capacity),data(rhs.data)
	{
		rhs.data = nullptr;
		rhs.capacity = 0;
		rhs.size = 0;
		

	}


	//Assignment Operator
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
		return *this;


	}

	//Move assignment operator
	Vector& operator=(Vector&& rhs)
	{
		swap(data, rhs.data);
		swap(size, rhs.size);
		swap(capacity, rhs.capacity);
		
		return *this;

	}


	//Destructor
	~Vector()
	{
		delete[] data;
	}

	bool push_back(const Object& entry)
	{
		if (size + 1 == capacity)
		{
			resize();
		}
		data[size++] = move(entry);
		



	}

	








};


int main()
{



}
