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

int main()
{
    return 0;
}