#include "deck.h"

using namespace std;

Deck::Deck() : cardIndex(0)
{
    for (int i = 0; i < 13; i++)
    {
        Card temp;
        temp.setRank(i + 2);
        temp.setSuit("Diamonds");
        deck[i] = temp;
    }

    for (int i = 0; i < 13; i++)
    {
        Card temp;
        temp.setRank(i + 2);
        temp.setSuit("Hearts");
        deck[i + 13] = temp;
    }

    for (int i = 0; i < 13; i++)
    {
        Card temp;
        temp.setRank(i + 2);
        temp.setSuit("Spades");
        deck[i + 26] = temp;
    }

    for (int i = 0; i < 13; i++)
    {
        Card temp;
        temp.setRank(i + 2);
        temp.setSuit("Clubs");
        deck[i + 39] = temp;
    }

}

bool Deck::empty()
{
    Card temp;
    if (deck[0].getNumberValue() == deck[1].getNumberValue() && deck[0].getSuit() == deck[1].getSuit())
    {
        return true;
    }
    else
    {
        return false;
    }


}

void Deck::shuffle()
{
    int bound1, bound2;
    Card temp;
    for (int i = 0; i < DECK_SIZE; i++)
    {
        bound1 = rand() % 52;
        bound2 = rand() % 52;
        temp = deck[bound1];
        deck[bound1] = deck[bound2];
        deck[bound2] = temp;
    }

}

ostream& operator<<(ostream& outs, const Deck& deck)
{
    for (int i = 0; i < deck.DECK_SIZE; i++)
    {
        outs << i + 1 << ": " << deck.deck[i] << endl;
    }

    return outs;
}

Card Deck::dealCard()
{
    if (!empty())
    {
        Card newCard;
        Card temp = deck[0];
        for (int i = 1; i < DECK_SIZE; i++)
        {
            //cout << "Shifting cards ";
            deck[i - 1] = deck[i];
        }
        return temp;
    }
    else
    {
        Card newCard;
        cout << "Deck is empty...";
        return newCard;
    }
}

Card Deck::getCardAt(int index)
{
    return deck[index];
}
