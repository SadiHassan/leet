class Trie {
public:

    class Node{
      public:
        char value;
        vector<Node*> children;
        bool endPoint = false;
        Node(char ch){
            this->value = ch;
        }
        void setEnd(bool val){
            this->endPoint = true;
        }
        bool getEnd(){
            return this->endPoint;
        }
    };

    map<char, Node*> m;

    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.size() == 0)
            return;
        if(m.find(word[0]) == m.end()){
            Node* p = new Node(word[0]);
            m[word[0]] = p;
            for(int i = 1; i < word.size(); i++){
                Node* q = new Node(word[i]);
                p->children.push_back(q);
                cout << word[i-1] << " " << p->children.size() << "  " << p->children[0]->value <<endl;
                p = q;
            }
            p->setEnd(true);
        }
        else{
            Node* p = m[word[0]];

            for(int i = 1; i < word.size(); i++){
                bool new_child = true;
                for(int j = 0; j < p->children.size(); j++){
                    if(word[i] == p->children[j]->value){
                        //cout << word[i-1] << " " << p->children.size() << "  " << p->children[0]->value <<endl;
                        p = p->children[j];
                        new_child = false;
                        break;
                    }
                }

                if(new_child){
                    Node* q = new Node(word[i]);
                    p->children.push_back(q);
                    //cout << word[i-1] << " " << p->children.size() << "  " << p->children[0]->value <<endl;
                    p = q;
                    //break;
                }
            }
            //cout << p->value << endl;
            p->setEnd(true);
        }//END else
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(m.find(word[0]) == m.end())
            return false;
        Node* p = m[word[0]];
        int i;
        int total_char_matched = 1;
        for(i = 1; i < word.size(); i++){
                for(int j = 0; j < p->children.size(); j++){
                    if(word[i] == p->children[j]->value){
                        total_char_matched++;
                        //if(i < word.size() - 1)
                        p = p->children[j];
                        break;
                    }
                }
        }
        //cout << word.size() << " --- " << i << endl;
        if(p->getEnd() && total_char_matched == i) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(m.find(prefix[0]) == m.end())
            return false;
        Node* p = m[prefix[0]];
            for(int i = 1; i < prefix.size(); i++){
                bool new_child = true;
                for(int j = 0; j < p->children.size(); j++){
                    if(prefix[i] == p->children[j]->value){
                        p = p->children[j];
                        new_child = false;
                        break;
                    }
                }

                if(new_child){
                    return false;
                }
            }
        return true;
    }
};