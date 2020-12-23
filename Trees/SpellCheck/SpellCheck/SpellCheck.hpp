//
//  SpellCheck.hpp
//  SpellCheck
//
//  Created by Adam Saher on 13/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef SpellCheck_hpp
#define SpellCheck_hpp

#include <iostream>
#include <string> 

class SpellCheck;

class Node {
    char letter_;
    bool terminal_;
    static const unsigned NUM_OF_ENGLISH_LETTERS;
    Node** next_;
    
    Node(const char& letter = '\0', const bool& terminal = false);
    friend SpellCheck;
};


class SpellCheck {
    Node* root_;
public:
    SpellCheck(std::string* data, unsigned size);
    
    
    /**
     Add a new word to the trie-dictionary. If the word already exists, do nothing.

     @param str A word to be added to the trie-dictionary
     */
    void addWord(const std::string& str);
    
    
    /**
     Look up the passed word in your dictionary.

     @param word Any English word
     @return true if the word exists in the dictionary, false otherwise.
     */
    bool lookup(const std::string& word) const;
    
    
    
    /**
     Given the first part of a word, suggest possible English words by adding them to the
     suggestions array. For instance, if the user passed 'app', append to the array: 'apple',
     'appartment', ..

     @param word Any English word
     @param suggestions An array containing the suggested words in ascending order.
     @return the number of suggested words
     */
    unsigned suggest(const std::string& word, std::string* suggestions);
    
    ~SpellCheck();
    
    
private:
    /**
     Count the number of nodes where terminal = true

     @param node A subtree
     @return an unsigned integer for the number of terminals.
     */
    static unsigned count_terminals(const Node* node);
    
    
    /**
     Fill the passed array with all the strings available in the trie that start with the
     passed substring

     @param node A subtree
     @param substring A prefix or the first couple of letters of a word
     @param suggestions An array to be filled with all words that start with the passed substring.
     @param num_of_suggested_words The number of words that have been added to the suggestion array.
     */
    static void suggest(const Node* node, const std::string& substring, std::string* suggestions, unsigned& num_of_suggested_words);
    
    
    /**
     Delete the passed node and all its children.

     @param node A subtree
     */
    static void destroy(Node* node);
};

#endif /* SpellCheck_hpp */
