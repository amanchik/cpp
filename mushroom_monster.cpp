
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans1 = 0;
        int diff = 0;
        for(int i=1;i<n;i++)
            if(a[i]<a[i-1]){
                ans1 += (a[i-1]-a[i]);
                if(a[i-1]-a[i]>diff)
                    diff = a[i-1]-a[i];
        }

        int ans2 = 0;
        for(int i=0;i<n-1;i++)
            if(a[i]>diff){
               ans2 += diff;
            } else{
            ans2 += a[i];
        }

        cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;
    }
    return 1;
}

