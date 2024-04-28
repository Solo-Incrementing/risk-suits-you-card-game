#include <iostream>

#include "Random.h"
#include "main.h"
#include "tests.h"

#define DEBUG

const int g_startScore{ 130 };

/*
* generate a random card suit
* @return A character 'C', 'S', 'D', or 'H' representing the card
* suits Clubs, Spades, Diamonds and Hearts respectively.
* '0' if something went wrong
*/
char generateRandomCardSuit()
{
    int suitNumber{ Random::get(1, 4) };

    switch (suitNumber)
    {
    case 1:
        return 'C';
    case 2:
        return 'S';
    case 3:
        return 'D';
    case 4:
        return 'H';
    default:
        return '0';
    }
}

/*
* generate a random card type with the correct probability distribution
* @return A character 'N', 'F', or 'A' representing the card types
* Number, Face or Ace respectively.
* '0' if something went wrong
*/
char generateRandomCardType()
{
    int typeNumber{ Random::get(1, 13) };

    if (typeNumber > 0 && typeNumber <= 9)          return 'N';
    else if (typeNumber > 9 && typeNumber <= 12)    return 'F';
    else if (typeNumber == 13)                      return 'A';
    else                                            return '0';
}

/*
* generate a random card number
* @return A random number between 2 and 10 inclusive for a number card
*/
int generateRandomCardNumber()
{
    return Random::get(2, 10);
}

/*
* generate a random card face
* @return A character 'K', 'Q', or 'J' representing the card
* faces King, Queen, and Jack respectively.
* '0' if something went wrong
*/
char generateRandomCardFace()
{
    int faceNumber{ Random::get(1, 3) };

    switch (faceNumber)
    {
    case 1:
        return 'K';
    case 2:
        return 'Q';
    case 3:
        return 'J';
    default:
        return '0';
    }
}

int main()
{
#ifdef DEBUG
    std::cout << "Automated Test Result: " << testAllFunctions() << '\n';
#endif // DEBUG

    int score{ g_startScore };

    std::cout << "Starting score is: " << score << '\n';

    return 0;
}