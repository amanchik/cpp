#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        int c[n];
        int min = 10000000;
        int res=0;
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>c[i];
            if(c[i]<min)
                min=c[i];
            res = res ^ c[i];
            sum += c[i];
        }
        if(res==0){
            cout<<"Case #"<<t<<": "<<(sum-min)<<endl;
        }else{
            cout<<"Case #"<<t<<": NO"<<endl;
        }

    }
    return 1;
}
