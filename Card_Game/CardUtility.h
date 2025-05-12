#ifndef CARDUTILITY_H
#define CARDUTILITY_H

#include <vector>
#include <algorithm>
#include "Card.h" // Include the Card header file here

using namespace std;
class CardUtility {
public:
    static int getHighestCard(const vector<Card>& cards) {
        // Sort the cards by value
        vector<Card> sortedCards = cards;
        sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
            return a.getValue() > b.getValue();
        });

        // Return the value of the highest card
        return sortedCards[0].getValue();
    }

    static int getLowestCardIndex(const vector<Card> &cards) {
        int lowestIndex = -1;
        int lowestValue = numeric_limits<int>::max(); // Initialize with the highest possible value

        for (size_t i = 0; i < cards.size(); ++i) {
            if (cards[i].getValue() < lowestValue) {
                lowestValue = cards[i].getValue();
                lowestIndex = i;
            }
        }

        return lowestIndex;
    }

};

#endif // CARDUTILITY_H
