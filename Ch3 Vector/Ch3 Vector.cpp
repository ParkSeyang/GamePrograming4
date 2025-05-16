/*
* 목표 : 배열의 크기를 수동으로 변경하는 코드를 만든다.
*		자동 "Vector"
*/

/*
* int 10개 배열로 저장한다.
* 배열의 특징 : 크기가 고정. 만들 때 크기를 정해줘야 한다. 40바이트의 공간을 확보해야한다.
* 41바이트 떨어진 공간에서 메모리를 접근 -> 문제가 발생.
* 
*/

// 배열의 크기를 N 받을 수 있게 코드를 추가해보기.
// string, char, double 코드를 추가해보세요

/* 
* @ 벡터의 특징 @
* - vector 배열은 first in Last out 방식으로 맨처음들어온 데이터가 맨마지막에 제거됩니다.
*  vector 클래스의 기능
* 
* 
* push_back()    : 백터의 끝에 데이터를 추가한다.(이미 존재 하는 데이터를)
* size()         : 벡터의 길이를 반환한다.
* emplace_back() : 벡터의 끝에 직접 생성한 데이터를 바로 추가한다.
* pop_back()     : 가장 뒤에 있는 데이터를 한개 제거한다.
* empty()        : 벡터의 크기가 0이면 true, 0 이상이면 false 를 반환한다.
* insert()       : 주어진 위치에 데이터를 입력한다.   vec.insert(vec.begin() + 2, 10);
* erase()        : 주어진 위치의 데이터를 제거한다.    vec.erase(vec.begin());
* 
*/


#include <iostream>
#include <vector>

using namespace std;

template<typename T,int N>
void MakeArray(T *& ptr, T value)
{
	// 연결된 메모리를 해제
	// 배열의 크기를 수동으로 만들고 보여주는 예제 코드
	delete[] ptr;

	ptr = new T[N];

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}
	cout << endl;
}
// 클래스 이름 Monster 번호, 이름


class Monster
{
private:
	int num;
	string name;
public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : num(num), name(name) {}

	int get_num() const { return num; }
	string get_name() const { return name; }

	// cout << monster 출력 했을때의 오류
	// friend 외부 클래스의 private에 접근할 수 있게 해주는 키워드
	friend ostream& operator<<(ostream& os, const Monster& obj)
	{
		os << obj.num << " " << obj.name << " ";
		return os;
	}
};
template<typename T>
void Show(vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	// 수동으로 배열의 크기를 변경하고 생성하는 함수 템플릿
	// 클래스 템플릿

    int* aPtr = new int[10];
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample(0, "고블린");

	MakeArray<int,10>(aPtr, 0);
	MakeArray<double, 10>(bPtr, 0.1);
	MakeArray<string, 10>(cPtr, "A");
	MakeArray<Monster, 10>(dPtr, sample);

	// vector로 쉽게 배열을 생성하고 출력하기.
	cout << "벡터 사용 예제" << endl;
	// vector int를 저장하는 가변배열 클래스
	vector<int> nums;
	vector<double> nums2;
	vector<string> name;

	// push_back : 벡터의 끝에 데이터를 추가한다.
	nums.push_back(1);   
	nums.push_back(2);   
	nums.push_back(3);   

	// emplace_back() :

	// pop_back() : 벡터에 삽입된 데이터를 맨 뒤에서부터 하나씩 제거한다 
	// 
	// clear() : 모든 데이터를 지워줍니다.
	vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "고블린");
	monsterDatabase.emplace_back(2, "슬라임");
	monsterDatabase.emplace_back(3, "골렘");

	monsterDatabase.clear();

	Show<Monster>(monsterDatabase);
	// empty() : 
	if (!monsterDatabase.empty())
	{
		cout << "데이터가 있습니다." << endl;
	}

	// insert()


	for (int i = 0; i < 10; i++)
	{
		nums.push_back(0);
		nums2.push_back(1.1);
		name.push_back("AAA");
		monsterDatabase.push_back(sample);
	}

	// size() : 벡터의 길이를 반환한다.

	Show<int>(nums);
	Show<double>(nums2);
	Show<string>(name);
	Show<Monster>(monsterDatabase);

}

