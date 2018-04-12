#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename Type>
void print(vector<Type> v){
    cout<<"[";
    for(int i=0;i<v.size();i++)
        i == v.size()-1  ? cout<<v[i] : cout<<v[i]<<", ";
    cout<<"]"<<endl;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
       int r,k,n;
       cin>>r>>k>>n;
       int g[n];
       for(int i=0;i<n;i++)
           cin>>g[i];
       int total = 0;
       for(int i=0;i<n;i++)
           total += g[i];
       if(total<=k){
           cout<<"Case #"<<t<<": "<<(total*r)<<endl;
       }else{
           long ans = 0;
           int current = 0;
           long sum = 0;
           while (r>0) {
               sum += g[current%n];
               if(sum>k){
                //   cout<<sum<<endl;
                   sum = sum - g[current%n];
                   ans += sum;
                   sum = g[current%n];
                   r--;
               }
               current++;
           }
           cout<<"Case #"<<t<<": "<<ans<<endl;
       }


    }
    return 1;
}

