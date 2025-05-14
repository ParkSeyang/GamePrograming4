// 자료 구조
// - 일반화 프로그래밍 (Generic Programming)
// - 일반적이다? : 어떤 타입이든 모두 사용할 수 있는 범용적인 코드
//
//
// 변수들을 T,N,Q 선언할 것인데, 컴퓨터가 어떠한 형태인지 알 수 있도록
// 키워드를 사용해야 한다.

// @ 과거에는 어떻게 일반화 프로그래밍을 했을까?
// - macro로 일반화 프로그래밍 작성하는 것은 지양합니다.
// - 컴파일 체크를 지원하지 않는다

/*
*
* 
* Legacy 코드를 읽고, 옛날 코드임을 인지할 수 있는 것.
* 단점1. 의도하지 않은 결과가 발생할 수 있다.
* 단점2. 컴파일 체크를 지원하지 않는다.
*/

/*
* 컴파일 타임(Compile time) : 컴파일하는 시점. 컴퓨터가 언어를 번역해서 전달하는 시점 오류를 검증하는 단계를 거친다.
* 런타임 (run time) : 프로그램이 시작하는 시점. 
* 
*/

/*
* template 키워드
* <Type지정  변수의 이름>
* 타입 자체를 받아오는 키워드 : typename, class
*/

/*
* 타입 추론 : 컴파일러가 앞 뒤 코드를 보고, 명시되지 않은 타입을 유추하는 것
* 
* auto 이름 = 10;
* 
* 선언한 함수 위에 template 키워드를 사용하여 일반화 함수
* 함수 template
* 
* 클래스 위에 template<> 사용하여 일반화 클래스.
* template 클래스
* 
* 자료 구조. STL
* 대부분이 템플릿 클래스로 구현되어 있다.
*/

#define Max(a,b) ((a>b) ? a:b)
#define Square(a) a * a
#include <iostream>
#include <array>     // #include <컨테이너 이름>


template<typename T1>
//template<class T1> 으로도 사용가능
T1 Maxfunc(T1 a, T1 b)
{
    return (a > b) ? a : b;
}
template<typename T1, typename T2>
void Func(T1 a, T2 b)
{
    std::cout <<  "No."<< a << " "
        << b << std::endl;
}
template<int N>
void Func2()
{
    std::cout << N << std::endl;
}

template<int N, typename T>
void Func3()
{
    for (int i = 0; i < N; i++)
    {
        std::cout << typeid(T).name() << std::endl;
    }
    
}

template<class T3>
T3 Min(T3 a, T3 b)
{
    return (a < b) ? a : b;
}
template<typename T4>
T4 Mulitply(T4 a, T4 b)
{
    return a * b;
}

struct person
{
    int age;
    std::string name;

    bool operator<(const person& other)
    {
        return this->age < other.age;
    }
};

// int sums[10]; sums[0]

// 우리가 직접 만든 person클래스에 접근하는 객체를 만들었따.
// person을 조작하는 함수들을 정의한 코드이다.
// 보편적으로 사용하는 데이터를 다루는 클래스입니다.
// Standard template 라이브러리
// class 기본적으로 private 필드에 선언되어 있다.
// struct 기본적으로 pubilc 필드에 선언되어 있다.

template<int N>
class People //
{
private:

    int size = N;          // N의 크기를 일반화 하고 싶다.
    person HumanInCity[N];

    // 연산자 오버로딩을 통해서 배열 기능을 흉내내보기.
public:
    person& operator[](int index)
    {
        return HumanInCity[index];
    }

    void at(int index)
    {
        // person 배열의 n번째에 접근하는 기능
        std::cout << " 나이 : " << HumanInCity[index].age
            << " " << "이름 : " << HumanInCity[index].name << std::endl;
    }
};
template<int N, typename T>
class Array
{
private:
    int size = N;
    T value[N];
public:
    T& operator[](int index)
    {
        return HumanInCity[index];
    }

    T at(int index)
    {
        // person 배열의 n번째에 접근하는 기능
       return value[index]
    }
};
/*
* Min 함수.
* Mulitply 함수  <- 각 두개의 매개 변수를 서로 곱하는 함수를 만들어보시오
*/


/*
* 자료 구조에 공부해야할 것 : 코드를 작성할 때 가장 효율적인 자료구조가 무엇인가?
* 데이터 선언.
* 데이터를 저장, '배열' -> 크기가 고정되어 있는 컨테이너
* 컨테이너 마다 장단점이 존재합니다.
* 
* 배열의 장점과 단점
* 특징 : 크기가 고정되어 있다.
* 장점 : 정해져 있는 규칙을 문법적으로 제한할 수 있다. 빠르다.
* 단점 : 배열의 크기를 변경할 때 드는 비용이 크다.
*/

void Ex1()
{
    int result1 = Max(5, 1); // ((5>1)?5:1)
    double result2 = Max(1.1, 2.2); // ((1.1 > 2.2)? )

    int result3 = 100 / Square(5);  // 100 / 5 * 5

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
    std::cout << result3 << std::endl;

    std::cout << Maxfunc<int>(1.0, 2.2) << std::endl;
    std::cout << Maxfunc<double>(1.0, 2.2) << std::endl;

    // 타입 추론 : 완벽하게 작동하지는 않는다.
    std::cout << Maxfunc(1.2, 2.4) << std::endl;

    std::cout << Maxfunc(0.1, 0.2) << std::endl;

    Func<int, std::string>(1, "피카츄");

    Func2<155>();

    Func3<5, int>;

    // Min template 예제, Multiply template 예제

    std::cout << "Min 예제\n" << std::endl;
    std::cout << Min(1.1, 2.4) << std::endl;
    std::cout << Min(1, 2) << std::endl;
    std::cout << Min('a', 'b') << std::endl;

    std::cout << "Multiply 예제\n" << std::endl;
    std::cout << Mulitply(1, 5) << std::endl;
    std::cout << Mulitply(1.1, 2.2) << std::endl;

    Func3<3, int>();
}  

int main()
{
    Ex1(); // 함수 템플릿 예제

    // 보충 예제
    person p1{ 10,"A" };
    person p2{ 20,"B" };

    person p3 = Min<person>(p1, p2);

    std::cout << p3.name << "나이가 더 어리다." << std::endl;

    People<5> busan;
    busan[0] = { 15, "이순신" };
    busan.at(0);
    busan[1] = { 20, "강감찬" };

    std::cout << "직접 만든 배열 클래스 예제" << std::endl;

    Array<10, person> seoul;
    seoul[0] = { 13, "장보고" };
    seoul.at(1) = { 15, "고주몽" };

    // 배열 형태의 문법 (syntax)
    std::cout << seoul[0].name << std::endl;
    std::cout << seoul[1].name << std::endl;

    // 배열 클래스 형태의 문법
    std::cout << seoul.at(0).name << std::endl;
    std::cout << seoul.at(1).name << std::endl;

 

}