#include <bits/stdc++.h>
using namespace std;

string generate_string(int A, int B, int C){

    if(A + B + C == 0) return "";

    string s = "";
    if( A + B == 0){
        for(int i = 1; i <= min(2,C); i++) s += 'c';
        return s;
    }
    if( A + C == 0){
        for(int i = 1; i <= min(2,B); i++) s += 'b';
        return s;
    }
    if( B + C == 0){
        for(int i = 1; i <= min(2,A); i++) s += 'a';
        return s;
    }

    priority_queue< pair<int,char> > pq;
    pair<int,char> first, second;


    pq.push({A,'a'}); pq.push({B,'b'}); pq.push({C,'c'});

    while(!pq.empty())
    {
        first = pq.top(); pq.pop();
        int len = s.size();
        if(len > 0 && s[len - 1] == first.second){
            if(pq.empty()) break; // s is the answer
            else{
                second = pq.top();pq.pop();
                s += second.second;
                second.first -= 1;
                if(second.first != 0) pq.push(second);
                pq.push(first);
            }
        }
        else{
            int limit = min(2, first.first);
            for(int i = 0; i < limit; i++){
                s += first.second;
                first.first -= 1;
            }
            if(first.first != 0) pq.push(first);
        }
    }
    return s;
}

bool is_valid(string str){
    int len = str.size();
    if(len < 3) return true;
    for(int i = 0; i < len - 3; i++){
        if(str[i] == str[i + 1] && str[i + 1] == str[i + 2])
            return false;
    }
    return true;
}

int main() {
    int A, B , C;

    A = 5;
    B = 3;
    C = 3;

    int MIN = 1;
    int MAX = 100;

    string ans = generate_string(A, B, C);
    cout << ans << " " << ans.size() << " Valid = " << is_valid(ans)<< endl;
    bool output = true;
    if(output){
            freopen("C:\\Users\\sadi\\GitHub\\leet\\Codility\\output.csv", "w", stdout);
            for(int A = MIN; A <= MAX; A++){
                for(int B = MIN; B <= MAX; B++){
                    for(int C = MIN; C <= MAX; C++){
                            string ans = generate_string(A, B, C);
                            int len = ans.size();
                            string validity = "";
                            if(!is_valid(ans))
                                validity = "INVALID";
                            cout << A << "," << B << "," << C << "," << len << "," << validity << ","<< ans << endl;
                    }
                }
            }
            fclose(stdout);
    }
    return 0;
}
