class Node{
    public:
    unordered_map<char,Node*>child;
    bool endofword;
    Node(){
        endofword = false;
    }
};
class Trie{
    Node*root;
public:
    Trie() {
        root=new Node();
       // root->freq = -1;
    }
    
    void insert(string word) {
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->child.count(word[i])==0){ // Not exist
                temp->child[word[i]]=new Node;
                //temp->child[word[i]]->freq=1;
            //}else{
             //    temp->child[word[i]]->freq++;
            }
            temp=temp->child[word[i]];
        }
        temp->endofword=true;
    }
    
    bool search(string word) {
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->child.count(word[i])){
                temp = temp->child[word[i]];
            }
            else{
                return false;
            }
        }
        return temp->endofword;
    }
    
    bool startsWith(string prefix) {
        Node*temp = root;
        for(int i=0;i<prefix.size();i++){
            if(temp->child.count(prefix[i])){
                temp=temp->child[prefix[i]];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    // Added a memoization map to prevent TLE
    unordered_map<string, bool> memo; 

    bool helper(Trie &trie, string key) {
        if (key.size() == 0) {
            return true;
        }
        
        // Return cached result if already calculated
        if (memo.count(key)) {
            return memo[key];
        }

        // Fixed typo: changed keys.size() to key.size()
        for (int i = 0; i < key.size(); i++) {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);

            // Fixed: called search on the trie object
            if (trie.search(first) && helper(trie, second)) {
                return memo[key] = true;
            }
            // Removed the "else return false" to allow the loop to continue trying other lengths
        }

        return memo[key] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie; // Ensure you have your Trie class defined elsewhere in your code
        
        for (int i = 0; i < wordDict.size(); i++) {
            trie.insert(wordDict[i]);
        }
        
        memo.clear(); // Clear memo for fresh test cases
        return helper(trie, s); 
    }
};
