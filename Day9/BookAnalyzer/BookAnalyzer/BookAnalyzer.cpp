//
//  BookAnalyzer.cpp
//  BookAnalyzer
//
//  Created by Laura Zhang on 9/1/22.
//

#include "BookAnalyzer.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

// parse and analyze the file
int parseFile(const char* file_name, string key_word) {
    ifstream myStream(file_name);
    
    if (! filesystem::exists(file_name)) {                          // if the file does not exist
        system("PAUSE");
        return WrongFileName;                                       // return -1
    }
    
    if (myStream.fail()) {                                          // if we fail to open the file
        system("PAUSE");
        return OpenFailed;                                          // return -2
    }
    
    string word;                                                    // represent a single word
    vector<string> words;                                           // stores all the words
    vector<int> key_word_char_index;                                // stores the indexes of each key words' first char
    vector<int> key_word_index;                                     // stores the indexes of each key words
    
    int word_counter = 0;                                           // stores the number of words
    int char_counter = 0;                                           // stores the number of characters
    int key_word_counter = 0;                                       // stores the number of key words
    
    int short_word_len = 999;                                       // stores the length of the shortest word
    int long_word_len = 0;                                          // stores the length of the longest word

    int short_word_index = -1;                                      // stores the index of the shortest word
    int long_word_index = -1;                                       // stores the index of the longest word
    
    string title = "Title:";
    string author = "Author:";
    string release_date = "Release";
    
    int title_index = -1;
    int author_index = -1;
    int release_date_index = -1;
    
    while (myStream >> word) {                                      // read the file and extract words
        words.push_back(word);                                      // push each non-empty string into the vector
        int word_len = (int) word.length();                         // store the length of the word
        
        if (word_counter < 200) {
            if (word == title) {
                title_index = word_counter;
            }
            
            else if (word == author) {
                author_index = word_counter;
            }
            
            else if (word == release_date) {
                release_date_index = word_counter;
            }
        }
        
        if (word == key_word) {                                     // if the word is the word we are looking for
            key_word_char_index.push_back(char_counter);            // push the index of the beginning char of the word
            key_word_index.push_back(word_counter);                 // push the index of the word
            key_word_counter++;                                     // count to the number of words
        }
        
        if (word_len > long_word_len) {
            long_word_len = word_len;                               // replace the length of the longest word with current word
            long_word_index = word_counter;                         // store the index of the current word
        }
        
        else if (word_len < short_word_len) {
            short_word_len = word_len;                              // replace the length of the shortest word with current word
            short_word_index = word_counter;                        // store the index of the current word
        }
        
        char_counter += word_len;                                   // count to the number of characters
        word_counter++;                                             // count to the number of words
    }
    
    myStream.close();
    
    string short_word = words[short_word_index];                    // locate the shortest word
    string long_word = words[long_word_index];                      // locate the longest word
    
    title = "";
    author = "";
    
    if (title_index > -1 && author_index > title_index) {
        for (int i = title_index + 1; i < author_index; i++) {
            title += words[i];
            title += " ";
        }
        
        if (release_date_index > author_index) {
            for (int j = author_index + 1; j < release_date_index; j++) {
                author += words[j];
                author += " ";
            }
            
            author.pop_back();
        }
        
        else {
            author = "unknown";
        }
    }
    
    else {
        title = "unknown ";
        author = "unknown";
    }
    
    cout << "Statistics for " << title;                             // print out the results
    cout << "by " << author << ":" << endl;
    cout << "  Number of words: " << word_counter << endl;
    cout << "  Number of characters: " << char_counter << endl;
    cout << "  The shortest word is \"" << short_word;
    cout << "\", and the longest word is \"";
    cout << long_word << "\"" << endl << endl;
    
    if (key_word_index.size() > 0) {                                // check if the key word is ever found
        cout << "The word \"" << key_word << "\" appears ";
        cout << key_word_counter << " times:" << endl;
        
        for (int i = 0; i < key_word_index.size(); i++) {           // loop the vector of key words' indexes
            int char_location = key_word_char_index[i] * 100 / char_counter;
            int word_location = key_word_index[i];
            
            cout << "  at " << char_location << "%: \"";            // print out the indexes of key words
            cout << words[word_location - 1] << " ";                // print the key word and two surrounding words
            cout << words[word_location] << " ";
            cout << words[word_location + 1];
            cout << "\"" << endl;
        }
    }
    
    else {                                                          // if the key word is never found
        cout << "The word \"" << key_word << "\" appears 0 times." << endl;
    }
    
    return Success;                                                 // return 0
}

// print an error message indicating the problem and return the enumeration label
int error_message(const char* file_name, string err_message, int err_type) {
    cerr << "Usage: " << file_name << endl << err_message << endl;
    exit(err_type);
}
