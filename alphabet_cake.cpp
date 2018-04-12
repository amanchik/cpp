#include <iostream>
using namespace std;
bool  is_empty_row(string s){
    for(int i=0;i<s.length();i++)
        if(s[i]!='?')
            return false;
    return true;
}
bool is_filled(string s){
    for(int i=0;i<s.length();i++)
        if(s[i]=='?')
            return false;
    return true;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int r,c;
        cin>>r>>c;
        string s[r];
        for(int i=0;i<r;i++)
            cin>>s[i];
        for(int i=0;i<r;i++){
            if(!is_empty_row(s[i])) {
                while(!is_filled(s[i])) {
                    int start = -1;
                    char ch;
                    for (int j = 0; j < c; j++) {
                        if (s[i][j] != '?') {
                            start = j;
                            ch = s[i][j];
                            break;
                        }
                    }
                    if (start != -1) {
                        for (int j = 0; j < start; j++)
                            s[i][j] = ch;
                    }
                    start = -1;
                    for (int j = 0; j < c; j++) {
                        if (s[i][j] == '?') {
                            start = j;
                            ch = s[i][j-1];
                            break;
                        }
                    }
                    if(start!=-1){
                        for (int j = start; j < c; j++)
                           if(s[i][j]=='?'){
                            s[i][j]=ch;
                        }else{
                               break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<r;i++){
            if(is_empty_row(s[i])){
             for(int j=0;j<c;j++)
                 s[i][j]=s[i-1][j];
            }
        }
        for(int i=r-2;i>=0;i--){
            if(is_empty_row(s[i])){
                for(int j=0;j<c;j++)
                    s[i][j]=s[i+1][j];
            }
        }
            cout<<"Case #"<<t<<": "<<endl;
        for(int i=0;i<r;i++)
            cout<<s[i]<<endl;
    }
    return 1;
}

