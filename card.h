#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> 
#include <array>
#include <vector>
#include <cstring>
#include <ctime>
#include <string>
#include <cctype>
#include <cstddef>
#include <algorithm>

using namespace std;

class Card
{
private:
    int value;
    string suit;
public:
    Card();
    Card(int theValue, string theSuit);
    string getSuit() const;
    int getNumberValue() const;
    string getWrittenValue() const;
    void setSuit(string newSuit);
    void setRank(int newValue);
    friend ostream& operator<<(ostream& outs, const Card& card);
};
#endif // !CARD
