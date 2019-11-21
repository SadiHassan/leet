#include <bits/stdc++.h>
using namespace std;

bool check(int A, int B, int C){
    if(A > B && A > C && B != 0 && C != 0) return true;
    return false;
}

int zero_count(int A, int B, int C){
    if(A + B == 0 || A + C == 0 || B + C == 0) return 2;
    if(A + B + C == 0) return 3;
    return 1;
}

string generate_string_core2(int A, int B, int C, char AA, char BB, char CC){
    string ans = "";
    if(A == B && B == C){
        for(int i = 0; i < A; i++)
            ans = ans + AA + BB + CC;
        return ans;
    }
    if(A == B){
        while(C > 0){
            ans = ans + AA + BB + CC;
            C -= 1;
            A -= 1;
            B -= 1;
        }
        while(A > 0){
            ans = ans + AA + BB;
            A -= 1;
        }
        return ans;
    }
    else{ // A > B, C and B >= C
        while(A > 0 && B > 0 && C > 0){
            //aab
            if(check(A, B, C)){
                if(A > 0) { ans += AA; A -= 1;}
            }
            if(check(A, B, C)){
                if(A > 0) { ans += AA; A -= 1;}
            }
            if(check(A, B, C)){
                if(B > 0) { ans += BB; B -= 1;}
            }
            //aac
            if(check(A, B, C)){
                if(A > 0) { ans += AA; A -= 1;}
            }
            if(check(A, B, C)){
                if(A > 0) { ans += AA; A -= 1;}
            }
            if(check(A, B, C)){
                if(B > 0) { ans += CC; C -= 1;}
            }

            //bba
            if(check(B, A, C)){
                if(B > 0) { ans += BB; B -= 1;}
            }
            if(check(B, A, C)){
                if(B > 0) { ans += BB; B -= 1;}
            }
            if(check(B, A, C)){
                if(A > 0) { ans += AA; A -= 1;}
            }
            //bbc
            if(check(B, A, C)){
                if(B > 0) { ans += BB; B -= 1;}
            }
            if(check(B, A, C)){
                if(B > 0) { ans += BB; B -= 1;}
            }
            if(check(B, A, C)){
                if(C > 0) { ans += CC; C -= 1;}
            }
            //cca
            if(check(C, A, B)){
                if(C > 0) { ans += CC; C -= 1;}
            }
            if(check(B, A, C)){
                if(C > 0) { ans += CC; C -= 1;}
            }
            if(check(B, A, C)){
                if(A > 0) { ans += AA; A -= 1;}
            }
            //ccb
            if(check(C, A, B)){
                if(C > 0) { ans += CC; C -= 1;}
            }
            if(check(B, A, C)){
                if(C > 0) { ans += CC; C -= 1;}
            }
            if(check(B, A, C)){
                if(B > 0) { ans += BB; B -= 1;}
            }

            if(A == B && B == C){
                ans = ans + AA + BB + CC;
                A -= 1; B -= 1; C -= 1;
            }
        }//end while

        int total_zero = zero_count(A, B, C);
        if(total_zero == 3) return ans;

        if(total_zero == 1){
            char last_character = '.';
            int len = ans.size();
            if(len > 0) last_character = ans[len - 1];
            /*
            if A = 0, tahole B, C er string baniye first e add kori, like ans = str + ans
            if B = 0, C/A or A/C
            if C = 0, B/A or A/B
            */
        }
        else{
            //easy
        }
    }
    return ans;
}




string generate_string_core(int A, int B, int C, char AA, char BB, char CC){
    string ans = "";
    while(A > 0){
        if(A > B && B != 0){
            if(A > 0) { ans += AA; A--;}
            if(A > 0) { ans += AA; A--;}
            if(B > 0) { ans += BB; B--;}
        }
        else if(A == B){
            if(A > 0) { ans += AA; A--;}
            if(B > 0) { ans += BB; B--;}
        }
        else if(A > C && C != 0){
            if(A > 0) { ans += AA; A--;}
            if(A > 0) { ans += AA; A--;}
            if(C > 0) { ans += CC; C--;}
        }
        else if(A == C){
            if(A > 0) { ans += AA; A--;}
            if(C > 0) { ans += CC; C--;}
        }
        if(B == 0 && C == 0 && A > 0){
            if(A > 0) { ans += AA; A--;}
            if(A > 0) { ans += AA; A--;}
        }
        if(B == 0 && C == 0) return ans;
        if(A == 0) break;
    }

    if(B == 0){
        if(C > 0) ans = CC + ans;
        C--;
        if(C > 0) ans = CC + ans;
        C--;
        if(C > 0) ans = ans + CC;
        C--;
        if(ans.size() >= 2 && ans[ans.size() - 2] != CC && C > 0) ans = ans + CC;
        return ans;
    }

    if(C == 0){
        if(B > 0) ans = BB + ans;
        B--;
        if(B > 0) ans = BB + ans;
        B--;
        if(B > 0) ans = ans + BB;
        B--;
        if(ans.size() >= 2 && ans[ans.size() - 2] != BB && B > 0) ans = ans + BB;
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
        if(C > 0) ans = ans + CC;
        C--;
        if(ans.size() >= 2 && ans[ans.size() - 2] != CC && C > 0) ans = ans + CC;
        return ans;
    }

    if(C == 0){
        if(B > 0) ans = BB + ans;
        B--;
        if(B > 0) ans = BB + ans;
        B--;
        if(B > 0) ans = ans + BB;
        B--;
        if(ans.size() >= 2 && ans[ans.size() - 2] != BB && B > 0) ans = ans + BB;
        return ans;
    }
    return ans;
}

string generate_string(int A, int B, int C){

    if(A <= 0 && B <= 0 && C <= 0) return "";

    if(A >= B && A >= C && B >= C) return generate_string_core2(A, B, C, 'a', 'b', 'c');
    else if(A >= B && A >= C && C >= B) return generate_string_core2(A, C, B, 'a', 'c', 'b');

    else if(B >= A && B >= C && A >= C) return generate_string_core2(B, A, C, 'b', 'a', 'c');
    else if(B >= A && B >= C && C >= A) return generate_string_core2(B, C, A, 'b', 'c', 'a');

    else if(C >= A && C >= B && A >= B) return generate_string_core2(C, A, B, 'c', 'a', 'b');
    else if(C >= A && C >= B && B >= A) return generate_string_core2(C, B, A, 'c', 'b', 'a');
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

    A = 5;
    B = 3;
    C = 3;

    int MIN = 1;
    int MAX = 100;

    string ans = generate_string(A, B, C);
    cout << ans << " " << ans.size() << " Valid = " << is_valid(ans)<< endl;
    bool output = false;
    if(output){
            freopen("C:\\Users\\MH9130\\Sadi\\AkhtarVai\\leet\\Codility\\output.csv", "w", stdout);
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
