#include <iostream>

#include "Random.h"
#include "main.h"
#include "tests.h"

#define DEBUG

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
* generate a card number
* @return A random number between 2 and 10 inclusive for a number card
*/
int generateCardNumber()
{
    return Random::get(2, 10);
}

int main()
{
#ifdef DEBUG
    std::cout << testAllFunctions() << '\n';
#endif // DEBUG

    return 0;
}