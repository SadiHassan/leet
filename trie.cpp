#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
            Node* temp;
            temp = p;
            for(int i = 1; i < word.size(); i++){
                Node* q = new Node(word[i]);
                p->children.push_back(q);
                //cout << word[i-1] << " " << p->children.size() << "  " << p->children[0]->value <<endl;
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

                        p = p->children[j];
                        new_child = false;
                        break;
                    }
                }

                if(new_child){
                    Node* q = new Node(word[i]);
                    p->children.push_back(q);
                    p = q;
                    break;
                }
            }
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
                        p = p->children[j];
                        total_char_matched++;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main(){

    Trie* trie = new Trie();
    trie->insert("hello");
    cout << trie->search("hello") << endl;   // returns true
    cout << trie->startsWith("hell") << endl;     // returns false
    cout << trie->startsWith("app") << endl; // returns true
    trie->insert("app");
    cout << trie->search("hellowwww") << endl;     // returns true

    /*
    obj->insert("apple");
    obj->insert("appropriate");
    cout<< "apple is there: " << obj->search("apple");
    cout << endl;

    cout<< "appropriate is there: " << obj->search("appropriate");
    cout << endl;

    cout<< "boltu is there: " << obj->search("boltu");
    cout << endl;

    cout<< "app is there: " << obj->startsWith("app");
    cout << endl;

    cout<< "bb is there: " << obj->startsWith("bb");
    cout << endl;
    */
return 0;
}


/*

Input:
["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"]
[[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]

Output:                                         E
[null,null,null,null,null,null,null,false,true,true,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true]

Expected:
[null,null,null,null,null,null,null,false,true,false,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true]


New

Input:
["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"]
[[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]

Output:
[null,null,null,null,null,null,null,false,true,true,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true]


Expected:
[null,null,null,null,null,null,null,false,true,false,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true]



*/


