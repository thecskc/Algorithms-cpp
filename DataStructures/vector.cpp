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
	const static int INITIAL_SIZE = 0;

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

	//no checking of bounds.
	Object& operator[](int position) const
	{
		return data[position];
	}


	//Destructor
	~Vector()
	{
		delete[] data;
	}

	//adds an entry to the back of the vector
	void push_back(const Object& entry)
	{
		if (size + 1 == capacity)
		{
			resize();
		}
		data[size++] = move(entry);
		
		


	}

	//removes an entry from the back of the vector.
	void pop_back()
	{
		Object *newData = new Object[capacity];
		for (int counter = 0;counter < size - 1;counter++)
		{
			newData[counter] = data[counter];

		}

		delete[] data;
		size = size - 1;
		data = newData;
		newData = nullptr;

		

	}


	void displayVector()
	{
		for (int counter = 0;counter < size;counter++)
		{
			cout << data[counter] << endl;
		}
	}



	








};


int main()
{
	Vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.displayVector();
	vec.pop_back();
	vec.displayVector();

	cout << vec[0] << endl;

	cout << vec[10] << endl; //no bounds checking

	vec[0] = 50;
	cout << vec[0] << endl;
	


}
