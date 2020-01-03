class Solution {
    struct TrieNode {
        TrieNode* children[26];
        vector<string> strs;
        
        TrieNode() {
            for (auto& child : children) {
                child = nullptr;
            }
        }
        
        void insert(string s) {
            TrieNode* curr = this;
            for (char c : s) {
                if (!curr->children[c - 'a']) {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
                curr->strs.push_back(s);
            }
        }
        
        vector<string> find(string s) {
            TrieNode* curr = this;
            for (char c : s) {
                if (!curr->children[c - 'a']) {
                    return {};
                }
                curr = curr->children[c - 'a'];
            }
            if (curr->strs.size() < 3) {
                return curr->strs;
            }
            return vector<string>(curr->strs.begin(), curr->strs.begin() + 3);
        }
    };
    
    TrieNode* root = nullptr;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        buildTrie(products);
        vector<vector<string>> ret;
        for (int len = 1; len <= searchWord.size(); len++) {
            string s = searchWord.substr(0, len);
            ret.push_back(root->find(s));
        }
        return ret;
    }
    
    void buildTrie(vector<string>& products) {
        root = new TrieNode();
        for (auto& product : products) {
            root->insert(product);
        }
    }
};