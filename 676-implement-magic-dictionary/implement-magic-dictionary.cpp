#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool endofword;
    Node() {
        endofword = false;
    }
};

class Trie {
public: // Made public so MagicDictionary can use it
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.length(); i++) {
            if (temp->child.count(key[i]) == 0) {
                temp->child[key[i]] = new Node();
            }
            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }
    
    // Your exact search logic, placed here to look for perfect word matches
    bool exactSearch(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->child.count(key[i])) {
                temp = temp->child[key[i]];
            } else {
                return false;
            }
        }
        return temp->endofword;
    }
};

class MagicDictionary {
    Trie* trie; // Connected your Trie class here

public:
    MagicDictionary() {
        trie = new Trie(); // Instantiated the Trie
    }
    
    void buildDict(vector<string> dictionary) {
        // FIX: Insert every word from the input into your Trie structure
        for (string word : dictionary) {
            trie->insert(word);
        }
    }
    
    bool search(string searchWord) {
        // Systematically try modifying exactly one character at a time
        for (int i = 0; i < searchWord.length(); i++) {
            char original_char = searchWord[i]; // Remember the original character
            
            // Try substituting it with every other lowercase English letter
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original_char) continue; // Skip substituting with itself
                
                searchWord[i] = c; // Change the character
                
                // Use your iterative logic to see if this modified word exists
                if (trie->exactSearch(searchWord)) {
                    return true; // Match found!
                }
            }
            
            searchWord[i] = original_char; // Restore the character before moving to the next index
        }
        
        return false; // Exhausted all single-character variations without a match
    }
};
