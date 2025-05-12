#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QPixmap>
#include <QDebug>

using namespace std;

class Card {
private:
    int value; // 1 to 14
    QString suit; // "Hearts", "Diamonds", "Spades", "Clubs"
    QPixmap image; // Image of the card

public:
    Card(int value, const QString &suit) : value(value), suit(suit) {
        loadCardImage();
    }

    int getValue() const {
        return value;
    }

    QString getSuit() const {
        return suit;
    }

    QString getName() const {
        static const QString values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king" , "ace"};
        return values[value] + " of " + suit;
    }

    const QPixmap& getImage() const {
        return image;
    }

    bool operator==(const Card& other) const {
        return value == other.value && suit == other.suit;
    }

private:
    void loadCardImage() {
        QString name;
        if (value >= 2 && value <= 10) {
            name = QString::number(value);
        } else {
            switch (value) {
            case 11:
                name = "jack";
                break;
            case 12:
                name = "queen";
                break;
            case 13:
                name = "king";
                break;
            case 14:
                name = "ace";
                break;
            default:
                name = "";
                break;
            }
        }

        QString imageName = name + "_of_" + suit.toLower() + ".png";
        qDebug() << "C:/Users/aalia/OneDrive/Documents/Card_Game/images/" + imageName;
        if (!image.load("C:/Users/aalia/OneDrive/Documents/Card_Game/images/" + imageName)) {
            qDebug() << "Failed to load image:" << imageName;
        }
    }

};

#endif // CARD_H
