#pragma once

/* 벡터(가변 배열)의 특징
*  - 길이가 변할 수 있다. 동적 크기 변환이 가능하다.
*  - 자동으로 크기가 변경 된다.
*  - 
* 
*/

/*
*  int size 크기;
*  int capacity 수용량;
* 
* int arr = new int[5]; -> size(0) capacity(5)
* 
* size 6 = int[6]
* arr = new int[10];
* 
* resize();
* int size, capacity
*/
// value에 해당하는 타입을 T로 변환하세요.
#include <iostream>
template<typename T>  // int, double, string
class MyVector
{
private:
	int size;
	int capacity;
	T* vec;


public:
	// 생성자
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}
	// 소멸자
	~MyVector()
	{
		delete[] vec;
	}

	

	T& operator[](int idx)
	{
		return vec[idx];
	}
	void resize(int nsize)
	{
		// size : 현재 배열에 들어있는 원소의 숫자
		// nsize : 변경하려는 사이즈의 크기

		// 원소의 갯수를 재정의
		if (size < nsize)
		{
			size = size;
		}
		else
		{
			size = nsize;
		}

		// capacity 어떻게 변경할까?
		
		capacity = nsize;

		T* arr = new T[nsize];

		//vec[0], vec[1].... size 만큼
		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;  // 기존의 vec가 가리키고 있는 공간을 메모리 해제한다.

		vec = arr;     // vec가 새로운 공간을 다시 가리켜라.

		// delete[] arr;
 
	}
	void push_back(const T& element)
	{
		// capacity <= size
		if (capacity <= size)
		{
			capacity = capacity * 2; 
			resize(capacity);
		}

		vec[size] = element;

		size++;

	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;

		// if (size > 0)
		// {
		// 	size = size - 1;
		// }
		// else if (size == 0)
		// {
		// 	size = 0;
		// }
	}

	int Size() { return size; }

};
void test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);
		delete myVec;
	}
}

void test2()
{
	MyVector<int> vec(5);

	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);

		std::cout << vec[i] << " ";
	}

	vec.push_back(6);
	std::cout << std::endl;

	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << " ";
	}


	MyVector<double> vec2(5);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		vec2.push_back(i + 0.1);
		
		std::cout << vec2[i] << " ";
	}
}