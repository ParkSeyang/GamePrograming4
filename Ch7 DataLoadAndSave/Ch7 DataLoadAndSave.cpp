#include <iostream>
#include "GameModel.h"
#include <conio.h>
#include "DataHandler.h"
/* 경험치 테이블
* 1 레벨 - 100
* 1 레벨 - 100
* 1 레벨 - 100
* 4 레벨 - 150
* 5 레벨 - 150
* 
* 
*/

int main()
{
    Player player(0,100);  // exp(0), level(1), maxExp(10)

	Data data;
	data.SaveData("data.txt");
	data.loadData("data.txt");

	std::cout << "data의 level : " << data.level << std::endl;
	std::cout << "exp : " << data.exp << std::endl;


	int count = 0;
	while (true)
	{
		system("cls");
		player.GetExp(30);
		player.Show();
		_getch();
		count++;

		if(count >= 4)

		{
		  break;
		}
	}
   
	player.SaveData("data.txt");
}

