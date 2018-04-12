#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int a,b,k;
        cin>>a>>b>>k;
        int ans = 0;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                if((i&j)<k)
                    ans++;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}

