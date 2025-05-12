#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

class Player {
private:
    QString name;
    int score;
    Hand hand;

public:
    Player(const QString &name) : name(name), score(0) {}

    Hand& getHand() {
        return hand;
    }

    void incrementScore() {
        ++score;
    }

    int getScore() const {
        return score;
    }
};

#endif // PLAYER_H
