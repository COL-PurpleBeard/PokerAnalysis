#include "card.h"
#include "cardHand.h"

using namespace std;


CardHand::CardHand()
{
    hand.reserve(5);
}

CardHand::~CardHand()
{
    hand.clear();
}

void CardHand::giveCard(Deck& theDeck)
{
    Card temp = theDeck.dealCard();
    hand.push_back(temp);
}

Card CardHand::getCardAt(int index)
{
    return hand.at(index);
}

vector<Card> CardHand::getHand() const
{
    return hand;
}

ostream& operator<<(ostream& outs, CardHand& theHand)
{
    for (int i = 0; i < theHand.hand.size(); i++)
    {
        outs << theHand.getCardAt(i) << " ";
    }
    return outs;
}