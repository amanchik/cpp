#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
string con(int n) {
    string s="";
    for(int i=0;i<n;i++)
        s+='0';
    return s;
}
void find_substrings(string s,int i,string look_for) {
    if (s.find(look_for,i) == std::string::npos) {
        return;
    }else {
        cout<<i<<endl;
     find_substrings(s,s.find(look_for,i)+1,look_for);
    }
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        string s;
        cin>>s>>n;
        long ans = 0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                s[i]='1';
            else
                s[i]='0';
            bool start = false;
            int count = 0;
            int zen = 0;
            int start_i = 0;
            long not_possible = 0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0'&&s[i]!='0'){
                start = true;
                count++;
            }else if(s[i]=='0') {
                count++;
            }else{
                if(count>=n){
                    long len = (i-count+n-1-start_i);
                    not_possible = (len * (len+1))/2;
                    start_i = i - (n-1);
                    cout<<i<<" "<<count<<endl;
                }
                start = false;
                count = 0;
            }
        }
    }
    return 1;
}
