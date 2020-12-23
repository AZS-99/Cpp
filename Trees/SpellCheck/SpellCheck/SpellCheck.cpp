//
//  SpellCheck.cpp
//  SpellCheck
//
//  Created by Adam Saher on 13/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include "SpellCheck.hpp"

const unsigned Node::NUM_OF_ENGLISH_LETTERS = 26;

Node::Node(const char& letter, const bool& terminal) {
    letter_ = letter;
    terminal_ = terminal;
    next_ = new Node*[NUM_OF_ENGLISH_LETTERS]();
}



SpellCheck::SpellCheck(std::string* data, unsigned size) {
    root_ = new Node;
    for (unsigned i = 0; i < size; ++i)
        addWord(data[i]);
}


void SpellCheck::addWord(const std::string& str) {
    auto current = root_;
    char ch;
    for (unsigned i = 0; i < str.size(); ++i) {
        ch = str[i];
        if (!current->next_[ch - 97]) //index of every letter in accordance with ASCII
            current->next_[ch - 97] = new Node(ch);
        current = current->next_[ch - 97];
    }
    current->terminal_ = true;
}


bool SpellCheck::lookup(const std::string & str) const{
    auto current = root_;
    for (auto ch : str) {
        if (!current->next_[ch - 97])
            return false;
        current = current->next_[ch - 97];
    }
    return current->terminal_; //if the last character is a terminal, return true.
    
}


unsigned SpellCheck::suggest(const std::string & str, std::string* suggestions) {
    auto current = root_;
    for (auto ch : str) {
        if (!current->next_[ch - 97])
            return 0;
        current = current->next_[ch - 97];
    }
    unsigned num_of_suggested_words = 0;
    SpellCheck::suggest(current, str, suggestions, num_of_suggested_words);
    //number of words under a node = number of terminals that it carries along with its children
    return SpellCheck::count_terminals(current);
}


void SpellCheck::suggest(const Node* node, const std::string& str, std::string* suggestions, unsigned& num_of_suggested_words) {
    if (!node)
        return;
        
    if (node->terminal_)
        suggestions[num_of_suggested_words++] = str;
    
    std::string str2;
    for (unsigned i = 0; i < Node::NUM_OF_ENGLISH_LETTERS; ++i) {
        if (node->next_[i]) {
            str2 = str + node->next_[i]->letter_;
            SpellCheck::suggest(node->next_[i], str2, suggestions, num_of_suggested_words);
        }
    }
}


unsigned SpellCheck::count_terminals(const Node* node) {
    if (!node)
        return 0;
    unsigned count = 0;
    Node* current;
    for (unsigned i = 0; i < Node::NUM_OF_ENGLISH_LETTERS; ++i) {
        current = node->next_[i];
        count += SpellCheck::count_terminals(current);
    }
    if (node->terminal_)
        count += 1;
    return count;
}


void SpellCheck::destroy(Node* node) {
    if (!node)
        return;
    for (unsigned i = 0; i < Node::NUM_OF_ENGLISH_LETTERS; ++i)
        destroy(node->next_[i]);
    delete node->next_;
}


SpellCheck::~SpellCheck() {
    destroy(root_);
}



