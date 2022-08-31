//
//  Poker.h
//  Poker
//
//  Created by Laura Zhang on 8/31/22.
//

#ifndef Poker_h
#define Poker_h

#include <vector>
#include <string>

struct Card {
    int rank;
    std::string suit;
};

std::vector<Card> createCardDeck();

void deckPrinter(std::vector<Card> card_deck);

#endif /* Poker_h */
