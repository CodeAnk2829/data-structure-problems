#include "TrieNode.h"
#include <iostream>
#include <string>
using namespace std;
class Trie
{
private:
    TrieNode* root;

public:    
    Trie() {
        root = new TrieNode('\0');
    }

private:
    void insertWord(TrieNode* root, string word) {
        // Base Case
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
    
        // Recursive Call
        insertWord(child, word.substr(1));
    }

public:
    // For User
    void insertWord(string word) {
        insertWord(root, word);
    }

private:
    bool searchWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] != NULL) {
            return searchWord(root->children[index], word.substr(1));
        } 
        return false;
    }

public:
    bool searchWord(string word) {
        return searchWord(root, word);
    }

private:
    void removeWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            root->isTerminal = false;
            return;
        }

        // Small Calculations
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Word not found
            return;
        }

        // Recursive Call
        removeWord(child, word.substr(1));

        // Remove child if it is useless
        if(root->isTerminal == false) {
            for(int i = 0; i < 26; ++i) {
                if(root->children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

public:
    void removeWord(string word) {
        removeWord(root, word);
    }
};