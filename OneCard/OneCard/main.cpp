#include <iostream>
#include "Card.h"

int main(){
    // Card Spade1 = Card(1, SPADE);
    // Spade1.ShowGraphic();
    // Card DiamondJ = Card(11, DIAMOND);
    // DiamondJ.ShowGraphic();
    // Card HeartQ = Card(12, HEART);
    // HeartQ.ShowGraphic();
    // Card CloverK = Card(13, CLOVER);
    // CloverK.ShowGraphic();
    // Card BJoker = Card(-1, -1, BLACK);
    // BJoker.ShowGraphic();
    // Card CJoker = Card(-1, -1, COLOR);
    // CJoker.ShowGraphic();

    for (int i = 0; i < 13; i++){
        for (int j = SPADE; j <= CLOVER; j++){
            Card(i + 1, j, NOT).ShowGraphic();
        }
    }

    Card(-1, -1, BLACK).ShowGraphic();
    Card(-1, -1, COLOR).ShowGraphic();
}