#include <iostream>
using namespace std;

double wp(string s[],int i){
    double ans = 0;
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.') {
            count++;
            if(s[i][j]=='1')
                ans += 1;
    }
    return ans/count;
}

double wpt(string s[],int i,int k){
    double ans = 0;
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.'&&j!=k) {
            count++;
            if(s[i][j]=='1')
                ans += 1;
        }
    return ans/count;
}

double owp(string s[],int i) {
    double ans = 0;
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.') {
        count ++;
        ans = ans + wpt(s,j,i);
    }

    return  ans/count;
}

double oowp(string s[],int i) {
    double ans = 0;
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.') {
            count ++;
            ans = ans + owp(s,j);
        }
    return  ans/count;
}
int main()
{
    /*

    Fraction f1(0,2),f2(2,3);
    cout<<(f1+f2);
    cout<<(f1/f2);
    cout<<(f2/3);
    cout<<(f2*7);
*/


    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        cout.precision(20);
        cout<<"Case #"<<t<<": "<<endl;
        for(int i=0;i<n;i++){
            double rpi = (wp(s,i) + (owp(s,i) * 2)+ oowp(s,i))/4;
            cout<<rpi<<endl;
        }
    }

    return 1;
}
