class Node{
    public:
    unordered_map<char,Node*>child;
    bool endofword;
    int freq;
    Node(){
        endofword = false;
        freq=0;
    }
};
class Trie {
    Node*root;
public:
    Trie() {
        root=new Node();
        root->freq = -1;
    }
    
    void insert(string word) {
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->child.count(word[i])==0){ // Not exist
                temp->child[word[i]]=new Node;
                temp->child[word[i]]->freq=1;
            }else{
                 temp->child[word[i]]->freq++;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */