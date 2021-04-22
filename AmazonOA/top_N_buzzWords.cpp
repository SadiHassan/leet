#include <bits/stdc++.h>
using namespace std;

struct Toy{
    string name;
    int total_freq;
    int doc_freq;
};

bool comp(Toy ob1, Toy ob2){
        if(ob1.total_freq == ob2.total_freq){
            if(ob1.doc_freq == ob2.doc_freq){
                    return ob1.name <= ob2.name;
            }
            else
                return ob1.doc_freq > ob2.doc_freq;
        }
        else
            return ob1.total_freq > ob2.total_freq;
}

class Solution {
public:

    vector<string> TopNToys(int numToys, int topToys, vector<string> toys, int numQuotes, vector<string> quotes) {
        vector<string> ans;
        //make lower-case for all quotes
        //also replace non letters to space (assuming toy names will contain letters only!!!!!
        //what-if toy names contain non-letters?
        //in that case, map cannot be used and for each toyname we will have to loop through each quotes
        for(int i = 0; i < quotes.size(); i++){
            for(int j = 0; j < quotes[i].size(); j++)
                if( (quotes[i][j] >= 'a' && quotes[i][j] <= 'z') || (quotes[i][j] >= 'A' && quotes[i][j] <= 'Z') )
                    quotes[i][j] = tolower(quotes[i][j]);
                else quotes[i][j] = ' ';
        }

        //make lower-case for all toys
        for(int i = 0; i < toys.size(); i++)
            for(int j = 0; j < toys[i].size(); j++)
                toys[i][j] = tolower(toys[i][j]);
        //take all toys names in a map
        map<string, int> m;
        vector<Toy> arr;
        for(int i = 0; i < toys.size(); i++){
            Toy ob;
            ob.name = toys[i];
            ob.total_freq = 0;
            ob.doc_freq = 0;
            arr.push_back(ob);

            m[toys[i]] = i;
        }

        for(int i = 0; i < quotes.size(); i++){
            //tokenize quotes to words and check if map contains it or nor
            //bool found_in_this_quote = false;
            map<string, bool> found_in_this_quote;
            stringstream single_quote(quotes[i]);
            string word;
            while(getline(single_quote, word, ' ')){
                    if(m.find(word) != m.end()){
                        int ind = m[word];
                        Toy ob = arr[ ind ];
                        ob.total_freq += 1;
                        if(found_in_this_quote.find(word) == found_in_this_quote.end()){
                            found_in_this_quote[ word ] = true;
                            ob.doc_freq += 1;
                        }
                        arr[ind] = ob; //updated object is saved back to array
                    }
            }
        }
        /*
        for(int i = 0; i < quotes.size(); i++){
            for(int j = 0; j < quotes[i].size(); j++)
                cout << quotes[i][j];
            cout << endl;
        }
        */
        sort(arr.begin(), arr.end(), comp);

        for(int i = 0; i < arr.size(); i++)
            cout << arr[i].name << " " << arr[i].total_freq << " " << arr[i].doc_freq << endl;
        return ans;
    }
};

int main(){

Solution* p;
int numToys = 6;
int topToys = 2;
vector<string> toys; //= {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};
toys.push_back("aaa"); //elmo
toys.push_back("bbb"); //elsa
toys.push_back("legos");
toys.push_back("drone");
toys.push_back("tablet");
toys.push_back("warcraft");

int numQuotes = 6;
vector<string> quotes; /* = {
        "Elmo is the hottest of the season! Elmo will be on every kid's wishlist!",
        "The new Elmo dolls are super high quality",
        "Expect the Elsa dolls to be very popular this year, Elsa!",
        "Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good",
        "For parents of older kids, look into buying them a drone",
        "Warcraft is slowly rising in popularity ahead of the holiday season"
};
*/
quotes.push_back("bbb Elmo is the hottest of the season! Elmo will be on every kid's wishlist!");
quotes.push_back("bbb aaa aaa The new Elmo dolls are super high quality");
quotes.push_back("bbb aaa Expect the Elsa dolls to be very popular this year, Elsa!");
quotes.push_back("bbb aaa Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good");
quotes.push_back("bbb aaa For parents of older kids, look into buying them a drone");
quotes.push_back("bbb aaa Warcraft is slowly rising in popularity ahead of the holiday season");

vector<string> ans = p->TopNToys(numToys, topToys, toys, numQuotes, quotes);

return 0;
}
