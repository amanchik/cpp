#include <iostream>
using namespace std;
int diff(int a,int b)
{
    return a>b?a-b:b-a;
}
void print_array(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        string s;
        int p;
        int ans[n];
        int o=1,b=1;
        int ot=0,bt=0;
        int prev = 0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            cin>>p;
            if(s=="O"){
                ans[i] = ot +diff(o,p) + 1;
                o = p;
                if(i>0&&ans[i-1]>=ans[i]){
                    ans[i] = ans[i-1]+1;
                }
                ot = ans[i];
            }else{
                ans[i] = bt + diff(b,p) + 1;
                if(i>0&&ans[i-1]>=ans[i]){
                    ans[i] = ans[i-1]+1;
                }
                bt = ans[i];
                b=p;
            }

        }
      //  print_array(ans,n);
        cout<<"Case #"<<t<<": "<<ans[n-1]<<endl;
    }
    return 1;
}
