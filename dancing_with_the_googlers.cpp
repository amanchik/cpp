#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n,s,p;
        cin>>n>>s>>p;
        int g[n];
        for(int i=0;i<n;i++)
            cin>>g[i];
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(g[i]%3==1&&((g[i]/3)+1)>=p)
                ans++;
            else if(g[i]%3==2&&((g[i]/3)+1)>=p)
                ans++;
            else if(g[i]%3==2&&((g[i]/3)+2)>=p&&s>0){
                ans++;
                s--;
            }else if(g[i]%3==0&&((g[i]/3))>=p)
                ans++;
            else if(g[i]%3==0&&((g[i]/3)+1)>=p&&s>0&&(g[i]/3)>0){
                ans++;
                s--;
            }
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}
