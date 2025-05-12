#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

using namespace std;
class Deck {
private:
    vector<Card> cards;

public:
    Deck() {
        createDeck();
    }

    void createDeck() {
        static const QString suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
        for (const QString &suit : suits) {
            for (int value = 2; value <= 14; ++value) {
                cards.emplace_back(value, suit);
            }
        }
    }

    void shuffle() {
        std::shuffle(cards.begin(), cards.end(), mt19937{random_device{}()});
    }

    Card dealCard() {
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
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

            qDebug() << "Swapping card at index" << index
                     << "Old card:" << oldCard.getName()
                     << "New card:" << newCard.getName();
        }
    }
};

#endif // DECK_H
