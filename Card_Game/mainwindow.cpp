#include "mainwindow.h"
#include "CardUtility.h"
#include <QTimer>
#include <QMessageBox>
#include <QString>

using namespace std;
QString end_result = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), player("Player"), computer("Computer"), swapCounter(0) {
    setupUI();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    dealButton = new QPushButton("Deal", this);
    connect(dealButton, &QPushButton::clicked, this, &MainWindow::dealCards);

    swapButton = new QPushButton("Swap", this);
    connect(swapButton, &QPushButton::clicked, this, &MainWindow::showSwapButtons);
    swapButton->hide(); // Initially hide the swap button

    QHBoxLayout *playerHandLayout = new QHBoxLayout();
    QHBoxLayout *computerHandLayout = new QHBoxLayout();

    for (int i = 0; i < 5; ++i) {
        QLabel *playerCardLabel = new QLabel(this);
        playerCardLabels.append(playerCardLabel);
        playerHandLayout->addWidget(playerCardLabel);

        QLabel *computerCardLabel = new QLabel(this);
        computerCardLabels.append(computerCardLabel);
        computerHandLayout->addWidget(computerCardLabel);
    }

    QHBoxLayout *swapButtonLayout = new QHBoxLayout();
    for (int i = 0; i < 5; ++i) {
        QPushButton *swapCardButton = new QPushButton(QString::number(i + 1), this);
        swapCardButton->setCheckable(true);
        swapCardButtons.append(swapCardButton);
        swapButtonLayout->addWidget(swapCardButton);
    }

    QPushButton *doneButton = new QPushButton("Done", this);
    connect(doneButton, &QPushButton::clicked, this, &MainWindow::performSwap);
    swapButtonLayout->addWidget(doneButton);

    swapButtonContainer = new QWidget(this);
    swapButtonContainer->setLayout(swapButtonLayout);
    swapButtonContainer->hide();

    resultLabel = new QLabel(this);

    mainLayout->addWidget(dealButton);
    mainLayout->addWidget(swapButton);
    mainLayout->addLayout(playerHandLayout);
    mainLayout->addLayout(computerHandLayout);
    mainLayout->addWidget(swapButtonContainer);
    mainLayout->addWidget(resultLabel);

    setCentralWidget(centralWidget);
}

void MainWindow::showSwapButtons() {
    if (swapCounter < 4) {
        swapButtonContainer->show();
    } else {
        swapButton->setEnabled(false);

        qDebug() << "No more swaps allowed.";
    }
}

void MainWindow::performSwap() {
    vector<int> cardsToSwap;
    QStringList swapBooleans;

    for (int i = 0; i < swapCardButtons.size(); ++i) {
        if (swapCardButtons[i]->isChecked()) {
            cardsToSwap.push_back(i);
            swapBooleans.append("true");
        } else {
            swapBooleans.append("false");
        }
    }

    QString swapString = swapBooleans.join(",");
    qDebug() << "Swapping cards: " << swapString;

    if (!cardsToSwap.empty()) {
        swapCardsWithDeck(cardsToSwap);
        swapCounter++;
        performOpponentSwap();
    }

    swapButtonContainer->hide();
    for (auto button : swapCardButtons) {
        button->setChecked(false);
    }

    if (swapCounter >= 4) {
        const QString end_result1 = end_result;
        swapButton->setText(end_result);
        showOpponentCards();

        // Determine the winner after the 3rd swap
        determineWinner();
    }
}

void MainWindow::dealCards() {
    deck.shuffle();
    player.getHand().dealHand(deck);
    computer.getHand().dealHand(deck);

    // Automatically swap one of the player's cards
    int randomIndex = rand() % 5; // Generate a random index
    swapCardsWithDeck({randomIndex});

    updateUI();
    determineWinner();

    dealButton->hide();
    swapCounter = 0;
    swapButton->setEnabled(true);
    swapButton->show(); // Show the swap button after dealing cards

    // Hide opponent cards after 1 second
    //QTimer::singleShot(1000, this, &MainWindow::hideOpponentCards);
}

void MainWindow::hideOpponentCards() {
    for (auto label : computerCardLabels) {
        label->setPixmap(QPixmap("C:/Users/aalia/OneDrive/Documents/Card_Game/images/back.png").scaled(100, 150));
    }
}

void MainWindow::showOpponentCards() {
    const auto &computerHand = computer.getHand().getCards();
    for (int i = 0; i < 5; ++i) {
        computerCardLabels[i]->setPixmap(computerHand[i].getImage().scaled(100, 150));
    }
}

void MainWindow::updateUI() {
    const auto &playerHand = player.getHand().getCards();
    const auto &computerHand = computer.getHand().getCards();

    for (int i = 0; i < 5; ++i) {
        playerCardLabels[i]->setPixmap(playerHand[i].getImage().scaled(100, 150));
        computerCardLabels[i]->setPixmap(computerHand[i].getImage().scaled(100, 150));
    }
    if (swapCounter<3);
    //QTimer::singleShot(1000, this, &MainWindow::hideOpponentCards);
}

void MainWindow::swapCardsWithDeck(const vector<int> &indices) {
    if (indices.size() > 3) {
        qDebug() << "Invalid number of cards to swap.";
        return;
    }

    player.getHand().swapCards(deck, indices);
    updateUI(); // Update the UI to reflect the swapped cards
}

void MainWindow::swapCardsWithDeck_opponent(const vector<int> &indices) {
    if (indices.size() > 3) {
        qDebug() << "Invalid number of cards to swap.";
        return;
    }

    computer.getHand().swapCards(deck, indices);
    updateUI(); // Update the UI to reflect the swapped cards
}

void MainWindow::determineWinner() {
    qDebug() << "Determining player and opponent hands...";
    int playerHand = player.getHand().getBest();
    int opponentHand = computer.getHand().getBest();
    qDebug() << "Player hand score: " << playerHand;
    qDebug() << "Opponent hand score: " << opponentHand;

    QString playerHandType;
    QString opponentHandType;

    switch (playerHand) {
    case 9:
        playerHandType = "Straight Flush";
        break;
    case 8:
        playerHandType = "Four of a Kind";
        break;
    case 7:
        playerHandType = "Full House";
        break;
    case 6:
        playerHandType = "Flush";
        break;
    case 5:
        playerHandType = "Straight";
        break;
    case 4:
        playerHandType = "Three of a Kind";
        break;
    case 3:
        playerHandType = "Two Pair";
        break;
    case 2:
        playerHandType = "Pair";
        break;
    case 1:
        playerHandType = "High Card";
        break;
    }

    switch (opponentHand) {
    case 9:
        opponentHandType = "Straight Flush";
        break;
    case 8:
        opponentHandType = "Four of a Kind";
        break;
    case 7:
        opponentHandType = "Full House";
        break;
    case 6:
        opponentHandType = "Flush";
        break;
    case 5:
        opponentHandType = "Straight";
        break;
    case 4:
        opponentHandType = "Three of a Kind";
        break;
    case 3:
        opponentHandType = "Two Pair";
        break;
    case 2:
        opponentHandType = "Pair";
        break;
    case 1:
        opponentHandType = "High Card";
        break;
    }

    qDebug() << "Player hand type: " << playerHandType;
    qDebug() << "Opponent hand type: " << opponentHandType;

    // Compare hand rankings
    if (playerHand == opponentHand) {
        // If both hands have the same ranking, compare the highest card
        int playerHighestCard = CardUtility::getHighestCard(player.getHand().getCards());
        int opponentHighestCard = CardUtility::getHighestCard(computer.getHand().getCards());

        if (playerHighestCard == opponentHighestCard) {
            // If both hands have the same highest card, it's a tie
            qDebug() << "It's a tie!";
            end_result = "It's a tie!";

        } else if (playerHighestCard > opponentHighestCard) {
            // Player wins
            qDebug() << "Player Wins!";
            end_result = "Player Wins!";
        } else {
            // Opponent wins
            qDebug() << "Opponent Wins!";
            end_result = "Opponent Wins!";
        }
    } else if (playerHand > opponentHand) {
        // Player wins
        qDebug() << "Player Wins!";
        end_result = "Player Wins!";
    } else {
        // Opponent wins
        qDebug() << "Opponent Wins!";
        end_result = "Opponent Wins!";
    }
}

void MainWindow::performOpponentSwap() {
    const auto &computerHand = computer.getHand().getCards();
    int opponentHand = determineOpponentHand(computerHand);

    qDebug() << "Opponent has hand: " << opponentHand;

    // Implement AI logic based on opponent's hand
    switch (opponentHand) {
    case 2: // Pair
        qDebug() << "Opponent Stratergy, Swap other 3 Cards";
        swapOtherThreeCards(computerHand);
    case 3: // Two Pair
        qDebug() << "Opponent strategy: Swap other card";
        swapLowestCard(computerHand);
        break;
    case 4: // Three of a Kind
        qDebug() << "Opponent strategy: Swap other 2 cards";
        swapOtherTwoCards(computerHand);
        break;
    case 8: // Four of a Kind
    case 7: // Full House
        qDebug() << "Opponent strategy: Swap other card";
        swapLowestCard(computerHand);
        break;
    case 1: // High Card
        qDebug() << "Opponent strategy: Swap lowest card";
        swapLowestCard(computerHand);
        break;
    default:
        // No specific strategy, do nothing
        qDebug() << "Opponent strategy: No specific strategy, do nothing";
        break;
    }
}

int MainWindow::determineOpponentHand(const vector<Card> &hand) {
    // Sort the hand by rank
    vector<Card> sortedHand = hand;
    sort(sortedHand.begin(), sortedHand.end(), [](const Card &a, const Card &b) {
        return a.getValue() < b.getValue();
    });

    // Count occurrences of each rank
    map<int, int> rankCount;
    for (const Card &card : sortedHand) {
        rankCount[card.getValue()]++;
    }

    // Determine hand strength
    int maxSameRank = 0;
    for (const auto &pair : rankCount) {
        maxSameRank = max(maxSameRank, pair.second);
    }

    switch (maxSameRank) {
    case 4:
        return 8; // Four of a Kind
    case 3:
        if (rankCount.size() == 2)
            return 7; // Full House
        else
            return 4; // Three of a Kind
    case 2:
        if (rankCount.size() == 3)
            return 3; // Two Pair
        else
            return 2; // Pair
    default:
        // Check for straight or flush
        bool straight = true;
        bool flush = true;
        for (int i = 1; i < sortedHand.size(); ++i) {
            if (sortedHand[i].getValue() != sortedHand[i - 1].getValue() + 1) {
                straight = false;
            }
            if (sortedHand[i].getSuit() != sortedHand[i - 1].getSuit()) {
                flush = false;
            }
        }
        if (straight && flush)
            return 9; // Straight Flush
        else if (flush)
            return 6; // Flush
        else if (straight)
            return 5; // Straight
        else
            return 1; // High Card
    }
}

void MainWindow::swapLowestCard(const vector<Card> &hand) {
    // Initialize the index of the lowest card as the first card's index
    int lowestCardIndex = 0;

    // Iterate through the hand starting from the second card
    for (int i = 1; i < 5; ++i) {
        // If the current card's value is less than the lowest card's value, update the lowest card index
        if (hand[i].getValue() < hand[lowestCardIndex].getValue()) {
            lowestCardIndex = i;
            qDebug() << "New lowest card found at index: " << lowestCardIndex;
        }
    }

    // Swap the lowest card
    vector<int> cardsToSwap = {lowestCardIndex};
    qDebug() << "Opponent swaps lowest card at index: " << lowestCardIndex;
    swapCardsWithDeck_opponent(cardsToSwap);
}




void MainWindow::swapOtherTwoCards(const vector<Card> &hand) {
    int three_count_index1 = 0;
    int three_count_index2 = 0;
    int three_count_index3 = 0;
    int count = 1;

    // Find the first card with three occurrences of the same value
    while (count != 3) {
        if (hand[three_count_index1].getValue() == hand[three_count_index2].getValue()) {
            count++;
        } else {
            count = 1;
            three_count_index1 = three_count_index2;
        }
        three_count_index2++;
    }

    // Now three_count_index1 points to the first card with three occurrences
    // Find the indices of the other two cards with the same value
    for (int i = three_count_index1 + 1; i < 5; i++) {
        if (hand[i].getValue() == hand[three_count_index1].getValue()) {
            three_count_index3 = i;
            break;
        }
    }

    // Find the indices of the cards to swap (excluding the ones with three occurrences)
    vector<int> cardsToSwap;
    for (int i = 0; i < 5; ++i) {
        if (i != three_count_index1 && i != three_count_index2 && i != three_count_index3) {
            cardsToSwap.push_back(i);
        }
    }

    qDebug() << "Opponent swaps other two cards at indices: " << cardsToSwap[0] << ", " << cardsToSwap[1];
    swapCardsWithDeck_opponent(cardsToSwap);
}

void MainWindow::swapOtherThreeCards(const vector<Card> &hand) {
    // Find the indices of the pair
    vector<int> pairIndices;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (hand[i].getValue() == hand[j].getValue()) {
                pairIndices.push_back(i);
                pairIndices.push_back(j);
                break;
            }
        }
        if (!pairIndices.empty()) break; // If pair found, exit the outer loop
    }

    // Find the indices of the cards to swap (excluding the ones with the pair)
    vector<int> cardsToSwap;
    for (int i = 0; i < 5; ++i) {
        if (i != pairIndices[0] && i != pairIndices[1]) {
            cardsToSwap.push_back(i);
        }
    }

    qDebug() << "Opponent swaps other three cards at indices: " << cardsToSwap[0] << ", " << cardsToSwap[1] << ", " << cardsToSwap[2];
    swapCardsWithDeck_opponent(cardsToSwap);
}


