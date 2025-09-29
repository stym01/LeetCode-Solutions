struct Node{
    Node*links[26];
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void setKey(char ch,Node*node){
        node->links[ch-'a']=new Node();
    }

    Node*getKey(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }

};

class Trie {
private:
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node*node=root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->setKey(word[i],node);
            }
            node=node->getKey(word[i]);
        }

        node->setEnd();

    }
    
    bool search(string word) {
        Node*node=root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->getKey(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node*node=root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->getKey(word[i]);
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