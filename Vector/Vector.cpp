#include "Vector.h"

Vector::Vector() {
    size = 0;
    capacity = 10;
    arr = new int[capacity];
}

Vector::Vector(int size)
{
    capacity = size;
    arr = new int[capacity];
    this->size =0;
}

Vector::Vector(const Vector& other)
{
    if (arr)
    {
        delete[] arr;
    } 
    capacity = other.capacity;
    size = other.size;
    arr = new int[capacity]; 
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}
Vector::~Vector()
{
    delete[] arr;
}

int Vector::getCapacity() {
    return capacity;
}

int Vector::getSize()
{
    return size;
}

void Vector::print()
{
    cout << "capacity: " << capacity << " " << "size: " << size << " val:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void Vector::delLast()
{
    if (size == 0)
    {
        cout << "ERROR" << endl;
        exit(-1);
    }
    size = size - 1;//Shaving off last element so size will decrease by one.
    int* newArr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}
Vector Vector:: operator + (const Vector &other)
{
    Vector combinedVector = Vector(size + other.size);
    for (int i = 0; i < size; ++i)
    {
        combinedVector[i] = arr[i];
        combinedVector.size++;
    }
    for (int i =0; i < other.size; ++i)
    {
        combinedVector[i+size] = other.arr[i];
        combinedVector.size++;
    }
    return combinedVector;
}
void Vector::clear() {
    size = 0;
}
Vector& Vector::operator = (const Vector &other)
{
    if (arr)
    {
        delete[] arr;
    }
    capacity = other.capacity;
    size=other.size;
    arr = new int[size];
    for (int i = 0; i <size; ++i)
    {
        arr[i] = other.arr[i];   
    }
    
    return *this;
}
bool Vector::operator == (const Vector &other)
{
    if (this->size != other.size)
    {
        return false;
    }
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }
    return true;
}
int& Vector::operator [] (int index)
{
    if (index < 0 || (index!=0 && index>size))
    {
        cout << "ERROR" << endl;
        exit(-1);
    }
    return arr[index];
}
int Vector::operator * (const Vector &other)
{
    int result = 0;
    if (size != other.size)
    {
        cout << "ERROR" << endl;
        exit(-1);
    }
    for (int i = 0; i < size; ++i)
    {
        result += arr[i] * other.arr[i];
    }
    return result;
}
void Vector::insert(int val)
{
    if (size == capacity)//Array is full
    {
        cout << "ERROR" << endl;
        exit(-1);
    }
    arr[size] = val;
    size++;
}
