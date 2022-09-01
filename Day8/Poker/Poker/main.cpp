//
//  main.cpp
//  Poker
//  Group members: Muyuan Zhang, Thomas Ford
//  Created by Laura Zhang on 8/31/22.
//

/*
 1,000,000 times of shuffing:
 Flush:          0.1925%
 Straight:       0.3555%
 Straight Flush: 0.0014%
 Royal Flush:    0.0001%
 Full House:     0.144%
 */

#include "Poker.h"

#include <iostream>
#include <cstdlib>

using namespace std;

// create a deck of cards
vector<Card> createDeck() {
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
void printDeck(vector<Card> card_deck) {
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

// shuffle the deck of cards
void shuffleDeck(vector<Card>& deck) {
    for (int i = (int) deck.size() - 1; i > 0; i--) {
        int j = rand() % i + 0;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// check if all the cards are the same suit
bool isFlush(vector<Card> deck) {
    string first_suit = deck[0].suit;
    
    for (int i = 1; i < 5; i++) {
        if (deck[i].suit != first_suit) {
            return false;
        }
    }
    
    return true;
}

// check if all 5 cards are in numerical order
// is 10, J, Q, K, A a straight?
bool isStraight(vector<Card> deck) {
    vector<int> ranks;
    
    for (int i = 0; i < 5; i++) {
        int cur_rank = deck[i].rank;
        ranks.push_back(cur_rank);
    }
    
    sort(ranks.begin(), ranks.end());
    
    for (int j = 0; j < 4; j++) {
        // if the deck is not royal flush and not continuous, it is not straight
        if (ranks[j + 1] - ranks[j] != 1 &&
            !(ranks[0] == 1 && ranks[1] == 10 && ranks[2] == 11 &&
            ranks[3] == 12 && ranks[4] == 13)) {
            return false;
        }
    }
    
    return true;
}

// check if the hand is a straight and a flush
bool isStraightFlush(vector<Card> deck) {
    if ((isStraight(deck)) && (isFlush(deck))) {
        return true;
    }
    
    return false;
}

// check if the hand is a straight flush whose low card is a ten
bool isRoyalFlush(vector<Card> deck) {
    vector<int> ranks;
    
    if (isStraightFlush(deck)) {
        // push the ranks of the cards into the vector
        for (int i = 0; i < 5; i++) {
            int cur_rank = deck[i].rank;
            ranks.push_back(cur_rank);
        }
        
        // sort the vector of the card ranks
        sort(ranks.begin(), ranks.end());
        
        if (ranks[0] == 1 && ranks[1] == 10) {
            return true;
        }
    }
    
    return false;
}

// check if there are 3 of one rank, and 2 of another
bool isFullHouse(vector<Card> deck) {
    vector<int> ranks;
    
    for (int i = 0; i < 5; i++) {
        int cur_rank = deck[i].rank;
        ranks.push_back(cur_rank);
    }
    
    sort(ranks.begin(), ranks.end());
    
    if ((ranks[0] == ranks[1] && ranks[0] == ranks[2] && ranks[3] == ranks[4]) ||
        (ranks[0] == ranks[1] && ranks[2] == ranks[3] && ranks[3] == ranks[4])) {
        return true;
    }
    
    return false;
}

// extract five cards from the deck
// reference: https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector
vector<Card> pickFiveCards(vector<Card>& deck) {
    vector<Card>::const_iterator first = deck.begin() + 0;
    vector<Card>::const_iterator last = deck.begin() + 5;
    vector<Card> hand(first, last);
    
    return hand;
}

// first shuffle the deck, and pick a poker hand,
// then check if it is one of the hands you test for above,
// and keep track of the total numbers
vector<int> shuffleAndCount(vector<Card>& deck, int times) {
    vector<int> counters;

    int flush_counter = 0;
    int straight_counter = 0;
    int straight_flush_counter = 0;
    int royal_flush_counter = 0;
    int full_house_counter = 0;
    
    for (int i = 0; i < times; i++) {
        shuffleDeck(deck);
        
        vector<Card> five_cards = pickFiveCards(deck);
        
        if (isFlush(five_cards)) {
            flush_counter++;
        }
        
        if (isStraight(five_cards)) {
            straight_counter++;
        }
        
        if (isStraightFlush(five_cards)) {
            straight_flush_counter++;
        }
        
        if (isRoyalFlush(five_cards)) {
            royal_flush_counter++;
        }
        
        if (isFullHouse(five_cards)) {
            full_house_counter++;
        }
    }
    
    counters = {flush_counter, straight_counter, straight_flush_counter, royal_flush_counter, full_house_counter};
    
    return counters;
}

int main(int argc, const char * argv[]) {
    // change the seed for rand()
    srand(time(NULL));
    
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
    Card card_11 = {1, "Diamonds"};
    Card card_12 = {2, "Diamonds"};
    Card card_13 = {3, "Hearts"};
    Card card_14 = {3, "Diamonds"};
    
    vector<Card> spades = {card_1, card_2, card_3, card_4, card_5};
    vector<Card> spadesStraight = {card_5, card_4, card_3, card_2, card_1};
    vector<Card> fullHouse = {card_2, card_12, card_3, card_13, card_14};
    vector<Card> royalFlush = {card_1, card_6, card_7, card_8, card_9};
    vector<Card> straight = {card_11, card_12, card_3, card_4, card_5};
    
    // cout << isStraight(royalFlush) << endl;
    
    vector<Card> deck = createDeck();
    // deckPrinter(deck);
    
    cout << "Enter the times to shuffle the card deck:" << endl;
    int times;
    cin >> times;
    
    while (times < 1) {
        cout << "Please enter a positive integer." << endl;
        cout << "Enter the times to shuffle the card deck:" << endl;
        cin >> times;
    }

    vector<int> shuffled_hand = shuffleAndCount(deck, times);

    cout << "Flush:          " << shuffled_hand[0] * 100.0 / times << "%" << endl;
    cout << "Straight:       " << shuffled_hand[1] * 100.0 / times << "%" << endl;
    cout << "Straight Flush: " << shuffled_hand[2] * 100.0 / times << "%" << endl;
    cout << "Royal Flush:    " << shuffled_hand[3] * 100.0 / times << "%" << endl;
    cout << "Full House:     " << shuffled_hand[4] * 100.0 / times << "%" << endl;
    
    return 0;
}
