#include "card.h"
#include "cardHand.h"
#include "cardHandScore.h"
#include "deck.h"
#include "pokerScore.h"

using namespace std;

int main()
{
    srand(time(NULL));
    PokerScore pokerScore;

    for (int i = 0; i < 10000; i++)
    {
        Deck deck;
        CardHand hand1, hand2, hand3, hand4, hand5;
        deck.shuffle();
        for (int i = 0; i < 5; i++)
        {
            hand1.giveCard(deck);
            hand2.giveCard(deck);
            hand3.giveCard(deck);
            hand4.giveCard(deck);
            hand5.giveCard(deck);
        }

        vector<PokerScore::Scores> tempScores = CardHandScorer::getScore(hand1);
        for (int i = 0; i < tempScores.size(); i++)
        {
            pokerScore.scores.push_back(tempScores[i]);
        }
        hand1.~CardHand();
    }
    pokerScore.output();

    return 0;
}