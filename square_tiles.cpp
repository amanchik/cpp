#include <iostream>
using namespace std;
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
        bool not_over = true;
        for(int i=0;i<r&&not_over;i++){
            for(int j=0;j<c;j++){
                if(s[i][j]=='#') {
                    if(j+1<c&&s[i][j+1]=='#'&&i+1<r&&s[i+1][j=='#']&&s[i+1][j+1]=='#'){
                        s[i][j]='/';
                        s[i][j+1]='\\';
                        s[i+1][j]='\\';
                        s[i+1][j+1]='/';
                    }else{
                        not_over = false;
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": "<<endl;
        if(not_over) {
            for(int i=0;i<r;i++)
                cout<<s[i]<<endl;
        }else{
            cout<<"Impossible"<<endl;
        }
    }
    return 1;
}
