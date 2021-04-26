class Solution {
public:
    string getCleanWord(string word){
        string clean_word = "";
        for(auto c: word){
            if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
                clean_word += tolower(c);
        }
        return clean_word;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, bool> bannedMap;
        for(auto& word: banned)
            bannedMap[word] = true;
        
        for(int i = 0; i < paragraph.size(); i++){
            if(paragraph[i] == ' ' || (paragraph[i] >= 'a' && paragraph[i] <= 'z')
              || (paragraph[i] >= 'A' && paragraph[i] <= 'Z') ) continue;
            paragraph[i] = ' ';
        }
        //cout << paragraph << endl;
        stringstream paragraph_stream(paragraph);
        string word;
        
        int top_freq = -1;
        string most_freq_word = "";
        map<string, int> word_by_freq;
        
        while(getline(paragraph_stream, word, ' ')){
            word = getCleanWord(word);
            if(word.size() == 0) continue;
            //cout << word << "#" << endl;
            if(bannedMap.find(word) == bannedMap.end()){
                    word_by_freq[word] += 1;
                    if(top_freq < word_by_freq[word]){
                        top_freq = word_by_freq[word];
                        most_freq_word = word;
                    }
            }//banned-if-end
        }//end-while
        return most_freq_word;
    }
};