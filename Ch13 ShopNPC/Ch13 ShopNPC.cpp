#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"
#include <fstream>   // ifstream(데이터를 읽는 함수), ofstream(데이터를 보내는 함수)
#include <iomanip>   // 입출력 조작 헤더
#include <utility>   // pair 클래스가 정의되어있다.

using std::cout;
using std::cin;
using std::endl;
using std::string;


/* 오늘의 목표
* 1. 콘솔 창에서 플레이어를 움직인다.
* 2. 특정 위치에 상점 NPC와 조우할 때 상점의 항목을 보여준다.
* 3. 상점을 이용한다.
* 
* Game Object : Player, NPC, Shop
* 자료구조. Item 어떠한 컨테이너에 보관하여 사용할 것인가?
* File Input & Output 메모장에 있는 데이터를 NPC에 전달하는 기능.
* 
* 오늘할 과정
* 클래스 구현 -> 테스트 -> 헤더 옮기기
*/

const int total_width = 60;      // 전체
const int field1_width = 30;     // 이름 길이
const int field2_width = 15;     // 가격
const int field3_width = 15;     // 타입


#pragma region 상점 코드
class Item
{
public:

    std::string name;
    int price;
    std::string type;

public:
    Item() = default;
    Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}

};

#pragma region Player 코드

class Player
{
public:
    // 좌표, 돈
    int posX, posY, money;

    // 오늘의 과제
    // 1.플레이어가 소유한 인벤토리를 자료구조를 한가지 선택해서. 그 자료구조에 구매한 아이템을 저장해보세요.
    // 2.저장한 자료구조를 사용하는 함수를 만들면 됩니다.

    Player() = default;
    Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

    // Shop 코드와 연동을 해서.. money , shop.items[i].price 비교 money -=price;
    // 인벤토리 (어떤 컨테이너를 선택하면 좋을까?)   shop -> player.inventory

    // 좌상단의 플레이어 UI 띄우기.
    void ShowPlayerUI()
    {
        ConsoleUtil::GotoXY(50, 5);
        cout << "플레이어의 정보" << endl;
        ConsoleUtil::GotoXY(50, 6);
        cout << "돈 : " << money;

        // (2) 보유한 아이템...

    }

    void BuyItem(Item& item)
    {
        money -= item.price;

        // vector.push_back(item);
        // map.insert(?, item); // 아이템의 이름으로 검색할 수 있게 map<string, item>
        // unordered_map<string,item>

    }

    // 현재 플레이거 가지고 있는 아이템 정보를 저장.
    // 게임종료
};

#pragma endregion


class Shop
{
private:
    std::map<int, Item> items;  // 자료구조 클래스를 보관한다.

public:
    Shop()  // 데이터를 초기화 한다.
    {
        items.insert({ 0, Item("심판의철퇴", 275, "무기") });
        items.insert(std::make_pair(1, Item("망자의갑옷", 175, "방어구")));
        std::pair<int, Item> p1(2, Item("회복물약(대)", 45, "소비아이템"));
        items.insert(p1);
        items.insert({ 3, Item("정령의목걸이", 160, "악세서리") });
        items.insert({ 4, Item("둔화의물약", 34,"소비아이템") });

    }

    Shop(string filename)
    {
        LoadShopData(filename);
    }

    void SaveShopData(string filename)
    {
        std::ofstream out_file;
        out_file.open(filename);

        string name;
        int price;
        string type;

        if (!out_file)
        {
            std::cerr << "파일을 여는데 실패 했습니다." << endl;
            std::exit(1);
        }

        for (int i = 0; i < items.size(); i++)
        {
            out_file << std::setw(field1_width) << std::left << items[i].name
                << std::setw(field2_width) << std::right << items[i].price
                << std::setw(field3_width) << std::right << items[i].type
                << endl;
        }

        out_file.close();
    }

    void LoadShopData(std::string filename)
    {
        std::ifstream in_file;
        in_file.open(filename);

        string name;
        int price;
        string type;

        if (!in_file)
        {
            std::cerr << "파일을 여는데 실패 했습니다." << endl;
            std::exit(1);
        }

        int index = 0;

        while (!in_file.eof())  // end of file (파일의 끝에 도달했을 때 true 반환)
        {
            in_file >> name >> price >> type;                 // 파일에서 name, price, type 읽기
            items.insert({index, Item(name, price, type) });  // map 자료구조에 저장
            index++;                                          // 다음 index 넘어가기
        }
        

        in_file.close();
    }



    // 데이터를 사용하여 기능을 구현한다.
    void ShowItems(int x, int y)
    {
        std::string headersize = "           Shop UI 시스템판             ";
        // 아이템의 머릿말
        std::cout << headersize << std::endl;

        ConsoleUtil::GotoXY(x, y); // 원하는 위치에 상점 UI를 추가할수있다.

        cout << std::setw(field1_width) << std::left << "이름"
            << std::setw(field2_width) << std::right << "가격"
            << std::setw(field3_width) << std::right << "타입"
            << endl;
      
        ConsoleUtil::GotoXY(x, y + 1);
       // 라인을 긋는 방법
            cout << std::setw(total_width)  // 길이 설정
            << std::setfill('-')        // 공백을'-'로 설정
            << ""                       // 길이 설정2
            << endl;

        cout << std::setfill(' ');      // 기존 버젼으로 리셋

        // 이 반복문은 인덱스 기반 접근이 가능한 자료구조여야 한다. ex) vector, map...
        // 아이템을 출력하라.

        for (int i = 0; i < items.size(); i++)  
        {
            ConsoleUtil::GotoXY(x, y + 2 + i);
            cout << std::setw(field1_width) << std::left << items[i].name
                << std::setw(field2_width) << std::right << items[i].price
                << std::setw(field3_width) << std::right << items[i].type
                <<endl;
        }
        // for (const auto& elem : items)
        // {
        // 
        // }
    }

    // 아이템을 판매한다. (플레이어가 돈이 없으면.. 아이템을 구매하지 못한다.)
    bool BuyItem(int index, Player& player)
    {
        if (items.find(index) != items.end())  // 해당하는 아이템을 찾았다.
        {
            Item itemInstance = items[index];

            if (player.money >= itemInstance.price)  // 플레이어가 소지금이 충분할 때
            {
                player.BuyItem(itemInstance);

                return true;
            }
            else if (player.money < itemInstance.price)  // 플레이어가 소지금이 부족할때
            {
                cout << "소지금이 부족합니다." << endl;

                return false;
            }
            
        }

    }

    void Interact(Player& player)
    {
        int select;
        cout << "번호를 입력하여 아이템을 구매할 수 있습니다." << endl;
        cin >> select;

        BuyItem(select, player);

    }
};

#pragma endregion

#pragma region NPC 코드
// 상인이 존재하는 위치에 플레이어가 도달했을 때 이 아이템을 보여주세요.

class NPC
{
private:
    Shop shop;
public:
    int posX;
    int posY;

    bool isActivate;

    NPC() = default;
    NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY), isActivate(true)
    {
        shop = Shop(filename);
    }

    void ShowItems(int x, int y)
    {
        shop.ShowItems(x, y);
    }

   void ChangeItemList(string filename)
   {
       shop = Shop(filename);
   }

    void ShowNPC()
    {
        ConsoleUtil::GotoXY(posX, posY);
        std::cout << "$";
    }

    void Interact(Player& player)
    {
        shop.Interact(player);
        isActivate = false;
    }


};

void Interact(Player&player, NPC& npc, int UI_X, int UI_Y)  // Player, NPC
{
    if (player.posX == npc.posX && player.posY == npc.posY)
    {
        if (!npc.isActivate)  // == (npc.isActivate == false) 같은 조건입니다.
        {
            return;   // 상점이 비활상화 되면 사용 불가능
        }
        npc.ShowItems(UI_X, UI_Y);
        npc.Interact(player);
    }
}


#pragma endregion


int main()
{
    ConsoleUtil::SetCursorVisible(false);

    Player player(10, 10, 500);  // 플레이어의 시작 설정


    // int playerX = 10;
    // int playerY = 10;

    NPC npc1("shop1.txt", 3,5);
    NPC npc2("shop2.txt", 10,2);
    NPC npc3("shop3.txt", 8,6);


  //  shop.SaveShopData("shop3.txt");

    while(true)
    {
  
        // 입력을 받았을 때 좌표가 변하는 코드
        
        if (_kbhit())
        {
            system("cls");

            if (GetAsyncKeyState(VK_UP))
            {
                player.posY--;
                if (player.posX <= 0)
                {
                    player.posY = 0;
                }
               
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                player.posY++;
            }

            if (GetAsyncKeyState(VK_LEFT))
            {
                player.posX--;
                if (player.posX <= 0)
                {
                    player.posX = 0;
                }
               
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                player.posX++;
            }
        }


        player.ShowPlayerUI();

        // 상인이 존재하는 위치에 플레이어가 도달했을 때 이 아이템을 보여주세요.

        npc1.ShowNPC();
        npc2.ShowNPC();
        npc3.ShowNPC();

        Interact(player, npc1, 0, 10);
        Interact(player, npc2, 0, 10);
        Interact(player, npc3, 0, 10);

        ConsoleUtil::GotoXY(player.posX, player.posY);
        std::cout << "a";
        
        _getch();  // 유저의 입력을 받는 코드
    }
    
}


