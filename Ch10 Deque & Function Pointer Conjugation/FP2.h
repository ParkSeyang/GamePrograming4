#pragma once
#include <iostream>
#include "ConsoleUtility.h"

// 저번수업시간 복습 계산기 기능 함수 포인터로 표현하기.

#pragma region // 심화 (1). 함수 포인터에 일반화 프로그래밍 (Generic Programming) 적용


template <typename T>
void Plus(T a, T b)
{
	std::cout << "더하기 결과 : ";
	std::cout << a + b << std::endl;
}

template <typename T2>
void Minus(T2 a, T2 b)
{
	std::cout << "빼기 결과 : ";
	std::cout << a - b << std::endl;
}

template <typename T3>
void Multiply(T3 a, T3 b)
{
	std::cout << "곱하기 결과 : ";
	std::cout << a * b << std::endl;
}

template<typename T4>
void Divide(T4 a, T4 b)
{
	std::cout << "나누기 결과 : ";
	std::cout << a / b << std::endl;
}

template<typename T>
void Calculate(void (*Func)(T a, T b), T outa, T outb)
{
	Func(outa, outb);

}

void FPTest()
{
	Calculate(Plus, 5, 6);
	Calculate(Plus, 5.5, 6.5);
	Calculate(Minus, 20, 10);
	Calculate(Multiply, 5, 5);
	Calculate(Divide, 2, 10);
}

#pragma endregion

#pragma region 심화(2). 열거형과 클래스로 함수포인터 활용

// - 변수 이름 규칙 -
// 열거형의 이름은 항상 대문자로 작성해서, 이름으로 타입을 알아볼 수 있게 설정한다.
// 함수는 첫글자가 대문자로 표현하게 설정한다.
enum ActorAction 
{
	MOVE,
	TALK,
	
};

class Actor
{
private:
	static void Move()
	{
		std::cout << "움직입니다." << std::endl;
	}

	static void Talk()
	{
		std::cout << "말하기" << std::endl;
	}

public:

	Actor() = default;

	void (*Action)();

	void Think()
	{
	  // 랜덤한 숫자를 받아서, 0이나오면 움직여라, 1이나오면 Talk, 2가나오면 ??
		int select = ConsoleUtil::GetRandomInt(2);

		ActorAction aaction = static_cast<ActorAction>(select - 1);

		switch (aaction)
		{
		case MOVE:
			Action = Move;
			break;
		case TALK:
			Action = Talk;
			break;
		default:
			std::cout << "잘못된 입력을 받아왔습니다." << std::endl;
			return;
		}
	}
};

void FPTest2()
{
	Actor actor;
	// 기능다듬기(기능추가)
	// actor.의사결정을 한다. Think
	// actor.ActionMove();
	// actor.Action();
	actor.Think();
	actor.Action();

}


#pragma endregion

#pragma region 가위바위보 예제 만들기

enum RPS_TYPE
{
	ROCK = 1,
	PAPER = 2,
	SCISSORS = 3,
};

class RPSGame
{
private:
	int wincount, winaicount = 0;


	// 함수 포인터 선언.
	void (*RPSAction)();
	// switch(RPS_TYPE) 각 타입에 맞게 함수 포인터의 함수를 넣는 코드를 만들어보세요.
	static void Rock()
	{
		std::cout << "플레이어 바위를 냈습니다." << std::endl;
	}
	static void Paper()
	{
		std::cout << "플레이어 보자기를 냈습니다." << std::endl;
	}
	static void Scissors()
	{
		std::cout << "플레이어 가위를 냈습니다." << std::endl;
	}

	RPS_TYPE usertype;
	RPS_TYPE AiramdomRPS;

	void Result()
	{
		// 유저와 컴퓨터가 같은선택을했다. : 비김
		// 유저 > 컴퓨터 : 이김
		// 그게아니면 졋다.

		std::cout << "결과를 확인합니다." << std::endl;

		if (usertype == AiramdomRPS)
		{
			std::cout << "비겼습니다." << std::endl;
		}
		else if (usertype == ROCK && AiramdomRPS == SCISSORS ||
			usertype == SCISSORS && AiramdomRPS == PAPER ||
			usertype == PAPER && AiramdomRPS == ROCK)
		{
			std::cout << "플레이어가 승리하였습니다!" << std::endl;
			wincount++; // 승리 횟수 추가
		}
		else
		{
			std::cout << "컴퓨터가 승리하였습니다!" << std::endl;
			winaicount++; // 컴퓨터 승리 횟수 추가
		}
		std::cout << "플레이어 승리 횟수 : " << wincount << std::endl;

		std::cout << "컴퓨터 승리 횟수 :" << winaicount << std::endl;
	}

public:
	RPSGame() : wincount(0), winaicount(0) {}

	void StartGame()
	{
		std::cout << "가위 바위 보 게임을 시작합니다." << std::endl;
		
		while (true)
		{
			std::cout << "플레이어가 선택할 번호를 선택하세요." << std::endl;
			std::cout << "1. 바위, 2. 보, 3.가위 " << std::endl;

			int input = 0;
			std::cin >> input;
			usertype = static_cast<RPS_TYPE>(input);
		
			switch (input)
			{
			case 1:
				RPSAction = Rock;
				break;
			case 2:
				RPSAction = Paper;
				break;
			case 3:
				RPSAction = Scissors;
				break;

			}	

			// 컴퓨터가 선택할 번호를 랜덤으로 받습니다.
			int aiChoise = ConsoleUtil::GetRandomInt(3);
			AiramdomRPS = static_cast<RPS_TYPE>(aiChoise);
			// switch문을 사용합니다. 함수포인터를 결정합니다.
			std::cout << "컴퓨터가 행동을 선택중입니다." << std::endl;
			Sleep(300);
			switch (AiramdomRPS)
			{
			case ROCK:
				std::cout << "컴퓨터가 바위를 냈습니다." << std::endl;
				break;
			case PAPER:
				std::cout << "컴퓨터가 보자기를 냈습니다." << std::endl;
				break;
			case SCISSORS:
				std::cout << "컴퓨터가 가위를 냈습니다." << std::endl;
				break;
			default:
				std::cout << "잘못된 입력을 받았습니다." << std::endl;
				return;
			}
			// 함수포인터의 함수를 실행합니다.
			RPSAction();
			Result();

			if (wincount >= 3 || winaicount >= 3)
			{
				std::cout << "게임을 종료합니다." << std::endl;
				break;
			}
		}

		if (wincount >= 3)
		{
			std::cout << "유저가 승리하였습니다!" << std::endl;
		}
		else if (true)
		{
			std::cout << "컴퓨터가 승리하였습니다!" << std::endl;
		}

	}

	void FPTest3()
	{
		RPSGame game;
		game.StartGame();
	}
	

};
#pragma endregion
