class Solution {
public:
    void print(vector<int>& arr){
        for(int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        while(i < arr.size()){
            if(arr[i] == 0){
                //cout << "pre-i: " << i << endl;
                int temp;
                if(i + 1 < arr.size()) {
                    temp = arr[i + 1]; 
                    arr[i + 1] = 0;
                }
                int j = i + 2;
                
                while(j < arr.size()){
                    int temp2 = arr[j];
                    arr[j] = temp;
                    temp = temp2;
                    j++;
                }
            i += 2;
            //print(arr);
            //cout << "post-i: " << i << endl;
            }
        else i++;
        }//while-i
        
    }
};