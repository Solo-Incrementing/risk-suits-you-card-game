#include "Random.h"

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

/*
* Test geenerateRandomCardSuit function
* @param testCount - number of tests to run
* @return 0 if all cases pass, 1 if a test fails
*/
int testGenerateRandomCardSuit(int testCount)
{
    for (int i{ 0 }; i < testCount; ++i)
    {
        char cardSuit{ generateRandomCardSuit() };

        switch (cardSuit)
        {
        case 'C':
        case 'S':
        case 'D':
        case 'H':
            break;
        default:
            return 1;
        }
    }

    return 0;
}

/*
* Test geenerateRandomCardType function
* @param testCount - number of tests to run
* @return 0 if all cases pass, 1 if a test fails
*/
int testGenerateRandomCardType(int testCount)
{
    int numberCount{ 0 };
    int faceCount{ 0 };
    int aceCount{ 0 };
    int otherCount{ 0 };

    for (int i{ 0 }; i < testCount; ++i)
    {
        char cardType{ generateRandomCardType() };

        switch (cardType)
        {
        case 'N':
            ++numberCount;
            break;
        case 'F':
            ++faceCount;
            break;
        case 'A':
            ++aceCount;
            break;
        default:
            ++otherCount;
        }
    }

    //std::cout << "Number Count: " << numberCount << '\n';
    //std::cout << "Face Count: " << faceCount << '\n';
    //std::cout << "Ace Count: " << aceCount << '\n';
    //std::cout << "Other Count: " << otherCount << '\n';

    if (otherCount > 0) return 1;

    return 0;
}

int main()
{
    return 0;
}