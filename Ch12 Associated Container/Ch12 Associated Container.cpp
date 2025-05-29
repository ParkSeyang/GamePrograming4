#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

#pragma region 커스텀 클래스를 set 넣는방법
struct Item
{
    int id;
    std::string name;

    Item() = default;
    Item(int id, std::string name) : id(id), name(name) {}

    bool operator<(const Item& other) const
    {
        return id < other.id;
    }

};


void Test3()
{
    std::cout << "커스텀 객체를 Set으로 출력하기 " << std::endl;
    std::set<Item> items;

    Item item1(1, "유리");
    Item item2(2, "김");
    Item item3(3, "바나나");
    Item item4(100, "칼");
    Item item5(5, "방패");


    items.insert(item1);
    items.insert(item2);
    items.insert(item3);
    items.insert(item4);
    items.insert(item5);


    std::cout << "중복을 허용 안함 " << std::endl;
    items.insert(Item(3, "투구"));

    for (const auto& item : items)
    {
        std::cout << item.id << " " << item.name << std::endl;
    }

    std::cout << "Set을 사용하면 데이터의 크기에 따라 자동으로 정렬한 결과를 얻을 수 있습니다." << std::endl;
    std::cout << "find 함수를 사용해서 빠르게 데이터를 찾을 수 있다." << std::endl;

 // item 전체를 items안에서 찾아야 한다.
 // item의 id가 n번인 데이터를 찾고 싶어요.
 // map을 사용하면 위의 문제점을 쉽게 해결 할 수 있다.

}
#pragma endregion

// set으로 데이터를 정렬 했을 때의 불편한 점, 그것을 개선한 map
// pair를 정의를 해야한다.

#pragma region Map 사용하기

void Test4()
{
    std::cout << "map 자료구조 사용하기" << std::endl;

    std::map<int, Item> items;

    // map의 데이터를 넣는 방법 (1) 중괄호로 사용
    // ex) {타입, 타입}

    items.insert({ 0, Item(100, "포션") });
    
    // (2) make_pair 함수 사용하기
    items.insert(std::make_pair(10, Item(1000, "롱소드")));

    // (3) pair 클래스를 직접 선언하기 (헤더가 필요 utility)

    std::pair<int, Item> p1(5, Item(101, "빨간 포션"));
    items.insert(p1);

    std::cout << "특징 1. map은 pair로 이루어진 데이터를 저장하는 컨테이너이다." << std::endl;
    std::cout << "특징 2. map의 key값으로 자동 정렬이 이루어 집니다." << std::endl;

    for (const auto& item : items)
    {
        std::cout << item.first << " " << " ID : " 
            << item.second.id << "이름 : " << item.second.name << std::endl;

    }


   
    std::cout << "특징3. 사전(Dictionary)형 자료 구조입니다." << std::endl;

    std::cout << items[0].id<< items[0].name<< std::endl;
}

#pragma endregion

#pragma region 연관 컨테이너를 실습한다.

struct NewItem
{
    std::string name;
    int ATK;
    int price;

    NewItem() = default;
    NewItem(std::string name, int ATK, int price) : name(name), ATK(ATK), price(price) {}

};


void Test5()
{
    std::map<std::string, int> map1;
    // 중괄호
    map1.insert({"김", 0});
    map1.insert({"알", 1});
    map1.insert(std::make_pair("다", 3));
    map1.insert(std::pair<std::string, int>("라", 3));
    // std::make_pair
    // std::pair<T1,T2>

    for (const auto& e : map1)
    {
        std::cout << "[";
        std::cout << e.first << " " << e.second;
        std::cout << "]" << " ";
    }
    
    std::cout << "김이라는 키우드에는 어떠한 숫자가 들어가 있습니까?" << map1["김"] << std::endl;

    std::map<int, int> map2;
    // 플레이어의 id번호(고유), 해당플레이어의 레벨
    // 레벨 -> user 타입으로 저장하면 user의 모든 정보를 id번호로 찾을 수 있다.
    map2.insert({0,10});
    map2.insert({5,100});
    map2.insert({ 100, 999 });
    map2.insert({ 25, 100 });
    std::cout << "map2 컨테이너 안에 선택한 키워드에는 어떠한 숫자가 들어있습니까?" << map2[100] << std::endl;
 
    std::map<std::string, NewItem> map3;
    map3.insert({"롱소드", NewItem("롱소드",50,100)});
    map3.insert({ "스파이", NewItem("스파이", 30, 75) });

   // std::cout << "map3를 사용해서 특정이름으로 아이템을 찾는 방법" << map3["롱소드"] << std::endl;

    std::cout << "만약에 map3안에 들어있는 이름이 롱소드인 데이터를 불러와줘" << std::endl;

    NewItem itemInstance = map3["롱소드"];
    std::cout << "이름 : " << itemInstance.name << " 공격력 : " << itemInstance.ATK <<" 가격 : " << itemInstance.price
        << std::endl;
    //void BuyItem(NewItem item) item가격, player돈 비교해서 구입한다.

}


#pragma endregion

#pragma region 상점 UI 및 기능 구현하기
// iomanip setw left

class Player
{
    int money;
public:
    Player(int money) : money(money) {}

    // 상점의 아이템을 획득했다.
    void BuyItems(NewItem item)
    {

    }
};


/*
* 상인이 많은 아이템을 팔고 싶다 . -> 아이템을 컨테이너 형태로 저장 해야한다.
* map을 사용해서 컨테이너 저장을 하겠다.
*/

class Shop
{
    // 1단계
    // 타입<int , NewItem> items 컨테이너를 선언하기
    std::map<int, NewItem> items;

public:
    

    Shop() = default;
    Shop()
    {
        // 2단계
        // 5개의 상점 데이터를 만들어서 넣어주세요
        // items.insert();
        items.insert({0,NewItem("자갈치",1,50)});
        items.insert({0,NewItem("양파",2,15)});
        items.insert({0,NewItem("대파",3,25)});
        items.insert({0,NewItem("명도잔월파",4,99999)});

    }

    void ShowItem()
    {
        std::cout << std::left;
        std::cout << std::setw(10) << "인덱스" << std::setw(10) << "이름" << std::setw(10) << "공격력" << std::setw(10) << "가격" << std::endl;
        for (const auto& item : items)
        {
            std::cout << std::left;
            std::cout << std::setw(10) << item.first << std::setw(20) << item.second.name << std::setw(10)<<item.second.ATK << std::setw(10) <<item.second.price<<std::endl;
        }
        
        
    }

    void SellItem()
    {
        // 3단계 
    }


};

void ShopTest()
{
    // 1. Item 데이터를 만든다.
    // 2. 정의한 데이터를 사용할 클래스.
    // 3. Shop클래스 안에 map 자료구조를 추가해보세요.
    // 4. items 데이터를 초기화 해주세요.

    std::cout << std::endl;

    Shop shop1;
    shop1.ShowItem();

}

#pragma endregion


int main()
{
    Test4();
    Test5();
}

