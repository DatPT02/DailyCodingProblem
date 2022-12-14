#include <iostream>

#include "Trie.cpp"

int main()
{
    std::cout<<"Daily Coding Problem 11"<<std::endl;

    Trie* myTrie = new Trie();

    myTrie->insert("Dog");
    myTrie->insert("Deer");
    myTrie->insert("Deal");

    myTrie->getAutoSuggest("De");

    return 0;
}