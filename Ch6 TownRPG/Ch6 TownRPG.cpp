#include <iostream>
#include "GameModel.h"

/*
* GameModel 만든 기능을 테스트 합니다.
* BattleManager - Player, Monster
*/

int main()
{
    Player player(100, 10);
    Monster monster(80, 5);

    // BattleManager battlemanager(player, monster); battlemanager.Battle()

    // 체력이 0보다 크면 반복해라. -> while문 탈출 조건을 먼저 작성해라.
    
    while (player.getHealth() > 0 && monster.getHealth() > 0)
    {
        player.attack(monster);
        if (monster.getHealth() > 0)
        {
            monster.attack(player);
        }
    }

    std::cout << "전투가 종료 되었습니다." << std::endl;
}

