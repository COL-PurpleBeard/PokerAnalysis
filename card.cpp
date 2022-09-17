#include "card.h"

using namespace std;

Card::Card() : value(0), suit("")
{}

Card::Card(int theValue, string theSuit) : value(theValue), suit(theSuit)
{
    if (theSuit != "Diamonds" && theSuit != "Hearts" && theSuit != "Spades" && theSuit != "Clubs")
    {
        cout << "Invalid suit...exiting...";
        exit(1);
    }
}

string Card::getSuit() const
{
    return suit;
}

int Card::getNumberValue() const
{
    return value;
}

string Card::getWrittenValue() const
{
    if (value == 2)
    {
        return "Two";
    }
    if (value == 3)
    {
        return "Three";
    }
    if (value == 4)
    {
        return "Four";
    }
    if (value == 5)
    {
        return "Five";
    }
    if (value == 6)
    {
        return "Six";
    }
    if (value == 7)
    {
        return "Seven";
    }
    if (value == 8)
    {
        return "Eight";
    }
    if (value == 9)
    {
        return "Nine";
    }
    if (value == 10)
    {
        return "Ten";
    }
    if (value == 11)
    {
        return "Jack";
    }
    if (value == 12)
    {
        return "Queen";
    }
    if (value == 13)
    {
        return "King";
    }
    if (value == 14)
    {
        return "Ace";
    }
}

void Card::setSuit(string newSuit)
{
    if (newSuit != "Diamonds" && newSuit != "Hearts" && newSuit != "Spades" && newSuit != "Clubs")
    {
        cout << "Invalid suit...exiting...";
        exit(1);
    }
    suit = newSuit;
}

void Card::setRank(int newValue)
{
    value = newValue;
}

ostream& operator<<(ostream& outs, const Card& card)
{
    outs << card.getWrittenValue() << " of " << card.getSuit();
    return outs;
}