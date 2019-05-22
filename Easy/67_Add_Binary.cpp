/*
BETTER SOLUTION
string addBinary(string a, string b) {
        int alen=a.size(), blen=b.size();
        int ia=alen-1, ib=blen-1;
        int out=0;
        string s="";
        while(ia>=0||ib>=0) {
            out += ia>=0? (a[ia--]-'0'):0;
            out += ib>=0? (b[ib--]-'0'):0;
            s = to_string(out%2) + s;
            out/=2;
        }
        if (out==1) s = to_string(out) + s;
        return s;
    }

*/

class Solution {
public:
    
    string sum(char a, char b, char carry){
        if(carry == '0'){
            if(a == '1' && b == '1') return "01"; // first character = sum; second character = carry
            if(a == '0' && b == '0') return "00";
            return "10";
        }
        if(carry == '1'){
            if(a == '1' && b == '1') return "11";
            if(a == '0' && b == '0') return "10";
            return "01";
        }
        
        return "";
    }
    
    string addBinary(string a, string b) {
        int len1 = a.size() - 1;
        int len2 = b.size() - 1;
        string ans = "";
        char carry = '0';
        
        while((len1 >= 0) || (len2 >= 0)){
            
            char ch1 = '0';
            char ch2 = '0';
                
            if(len1 >= 0) ch1 = a[len1];
            if(len2 >= 0) ch2 = b[len2];
            
            string temp = sum(ch1, ch2, carry);
            //cout << ch1 << " " << ch2 << " " << temp << endl;
            ans = ans + temp[0];
            carry = temp[1];
            len1--; 
            len2--;
        }
        if(carry == '1') ans += carry;
        string ans_rev = "";
        for(int i = ans.size()-1; i >= 0; i--) ans_rev += ans[i];
        
        return ans_rev;
    }
};