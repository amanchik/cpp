#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n,k;
        cin>>n>>k;
        int jk = (1<<n)-1;
        string ans= "OFF";
        if(k%(jk+1)==jk)
            ans = "ON";
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}