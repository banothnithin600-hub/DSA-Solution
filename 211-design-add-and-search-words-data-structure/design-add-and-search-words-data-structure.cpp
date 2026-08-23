class Node{
    public:
    unordered_map<char,Node*>child;
    bool endofword;
    //int freq;
    Node(){
        endofword = false;
        //freq=0;
    }
};
class WordDictionary {
    Node*root;
    bool searchHelper(string& word, int index, Node* curr) {
        // Base case: If we reached the end of the word, check if it forms a complete word
        if (index == word.size()) {
            return curr->endofword;
        }

        char ch = word[index];

        // If it's a wildcard, we must check ALL possible child paths
        if (ch == '.') {
            for (auto& pair : curr->child) {
                // If any path returns true, the search is successful
                if (searchHelper(word, index + 1, pair.second)) {
                    return true;
                }
            }
            return false; // None of the paths matched
        } 
        // If it's a regular character, check if it exists in the map
        else {
            if (curr->child.count(ch) == 0) {
                return false; // Character path doesn't exist
            }
            // Move down to the next node recursively
            return searchHelper(word, index + 1, curr->child[ch]);
        }
    }
public:
    WordDictionary() {
        root=new Node();
       // freq = -1;
    }
    
    void addWord(string word) {
        Node*temp = root;
        for(int i=0;i<word.size();i++){
           if(temp->child.count(word[i])==0){
            temp->child[word[i]]=new Node();
           }
           temp=temp->child[word[i]];
        }
        temp->endofword = true;
    }
    
    bool search(string word) {
       return searchHelper(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */