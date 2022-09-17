#include "cardHandScore.h"

using namespace std;


CardHandScorer::CardHandScorer() : score(0)
{
}

bool CardHandScorer::isPair(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (temp[i].getNumberValue() == temp[j].getNumberValue())
            {
                return true;
            }
        }
    }
    return false;
}

bool CardHandScorer::isTwoPair(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    int counter = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (temp[i].getNumberValue() == temp[j].getNumberValue())
            {
                counter++;
            }
        }
    }
    if (counter == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isTrips(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    int counter = 0;
    int value;
    for (int i = 0; i < 5; i++)
    {
        counter = 0;
        for (int j = i + 1; j < 5; j++)
        {
            value = temp[i].getNumberValue();
            if (temp[j].getNumberValue() == value)
            {
                counter++;
            }
            if (counter == 2)
            {
                return true;
            }

        }
    }
    return false;
}

bool CardHandScorer::isStraight(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    vector<int> sortedValues;
    for (int i = 0; i < 5; i++)
    {
        sortedValues.push_back(temp[i].getNumberValue());
    }

    sort(sortedValues.begin(), sortedValues.end());

    for (int i = 0; i < 4; i++)
    {
        if (sortedValues[i] + 1 != sortedValues[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isFlush(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    for (int i = 0; i < 4; i++)
    {
        if (temp[i].getSuit() != temp[i + 1].getSuit())
        {
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isFullHouse(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    vector<int> sortedValues;
    for (int i = 0; i < 5; i++)
    {
        sortedValues.push_back(temp[i].getNumberValue());
    }

    sort(sortedValues.begin(), sortedValues.end());

    for (int i = 0; i < 2; i++)
    {
        if (sortedValues[i] != sortedValues[i + 1])
        {
            return false;
        }
    }

    for (int i = 3; i < 4; i++)
    {
        if (sortedValues[i] != sortedValues[i + 1])
        {
            return false;
        }
    }

    return true;
}

bool CardHandScorer::isQuads(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    int counter = 0;
    int value;
    for (int i = 0; i < 5; i++)
    {
        counter = 0;
        for (int j = i + 1; j < 5; j++)
        {
            value = temp[i].getNumberValue();
            if (temp[j].getNumberValue() == value)
            {
                counter++;
            }
            if (counter == 3)
            {
                return true;
            }
        }
    }
    return false;
}

bool CardHandScorer::isStraightFlush(CardHand theHand)
{
    if (isStraight(theHand) && isFlush(theHand))
    {
        return true;
    }
    return false;
}

bool CardHandScorer::isRoyalFlush(CardHand theHand)
{
    vector<Card> temp = theHand.getHand();
    vector<int> sortedValues;
    for (int i = 0; i < 5; i++)
    {
        sortedValues.push_back(temp[i].getNumberValue());
    }

    sort(sortedValues.begin(), sortedValues.end());

    if (sortedValues[0] != 10)
    {
        return false;
    }

    if (!isStraight(theHand))
    {
        return false;
    }

    if (!isFlush(theHand))
    {
        return false;
    }

    return true;
}

vector<PokerScore::Scores> CardHandScorer::getScore(CardHand theHand)
{
    vector<PokerScore::Scores> theScores;
    CardHandScorer scoreObj;
    bool highCard = true;
    bool onePair = scoreObj.isPair(theHand);
    bool twoPair = scoreObj.isTwoPair(theHand);
    bool trips = scoreObj.isTrips(theHand);
    bool straight = scoreObj.isStraight(theHand);
    bool flush = scoreObj.isFlush(theHand);
    bool fullHouse = scoreObj.isFullHouse(theHand);
    bool quads = scoreObj.isQuads(theHand);
    bool straightFlush = scoreObj.isStraightFlush(theHand);
    bool royalFlush = scoreObj.isRoyalFlush(theHand);

    if (royalFlush)
    {
        theScores.push_back(PokerScore::ROYAL_FLUSH);
        theScores.push_back(PokerScore::STRAIGHT_FLUSH);
        theScores.push_back(PokerScore::FLUSH);
        theScores.push_back(PokerScore::STRAIGHT);
        theScores.push_back(PokerScore::HIGH_CARD);
        goto marker;
    }

    if (straightFlush)
    {
        theScores.push_back(PokerScore::STRAIGHT_FLUSH);
        theScores.push_back(PokerScore::FLUSH);
        theScores.push_back(PokerScore::STRAIGHT);
        theScores.push_back(PokerScore::HIGH_CARD);
        goto marker;
    }

    if (quads)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
        theScores.push_back(PokerScore::ONE_PAIR);
        theScores.push_back(PokerScore::TWO_PAIR);
        theScores.push_back(PokerScore::THREE_OF_A_KIND);
        theScores.push_back(PokerScore::FOUR_OF_A_KIND);
        goto marker;
    }

    if (fullHouse)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
        theScores.push_back(PokerScore::ONE_PAIR);
        theScores.push_back(PokerScore::TWO_PAIR);
        theScores.push_back(PokerScore::THREE_OF_A_KIND);
        theScores.push_back(PokerScore::FULL_HOUSE);
        goto marker;
    }

    if (flush)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
        theScores.push_back(PokerScore::FLUSH);
        goto marker;
    }

    if (straight)
    {
        theScores.push_back(PokerScore::STRAIGHT);
        theScores.push_back(PokerScore::HIGH_CARD);
        goto marker;
    }

    if (trips)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
        theScores.push_back(PokerScore::ONE_PAIR);
        theScores.push_back(PokerScore::THREE_OF_A_KIND);
        goto marker;
    }

    if (twoPair)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
        theScores.push_back(PokerScore::ONE_PAIR);
        theScores.push_back(PokerScore::TWO_PAIR);
        goto marker;
    }
    // add goto statements
    if (onePair)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
        theScores.push_back(PokerScore::ONE_PAIR);
        goto marker;
    }

    if (highCard)
    {
        theScores.push_back(PokerScore::HIGH_CARD);
    }

marker:

    return theScores;
}