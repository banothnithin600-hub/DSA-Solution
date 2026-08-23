#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

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
public: // Changed to public so Solution can use it
    Node* root;

    Trie() { 
        root = new Node(); 
    }

    void insert(string word) { 
        Node* temp = root; 
        for (int i = 0; i < word.size(); i++) { 
            if (temp->child.count(word[i]) == 0) { 
                temp->child[word[i]] = new Node(); 
            } 
            temp = temp->child[word[i]]; 
        } 
        temp->endofword = true; 
    }

    // Returns true if every prefix of the word also exists as a complete word
    bool checkIfAllPrefixesExist(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->child.count(word[i])) {
                temp = temp->child[word[i]];
                if (!temp->endofword) {
                    return false; // Prefix is missing
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution { 
public: 
    string longestWord(vector<string>& words) { 
        Trie trie; 
        for (int i = 0; i < words.size(); i++) { 
            trie.insert(words[i]); 
        } 
        
        string longest = "";
        
        for (const string& word : words) {
            // Check if this word can be built one character at a time
            if (trie.checkIfAllPrefixesExist(word)) {
                // If it's longer, or lexicographically smaller when lengths match
                if (word.size() > longest.size()) {
                    longest = word;
                } else if (word.size() == longest.size() && word < longest) {
                    longest = word;
                }
            }
        }
        
        return longest;
    } 
};
