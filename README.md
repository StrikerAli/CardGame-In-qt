# Poker-Style Card Game

## Overview
A C++ desktop card game developed using the Qt framework, featuring player vs. computer gameplay based on classic poker hand rankings.

## Game Rules
- The game is played over **5 rounds**.
- In each round:
  - Both the player and the computer are dealt **5 cards**.
  - Hands are ranked according to traditional poker categories.
  - Players may swap up to **3 cards** in rounds 1–4.
  - The computer performs strategic card swapping in **advanced mode**.

## Hand Rankings (Highest to Lowest)
1. Straight Flush  
2. Four of a Kind  
3. Full House  
4. Flush  
5. Straight  
6. Three of a Kind  
7. Two Pair  
8. One Pair  
9. Highest Card  

## Features
- Graphical user interface (GUI)
- Deck shuffling
- Hand evaluation
- Score tracking
- Advanced gameplay with card swapping

## Project Structure
### Key Classes
- **Game**: Manages the overall game state
- **Player**: Tracks player information
- **Card**: Represents individual cards
- **Deck**: Manages the collection and shuffling of cards
- **Hand**: Evaluates card combinations and rankings

## Requirements
- C++
- Qt Framework

## How to Play
1. Start a new game
2. Deal initial hands to both player and computer
3. Optionally swap up to 3 cards (rounds 1–4 only)
4. Compare hands to determine the winner of the round
5. Win rounds and track your score

## Installation
Built .exe version is available, you can test it from here

## CPU CARD SWAPPING LOGIC
Basic swapping logic has been setup for the CPU:
- If CPU has no hand, swap 3 cards at random
- If CPU has a pair or 2 pairs, swap the cards that do not make a pair
- If CPU is 1 card away from a straight, swap the 1 card to potientally make a straight 
- If CPU has 3 or 4 of a kind, swap cards that are not the same kind

In the output images, CPU makes a 3 of a kind and holds onto it, swapping only the other 2 cards

Output Images:
![1](https://github.com/user-attachments/assets/ee97ee07-6b67-407b-b090-d73769b10a74)
![2](https://github.com/user-attachments/assets/d9e8781d-32d7-4ff4-b41d-ddc76e7d64fd)
![3](https://github.com/user-attachments/assets/2e01295b-0fb0-4cb5-bec6-3d5850cc9621)
![4](https://github.com/user-attachments/assets/7b8c90e8-5594-4f91-8cf2-d064c9a62bf8)
![5](https://github.com/user-attachments/assets/27228ec3-c6c2-47be-ab85-0519d5c4c678)


Output Video:

https://github.com/user-attachments/assets/e6addd34-2f38-418e-bcce-ea44377e8c00

