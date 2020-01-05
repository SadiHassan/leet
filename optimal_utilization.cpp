/*Given 2 lists a and b. Each element is a pair of integers where the first integer represents the unique id and the second integer represents a value. Your task is to find an element from a and an element form b such that the sum of their values is less or equal to target and as close to target as possible. Return a list of ids of selected elements. If no pair is possible, return an empty list.*/
bool sort_func(vector<int> first, vector<int> second){
    return first[1]<second[1];
}
vector<vector<int>> ClosestSum( vector<vector<int>> a,vector<vector<int>> b, int target)
{
    sort(a.begin(),a.end(),sort_func);
    sort(b.begin(),b.end(),sort_func);
    int i=0;
    int j=b.size()-1;
    int prev_diff=INT_MAX;
    vector<vector<int>> output;
    while(i<a.size() && j>=0){
        int sum= a[i][1]+b[j][1];
        if (sum>target){
            j--;continue;}
        else{
            int diff= target-sum;
            if (diff<prev_diff){ prev_diff= diff;
                output.clear();}
            int begin=j;
            while(begin>=0 && a[i][1]+b[begin][1]==sum){
                vector<int> temp;
                temp.push_back(a[i][0]);temp.push_back(b[begin][0]);
                output.push_back(temp);
                begin--;
                }  
            }
        i++;
    }
    return output;
}

void print_vector(vector<vector<int>> output){
    cout<<"[";
    for(int i=0;i<output.size();i++){
        cout<<"["<<output[i][0]<<","<<output[i][1]<<"]";
    }
    cout<<"]"<<endl;
}
void tc1()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(2);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(4);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(6);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(2);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 7);
    print_vector(output);
}
void tc2()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(3);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(5);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(7);test1.push_back(temp);
    temp.clear();temp.push_back(4);temp.push_back(10);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(2);test2.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(3);test2.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(4);test2.push_back(temp);
    temp.clear();temp.push_back(4);temp.push_back(5);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 10);
    print_vector(output);
}
void tc3()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(8);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(7);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(14);test1.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(10);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(5);test2.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(10);test2.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(14);test2.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(5);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 20);
    print_vector(output);
}
void tc4()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(8);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(15);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(9);test1.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(10);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(8);test2.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(11);test2.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(12);test2.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(5);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 20);
    print_vector(output);
}
int main() {
    std::cout << "Hello World!\n";
    tc1();
    tc2();
    tc3();
    tc4();
}
