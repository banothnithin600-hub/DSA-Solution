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
    Trie(){
        root=new Node();
        
    }
    void insert(string key){
        Node*temp = root;
        for(int i=0;i<key.length();i++){
            if(temp->child.count(key[i])==0){
                temp->child[key[i]]=new Node();
            }
            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }
    bool search(string key){
        Node*temp = root;
        for(int i=0;i<key.size();i++){
            if(temp->child.count(key[i])){
                temp=temp->child[key[i]];
            }else{
                return false;
            }
        }
      return  temp->endofword;
    }
};
class Solution {
public:
   // Change return type to vector<string> so you can safely 'return ans;'
vector<string> helper(Trie &trie, string s) {
    vector<string> ans;
    
    // Base Case
    if (s.size() == 0) {
        ans.push_back(""); // Return an empty string base to append to
        return ans;
    }
    
    for (int i = 0; i < s.length(); i++) {
        string first = s.substr(0, i + 1);
        string second = s.substr(i + 1);
        
        // If the prefix is a valid word, get all valid sentences for the suffix
        if (trie.search(first)) {
            vector<string> sub_sentences = helper(trie, second);
            
            // Combine the current word with all valid suffix combinations
            for (string sentence : sub_sentences) {
                if (sentence == "") {
                    ans.push_back(first); // End of the string reached
                } else {
                    ans.push_back(first + " " + sentence);
                }
            }
        }
    }
    return ans; 
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
     Trie trie;
    // vector<string>arr;
     for(int i=0;i<wordDict.size();i++){
         trie.insert(wordDict[i]);
     }   
      return helper(trie,s);
    }
};