#ifndef HAND_H
#define HAND_H

#include <vector>
#include <algorithm>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Hand {
private:
    vector<Card> cards;

public:
    void dealHand(Deck &deck) {
        cards.clear();
        for (int i = 0; i < 5; ++i) {
            cards.push_back(deck.dealCard());
        }
    }
    void swapCards(Deck &deck, const vector<int> &indicesToSwap) {
        // Check if the indices to swap are valid
        for (int index : indicesToSwap) {
            if (index < 0 || index >= cards.size()) {
                qDebug() << "Invalid index: " << index;
                return; // Exit if any index is invalid
            }
        }

        // Remove cards from hand and add new cards from the deck
        for (int index : indicesToSwap) {
            Card oldCard = cards[index]; // Store the card that is being replaced
            Card newCard = deck.dealCard(); // Deal a new card from the deck
            cards[index] = newCard; // Replace the card in the hand

            qDebug() << "Swapping card at index" << index;

        }
    }

    void sortValue() {
        sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
            return a.getValue() < b.getValue();
        });
    }

    int getBest() {
        // Sort the cards by value for easier hand ranking checks
        sortValue();

        // Check for straight flush
        bool isStraightFlush = false;
        bool isFlush = true;
        bool isStraight = true;

        QString suit = cards[0].getSuit();
        int minValue = cards[0].getValue();

        for (int i = 1; i < cards.size(); ++i) {
            if (cards[i].getSuit() != suit) {
                isFlush = false;
            }
            if (cards[i].getValue() != minValue + i && cards[i].getValue() != 14 - cards.size() + i) {
                isStraight = false;
            }
        }

        if (isFlush && isStraight) {
            isStraightFlush = true;
        }

        if (isStraightFlush) {
            return 9; // Straight Flush
        }

        // Check for four of a kind
        bool isFourOfAKind = false;
        int maxCount = 0;
        int maxVal = 0;
        for (const Card &card : cards) {
            int count = count_if(cards.begin(), cards.end(), [&card](const Card &c) {
                return c.getValue() == card.getValue();
            });
            if (count == 4) {
                isFourOfAKind = true;
                maxVal = card.getValue();
                break;
            }
        }

        if (isFourOfAKind) {
            return 8; // Four of a Kind
        }

        // Check for full house
        bool isFullHouse = false;
        bool hasThree = false;
        bool hasTwo = false;
        for (const Card &card : cards) {
            int count = count_if(cards.begin(), cards.end(), [&card](const Card &c) {
                return c.getValue() == card.getValue();
            });
            if (count == 3) {
                hasThree = true;
            } else if (count == 2) {
                hasTwo = true;
            }
        }

        if (hasThree && hasTwo) {
            isFullHouse = true;
        }

        if (isFullHouse) {
            return 7; // Full House
        }

        // Check for flush
        if (isFlush) {
            return 6; // Flush
        }

        // Check for straight
        if (isStraight) {
            return 5; // Straight
        }

        // Check for three of a kind
        bool isThreeOfAKind = false;
        for (const Card &card : cards) {
            int count = count_if(cards.begin(), cards.end(), [&card](const Card &c) {
                return c.getValue() == card.getValue();
            });
            if (count == 3) {
                isThreeOfAKind = true;
                break;
            }
        }

        if (isThreeOfAKind) {
            return 4; // Three of a Kind
        }

        // Check for two pair
        bool isTwoPair = false;
        int pairs = 0;
        for (int i = 0; i < cards.size() - 1; ++i) {
            if (cards[i].getValue() == cards[i + 1].getValue()) {
                pairs++;
                i++;
            }
        }

        if (pairs == 2) {
            isTwoPair = true;
        }

        if (isTwoPair) {
            return 3; // Two Pair
        }

        // Check for pair
        bool isPair = false;
        for (const Card &card : cards) {
            int count = count_if(cards.begin(), cards.end(), [&card](const Card &c) {
                return c.getValue() == card.getValue();
            });
            if (count == 2) {
                isPair = true;
                break;
            }
        }

        if (isPair) {
            return 2; // Pair
        }

        // If no other hand is found, return the value of the highest card
        return 1; // High Card
    }



    const vector<Card>& getCards() const {
        return cards;
    }


};

#endif // HAND_H
