#include <iostream>
#include"ConsoleUtility.h"
#include <conio.h>   // _getch
#include <array>     
#include "Pokeball.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

void Example()
{
	for (int i = 0; i < 10; i++)
	{
		int sum = ConsoleUtil::GetRandomInt(20);
		std::cout << sum << std::endl;
		Sleep(200);
		if (sum >= 10)
		{
			std::cout << "승리하였습니다." << std::endl;
		}
		else
		{
			std::cout << "패배하였습니다." << std::endl;
		}
	}
}

template<int N>
void Display(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			std::cout << "▣ ";
		}
		else
		{
			std::cout << "□ ";
		}
	}
	
}

template<int N>
void Display2D(int index)
{
	int height = index / N;   // 세로
	int width = index % N;    // 가로
	// 코드 감싸기 단축키 
	// Ctrl + K + S
	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				std::cout << "▣ ";
			}
			else
			{
				std::cout << "□ ";
			}

		}
		cout << endl;
	}

}

/*
* std:: array (고정 배열) Fixed size Array
* - 특징 : 크기가 고정되어 있고, 규칙을 명확히 표현할 수 있다.
* - 의문 : 크기를 변경할 수 있는 배열로 만들면 되지 않을까? -> vector (가변 배열)
*/


int main()
{
	int selectedIndex = 0;
	
	char input;
	// 키보드 상하 좌우 입력을 받아서 아이템을 선택하는 그림 출력
	
	// 포켓 몬스터의 데이터를 세팅

	// PokeMon (값타입) : 데이터 복사, 크기가 작은 경우. 값 자체가 상태를 표현할 때.
	// PokeMon* (참조 타입, 주소값) : 복사를 안하고 데이터를 가져온다.

	// 몬스터의 종류가 많고 크기가 크다. -> PokeMon* 참조타입을 사용한다.
	// 몬스터 볼 갯수가 적고, 상태가 존재하기 때문에 값으로 표현

	ConsoleUtil::SetCursorVisible(false);

	std::array<PokeMon*, 36> pokeballs;
	
	PokeMon defaultMonster(0, "없음");

	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "이상해씨");
	pokeballs[1] = new PokeMon(2, "파이리");
	pokeballs[2] = new PokeMon(3, "꼬부기");
	pokeballs[3] = new PokeMon(4, "토게피");

	while (true)
	{
		const int size = 6;

		int sizePow = size * size;
		ConsoleUtil::GotoXY(0, 0);
		Display2D<size>(selectedIndex); // 현재 선택한 아이템을 보여주는 Display함수를 만든다

		if (_kbhit())
		{
			input = _getch();

			if (input == LEFT)
			{
				//std::cout << "왼쪽 화살키를 입력" <<std::endl;
				selectedIndex = (selectedIndex - 1 + sizePow) % sizePow; // 0 ~ 5
			}
			else if (input == RIGHT)
			{
				selectedIndex = (selectedIndex + 1) % sizePow;
			}
			else if (input == UP)
			{
				selectedIndex = (selectedIndex - size + sizePow) % sizePow;
			}
			else if (input == DOWN)
			{
				selectedIndex = (selectedIndex + size) % sizePow;
			}
			else if (input == ENTER)
			{

				break;
			}
			// 화면 지우기
			system("cls");
		}
		// std::cout << selectedIndex << std::endl;
		ConsoleUtil::GotoXY(30, 0);
		cout << "몬스터 UI";
		ConsoleUtil::GotoXY(30, 1);
		cout << "No." << pokeballs[selectedIndex]->get_number() << pokeballs[selectedIndex]->get_name() << endl;
	}

	cout << pokeballs[selectedIndex]->get_name() << endl;
}

