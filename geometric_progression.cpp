double ar,arr;
cin>>ar>>arr;
int n;cin>>n;
double r = arr/ar;
double a = ar/r;
string str = to_string(a*pow(r,n-1));
//cout<<str<<"\n";
int len = 0;
for(;len<str.size();len++)
	if(str[len]=='.')
		break;
char res[len+2+3];
for(int i = 0 ; i < len+3+1;i++){
	res[i] = str[i];
}
res[len+3+1] = '\0';
cout<<res<<"\n";