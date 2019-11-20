#include <iostream>
using namespace std;

string generate_string_core(int A, int B, int C, char AA, char BB, char CC){
    string ans = "";
    while(A > 0){
        if(A > 0) { ans += AA; A--;}
        if(A > 0) { ans += AA; A--;}
        if(B == 0 && C == 0) return ans;
        if(A == 0) break;
        if(B > 0) { ans += BB; B--;}
        if(C > 0) { ans += CC; C--;}
    }

    if(B == 0){
        if(C > 0) ans = CC + ans;
        C--;
        if(C > 0) ans = CC + ans;
        C--;
        return ans;
    }

    if(C == 0){
        if(B > 0) ans = BB + ans;
        B--;
        if(B > 0) ans = BB + ans;
        B--;
        return ans;
    }

    while( B > 0 && C > 0){
        if(B > C){
            if(B > 0) {ans += BB; B--;}
            if(B > 0) {ans += BB; B--;}
            if(C > 0) {ans += CC; C--;}
        }
        else if(C > B){
            if(C > 0) {ans += CC; C--;}
            if(C > 0) {ans += CC; C--;}
            if(B > 0) {ans += BB; B--;}
        }
        else{
            if(B > 0) {ans += BB; B--;}
            if(C > 0) {ans += CC; C--;}
        }
    }

    if(B == 0){
        if(C > 0) ans = CC + ans;
        C--;
        if(C > 0) ans = CC + ans;
        C--;
        return ans;
    }

    if(C == 0){
        if(B > 0) ans = BB + ans;
        B--;
        if(B > 0) ans = BB + ans;
        B--;
        return ans;
    }
    return ans;
}

string generate_string(int A, int B, int C){

    if(A <= 0 && B <= 0 && C <= 0) return "";

    if(A >= B && A >= C && B >= C) return generate_string_core(A, B, C, 'a', 'b', 'c');
    else if(A >= B && A >= C && C >= B) return generate_string_core(A, C, B, 'a', 'c', 'b');

    else if(B >= A && B >= C && A >= C) return generate_string_core(B, A, C, 'b', 'a', 'c');
    else if(B >= A && B >= C && C >= A) return generate_string_core(B, C, A, 'b', 'c', 'a');

    else if(C >= A && C >= B && A >= B) return generate_string_core(C, A, B, 'c', 'a', 'b');
    else if(C >= A && C >= B && B >= A) return generate_string_core(C, B, A, 'c', 'b', 'a');
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

int main(){

    int A, B , C;

    A = 1;
    B = 6;
    C = 5;

    int MIN = 0;
    int MAX = 1000;

    string ans = generate_string(A, B, C);
    int len = ans.size();
    string res;
    if(len == (A + B + C)) res = "True";
    else res = "False";

    //cout<< ans << " : " << len << " " << (A + B + C) << " " << res << endl;

    for(int i = MIN; i <= MAX; i++){
        for(int j = MIN; j <= MAX; j++){
            for(int k = MIN; k <= MAX; k++){
                    string ans = generate_string(i, j, k);
                    if(!is_valid(ans))
                        //cout<< ans << " : OK " << endl;
                    //else
                        cout<< ans << " : oooops! " << endl;
            }
        }
    }
    return 0;
}
