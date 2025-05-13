#pragma once


#include <iostream>

// 템플릿을 활용한 더하기 함수 예제

// 함수 오버로딩을 활용해서 실수를 더할수있는 함수를 만들어보자.

// 코인 현재 보유 코인, 추가된 코인
// 1/2 코인이 생겼다.
// 일반화된 코드로 만들면 유지 보수, 가독성에 좋지 않을까?

// T가 int, double, char
// <>

template <typename T>
T Add(T a, T b)
{
	return a + b;
}
