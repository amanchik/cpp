#include <iostream>
using namespace std;
bool valid_output(string s){
    for(int i=0;i<s.length();i++)
        if(s[i]=='-')
            return false;
    return true;
}
string flip_string(string s){
    char replace = '+';
    if(s[0]=='+')
        replace = '-';
    int n = s.length();
    for(int i = 0;i<s.length()-1;i++)
        if(s[i]!=s[i+1])
        {
            n = i+1;
            break;
        }
        for(int i=0;i<n;i++)
            s[i]=replace;
    return s;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        string s;
        cin>>s;
        int count = 0;
        while(!valid_output(s)){
            s = flip_string(s);
            count++;
        }
        cout<<"Case #"<<t<<": "<<count<<endl;
    }
    return  1;
}