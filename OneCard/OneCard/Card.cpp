#include <iostream>
#include "Card.h"

// #define debug
#define PRINT_RED(str) "\033[31m"<<#str<<"\033[0m"
//빨간색으로 출력해주는 매크로 , 사용법 : cout << PRINT_RED(str);

using std :: cout;
using std :: cin;
using std :: endl;

Card :: Card(const int newNum, const int newSymbol, const int newJoker) : num(newNum), symbol(newSymbol), joker(newJoker){ 
    #ifdef debug
        cout << "Card 생성자 호출 : " << newNum << ", " << newSymbol << ", " << newJoker << endl;
    #endif //디버그용 코드
}
//Card 생성자 : Card(숫자, 문양, 조커색깔)

Card :: ~Card(){
    #ifdef debug
        cout << "Card 소멸자 호출 : " << num << ", " << symbol << ", " << joker << endl;
    #endif //디버그용 코드
}
//Card 소멸자

int Card :: getNum() const{
    return num;
} //카드 숫자 리턴
int Card :: getSymbol() const{
    return symbol;
} //카드 문양 리턴
int Card :: getJoker() const{
    return joker;
} //조커 여부 리턴
void Card :: setSymbol(int newSymbol){
    symbol = newSymbol;
} //문양 바꾸기 : 7 냈을 때


// void Card :: Initialize(Card** &ref){
//     for (int i = SPADE; i <= CLOVER, i++){
//         for (int j = 0; j < 13; j++){
//             ref[i][j] = Card(j + 1, i, NOT);
//         }
//     }
//     ref[4][0] = Card(-1, -1, BLACK);
//     ref[4][1] = Card(-1, -1, COLOR);
// }

void Card :: ShowGraphic() const{
    cout << " ----------- " << endl;
    if (joker == NOT){ //조커가 아닌 그냥 카드일 때
        switch (num){
            case 1 :
                cout << "|A          |" << endl;
                break;
            case 10 :
                cout << "|10         |" << endl;
                break;
            case 11 :
                cout << "|J          |" << endl;
                break;
            case 12 :
                cout << "|Q          |" << endl;
                break;
            case 13 :
                cout << "|K          |" << endl;
                break;
            default :
                cout << "|" << num << "          |" << endl;
                break;
        }
        switch (symbol){
            case SPADE :
                cout << "|♠          |" << endl;
                break;
            case DIAMOND :
                cout << "|" << PRINT_RED(◆) << "          |" << endl;
                break;
            case HEART :
                cout << "|" << PRINT_RED(♥) << "          |" << endl; 
                break;
            case CLOVER :
                cout << "|♣          |" << endl;
                break;
        }
        cout << "|           |" << endl;
        switch (symbol){
            case SPADE :
                cout << "|     ♠     |" << endl;
                break;
            case DIAMOND :
                cout << "|     " << PRINT_RED(◆) << "     |" << endl;
                break;
            case HEART :
                cout << "|     " << PRINT_RED(♥) << "     |" << endl; 
                break;
            case CLOVER :
                cout << "|     ♣     |" << endl;
                break;
        }
        cout << "|           |" << endl;
        switch (symbol){
            case SPADE :
                cout << "|          ♠|" << endl;
                break;
            case DIAMOND :
                cout << "|          " << PRINT_RED(◆) << "|" << endl;
                break;
            case HEART :
                cout << "|          " << PRINT_RED(♥) << "|" << endl; 
                break;
            case CLOVER :
                cout << "|          ♣|" << endl;
                break;
        }
        switch (num){
            case 1 :
                cout << "|          A|" << endl;
                break;
            case 10 :
                cout << "|         10|" << endl;
                break;
            case 11 :
                cout << "|          J|" << endl;
                break;
            case 12 :
                cout << "|          Q|" << endl;
                break;
            case 13 :
                cout << "|          K|" << endl;
                break;
            default :
                cout << "|          " << num << "|" << endl;
                break;
        }        
    }
    else if (joker == BLACK){ //흑백조커일 때
        cout << "|JOKER      |" << endl; 
        cout << "|           |" << endl;
        cout << "|           |" << endl;       
        cout << "|     ☺     |" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|      JOKER|" << endl;
    }
    else if (joker == COLOR){ //칼라조커일 때
        cout << "|" << PRINT_RED(JOKER) << "      |" << endl; 
        cout << "|           |" << endl;
        cout << "|           |" << endl;       
        cout << "|     " << PRINT_RED(☻) << "     |" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|      " << PRINT_RED(JOKER) << "|" << endl;
    }
        
    cout << " -----------" << endl;
    //☺☻
}
