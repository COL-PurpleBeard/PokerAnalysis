#ifndef CARD_HAND_H
#define CARD_HAND_H

#include "card.h"
#include "deck.h"

using namespace std;

class CardHand
{
public:
    vector<Card> hand;
    //public:
    CardHand();
    ~CardHand();
    void giveCard(Deck& theDeck);
    Card getCardAt(int index);
    vector<Card> getHand() const;
    friend ostream& operator<<(ostream& outs, CardHand& theHand);
};

#endif // CARD_HAND_H


