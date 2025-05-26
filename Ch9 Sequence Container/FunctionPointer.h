#pragma once

#include <iostream>

/*
* 1단계 함수 선언 ((반환 값) (*호출할함수 이름)() )
* 2단계 호출한 함수의 인자가 있는 경우
* - 함수선언 ((반환값)(*호출할함수이름)(타입 이름, 타입 이름), 타입 이름, 타입 이름)
* 
*/

void Add(int a, int b)
{
	std::cout << "더하기 실행" << std::endl;
	std::cout << 1 + 2 << std::endl;
}

void Minus(int a, int b)
{
	std::cout << "빼기 실행" << std::endl;
	std::cout << 1 - 2 << std::endl;
}

// 곱하기와 나누기
void Multiply(int a, int b)
{
	std::cout << "곱셈 실행" << std::endl;
	std::cout << a * b << std::endl;
}

void Divide(int a, int b)
{
	std::cout << "나눗셈 실행" << std::endl;
	std::cout << a / b << std::endl;
}



void Calculate(void (*Func)(int aa, int bb), int a, int b)
{
	Func(a,b);
}

void Test()
{
	// 더하기
	Calculate(Add, 50, 50);
	// 빼기
	Calculate(Minus, 100, 50);
	// 곱하기
	Calculate(Multiply, 2 , 10);
	// 나누기
	Calculate(Divide, 25, 100);
}