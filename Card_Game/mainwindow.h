#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include <vector>
#include "Deck.h"
#include "Player.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Deck deck;
    Player player;
    Player computer;
    QPushButton *dealButton;
    QPushButton *swapButton;
    QVector<QPushButton*> swapCardButtons;
    QWidget *swapButtonContainer;
    QVector<QLabel*> playerCardLabels;
    QVector<QLabel*> computerCardLabels;
    QLabel *resultLabel;
    vector<int> cardsToSwap; // Store indices of cards to be swapped during opponent's turn
    int swapCounter;

    void setupUI();

private slots:
    void dealCards();
    void updateUI();
    void determineWinner();
    void swapCardsWithDeck(const std::vector<int> &indices);
    void showSwapButtons();
    void performSwap();
    void showOpponentCards();
    void hideOpponentCards();
    void performOpponentSwap();
    void swapLowestCard(const std::vector<Card> &hand);
    void swapOtherTwoCards(const std::vector<Card> &hand);
    int determineOpponentHand(const vector<Card> &hand);
    void swapCardsWithDeck_opponent(const vector<int> &indices);
    void swapOtherThreeCards(const vector<Card> &hand);
};
#endif // MAINWINDOW_H
