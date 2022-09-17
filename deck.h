#ifndef DECK_H
#define DECK_H

#include "card.h"

using namespace std;

class Deck
{
private:
    int cardIndex;
    Card deck[52];
    const int DECK_SIZE = 52;
public:
    Deck();
    bool empty();
    void shuffle();
    friend ostream& operator<<(ostream& outs, const Deck& deck);
    Card dealCard();
    Card getCardAt(int index);
};

#endif // !DECK_H
