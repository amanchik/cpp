#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    string s = "welcome to code jam";
    int T;
    cin>>T;
    string w;
    getline(cin,w);
    for (int t=1;t<=T;t++){
        getline(cin,w);
        int len = w.length();
        int counts[len][19];
        if(w[0]=='w')
            counts[0][0]=1;
        else
            counts[0][0]=0;
        for(int i=1;i<len;i++) {
            if (w[i] == s[0])
                counts[i][0] = counts[i - 1][0] + 1;
            else
                counts[i][0] = counts[i - 1][0];
        }
        for(int j=1;j<s.length();j++)
            counts[0][j]=0;
        for(int i=1;i<len;i++){
            for(int j=1;j<s.length();j++){
                if (w[i] == s[j])
                    counts[i][j] = (counts[i - 1][j] + counts[i - 1][j-1])%10000;
                else
                    counts[i][j] = counts[i - 1][j];
            }

        }
        /*
        for(int i=0;i<len;i++) {
            for (int j = 0; j < s.length(); j++) {
                cout<<counts[i][j]<<" ";
            }
            cout<<endl;
        }

*/
        cout<<"Case #"<<t<<": "<<setfill('0') << setw(4)<<counts[len-1][18]<<endl;
    }
    return 1;
}

