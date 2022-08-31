//
//  main.cpp
//  Poker
//  Group members: Muyuan Zhang, Thomas Ford
//  Created by Laura Zhang on 8/31/22.
//

#include "Poker.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// create a deck of cards
vector<Card> createCardDeck() {
    vector<Card> card_deck;                                                 // create an empty vector to store the deck
    vector<string> suits = {"Hearts", "Spades", "Clubs", "Diamonds"};       // create a vector to store the suits
    
    Card cur_card;                                                          // create an empty card
    
    for (int i = 0; i < 4; i++) {                                           // 4 types of suits
        for (int j = 1; j < 14; j++) {                                      // 13 types of ranks
            cur_card.suit = suits[i];                                       // assign the card a suit
            cur_card.rank = j;                                              // assign the card a rank
            
            card_deck.push_back(cur_card);                                  // push the current card into the deck
        }
    }
    
    return card_deck;
}

// print the deck
void deckPrinter(vector<Card> card_deck) {
    string ace = "A";
    string jack = "J";
    string queen = "Q";
    string king = "K";
    
    for (Card card : card_deck) {
        // rank 2 to 10 can be printed directly
        if (card.rank > 1 && card.rank < 11) {
            cout << card.suit << ", " << card.rank << endl;
        }
        
        else if (card.rank == 1) {
            cout << card.suit << ", " << ace << endl;
        }
        
        else if (card.rank == 11) {
            cout << card.suit << ", " << jack << endl;
        }
        
        else if (card.rank == 12) {
            cout << card.suit << ", " << queen << endl;
        }
        
        else if (card.rank == 13) {
            cout << card.suit << ", " << king << endl;
        }
        
        else {
            cerr << "Ranking of the card is out of range!" << endl;
        }
    }
}

void shuffleDeck(vector<Card>& deck) {
    // change the seed for rand()
    srand(time(NULL));
    
    for (int i = (int) deck.size() - 1; i > 0; i--) {
        int j = rand() % i + 0;
        // cout << i << " " << j << endl;
        Card temp = deck[i];
        // cout << deck[j].suit << " " << deck[j].rank << endl;
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

bool isFlush(vector<Card> deck) {
    string first_suit = deck[0].suit;
    
    for (int i = 1; i < 5; i++) {
        if (deck[i].suit != first_suit) {
            return false;
        }
    }
    
    return true;
}

bool isStraight(vector<Card> deck) {
    vector<int> ranks;
    
    for (int i = 0; i < 5; i++) {
        int cur_rank = deck[i].rank;
        ranks.push_back(cur_rank);
    }
    
    return is_sorted(ranks.begin(), ranks.end());
}

int main(int argc, const char * argv[]) {
    // create and print a card deck
    /*
    vector<Card> deck_1 = createCardDeck();
    shuffleDeck(deck_1);
    deckPrinter(deck_1);
     */
    
    // create some test "decks" which contain only 5 cards
    Card card_1 = {1, "Spades"};
    Card card_2 = {2, "Spades"};
    Card card_3 = {3, "Spades"};
    Card card_4 = {4, "Spades"};
    Card card_5 = {5, "Spades"};
    Card card_6 = {10, "Spades"};
    Card card_7 = {11, "Spades"};
    Card card_8 = {12, "Spades"};
    Card card_9 = {13, "Spades"};
    Card card_10 = {1, "Hearts"};
    
    vector<Card> spades = {card_1, card_2, card_3, card_4, card_5};
    
    cout << isStraight(spades) << endl;
    
    return 0;
}
