#ifndef CARD_HAND_SCORE_H
#define CARD_HAND_SCORE_H

#include "cardHand.h"
#include "pokerScore.h"

using namespace std;

class CardHandScorer
{
private:
    int score;
public:
    CardHandScorer();
    bool isPair(CardHand theHand);
    bool isTwoPair(CardHand theHand);
    bool isTrips(CardHand theHand);
    bool isStraight(CardHand theHand);
    bool isFlush(CardHand theHand);
    bool isFullHouse(CardHand theHand);
    bool isQuads(CardHand theHand);
    bool isStraightFlush(CardHand theHand);
    bool isRoyalFlush(CardHand theHand);
    static vector<PokerScore::Scores> getScore(CardHand theHand);
};


#endif // !CARD_HAND_SCORE_H

