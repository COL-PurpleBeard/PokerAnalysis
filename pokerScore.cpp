#include "pokerScore.h"

using namespace std;


PokerScore::PokerScore()
{
    scores.reserve(1000);
}

void PokerScore::operator+=(const Scores& score)
{
    scores.push_back(score);
}

bool operator==(const PokerScore& p, PokerScore::Scores score)
{
    for (int i = 0; i < p.scores.size(); i++)
    {
        if (p.scores[i] != score)
        {
            return false;
        }

    }
    return true;

}

PokerScore::Scores& PokerScore::operator[](unsigned int index)
{
    if (index >= scores.size()) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return scores[index];
}

void PokerScore::output()
{
    int count0, count1, count2, count3, count4, count5, count6, count7, count8, count9;
    count0 = count1 = count2 = count3 = count4 = count5 = count6 = count7 = count8 = count9 = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i] == 0)
        {
            count0++;
        }
        if (scores[i] == 1)
        {
            count1++;
        }
        if (scores[i] == 2)
        {
            count2++;
        }
        if (scores[i] == 3)
        {
            count3++;
        }
        if (scores[i] == 4)
        {
            count4++;
        }
        if (scores[i] == 5)
        {
            count5++;
        }
        if (scores[i] == 6)
        {
            count6++;
        }
        if (scores[i] == 7)
        {
            count7++;
        }
        if (scores[i] == 8)
        {
            count8++;
        }
        if (scores[i] == 9)
        {
            count9++;
        }
    }

    cout << "ROYAL_FLUSH: " << count0 << endl;
    cout << "STRAIGHT_FLUSH: " << count1 << endl;
    cout << "FOUR_OF_A_KIND: " << count2 << endl;
    cout << "FULL_HOUSE: " << count3 << endl;
    cout << "FLUSH: " << count4 << endl;
    cout << "STRAIGHT: " << count5 << endl;
    cout << "THREE_OF_A_KIND: " << count6 << endl;
    cout << "TWO_PAIR: " << count7 << endl;
    cout << "ONE_PAIR: " << count8 << endl;
    cout << "HIGH_CARD: " << count9 << endl;

}