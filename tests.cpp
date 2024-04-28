#include "main.h"
#include "tests.h"

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

/*
* Test generateCardNumber function
* @param testCount - number of tests to run
* @return 0 if all cases pass, test number if a test fails
*/
int testGenerateCardNumber(int testCount)
{
    for (int i{ 0 }; i < testCount; ++i)
    {
        int cardNumber{ generateRandomCardNumber() };

        if (cardNumber < 2) return 1;
        if (cardNumber > 10) return 2;
    }

    return 0;
}

int testGenerateRandomCardFace(int testCount)
{
    for (int i{ 0 }; i < testCount; ++i)
    {
        char cardFace{ generateRandomCardFace() };

        switch (cardFace)
        {
        case 'K':
        case 'Q':
        case 'J':
            break;
        default:
            return 1;
        }
    }

    return 0;
}

/*
* Tests all functions
* @param testCount - number of tests to run
* @return 0 if all tests pass, otherwise test number that failed
*/
int testAllFunctions()
{
    if (testGenerateRandomCardSuit(100) != 0) return 1;
    if (testGenerateRandomCardType(1300) != 0) return 2;
    if (testGenerateCardNumber(100) != 0) return 3;
    if (testGenerateRandomCardFace(100) != 0) return 4;

    return 0;
}