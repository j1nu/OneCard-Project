#ifndef _CARD_H
#define _CARD_H

enum {SPADE, DIAMOND, HEART, CLOVER};
enum {NOT, BLACK, COLOR};

class Card {
    private :
        const int num;
        int symbol;
        const int joker;
    public :
        Card(const int, const int, const int newJoker = NOT);
        // Card(const Card &copy);
        ~Card();

        // Card operator= (const Card &ref);

        int getNum() const;
        int getSymbol() const;
        int getJoker() const;
        void setSymbol(const int);
        //멤버 변수 접근 함수

        void Initialize(Card** &ref);
        void ShowInfo();
        void ShowGraphic() const;
        //카드 모습 보여주는 함수
};

#endif

