#include <iostream>
#include <limits> // for std::numeric_limits
#include <cstdlib> // for std::exit
#include <cctype> // for toupper()

#include "Random.h"
#include "main.h"
#include "tests.h"

#define DEBUG

namespace Constants
{
    constexpr int startScore{ 130 };

    namespace ScoreChange {
        constexpr int correctSuit{ 50 };
        constexpr int incorrectSuit{ -10 };

        constexpr int correctNumberType{ 10 };
        constexpr int incorrectNumberType{ -5 };
        constexpr int correctFaceType{ 100 };
        constexpr int incorrectFaceType{ -50 };
        constexpr int correctAceType{ 200 };
        constexpr int incorrectAceType{ -100 };

        constexpr int correctNumber{ 100 };
        constexpr int incorrectNumber{ -50 };

        constexpr int correctFace{ 50 };
        constexpr int incorrectFace{ -25 };
    }
}


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

/*
* Ignore everything in the input buffer until the next \n
*/
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
* get player input character for a card suit.
* Will keep on asking until a valid input is received.
* @return A character 'C', 'S', 'D' or 'H' representing one of the card suits
*/
char getPlayerSuitGuess()
{
    while (true)
    {
        std::cout << "Guess the suit of the card!\n";
        std::cout << "C - Clubs, S - Spades, D - Diamonds, H - Hearts\n";

        char suitGuess{};
        std::cin >> suitGuess;

        if (!std::cin) // If the previous extraction failed
        {
            if (std::cin.eof()) // If the stream was closed
            {
                std::exit(0); // Shut down the program now (requires #include <cstdlib>)
            }

            // Handle the failure

            std::cin.clear(); // Put us back in 'normal' operation mode
            ignoreLine();     // And remove the bad input
            continue;
        }

        switch (toupper(suitGuess))
        {
        case 'C':
        case 'S':
        case 'D':
        case 'H':
            break;
        default:
            std::cout << "That input is not suit-ed! Try again.\n";
            ignoreLine(); // ignore extraneous input
            continue;
        }

        // Valid Input Entered

        ignoreLine(); // ignore extraneous input

        return static_cast<char>(toupper(suitGuess));
    }
}

int main()
{
#ifdef DEBUG
    std::cout << "Automated Test Result: " << testAllFunctions() << '\n';
#endif // DEBUG

    int score{ Constants::startScore };

    std::cout << "Starting score is: " << score << '\n';

    char suit{ generateRandomCardSuit() };
    char type{ generateRandomCardType() };

    char playerSuitGuess{ getPlayerSuitGuess() };

    (playerSuitGuess == suit)
        ? score += Constants::ScoreChange::correctSuit
        : score += Constants::ScoreChange::incorrectSuit;


    std::cout << "Player Suit guess is: " << playerSuitGuess << '\n';
    std::cout << "The suit was: " << suit << '\n';
    std::cout << "The type was: " << type << '\n';

    std::cout << "Player Score now is: " << score << '\n';

    return 0;
}