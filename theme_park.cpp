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

       long sum = 0;
       bool not_over = true;
       vector<int> js;
       vector<long> sums;
       int num = 0;
       long total = 0;
       for(int i=0;i<n;i++)
           total += g[i];
       int period = 0;
       int start = 1;
       for(int i=0;i<2*n&&not_over;i++){
          for(int j=0;j<n;j++){
              sum += g[j];
              if(sum>k){

                  if(find(js.begin(), js.end(), j) != js.end()){
                      period = js.end()-find(js.begin(), js.end(), j);
                      start = find(js.begin(), js.end(), j) - js.begin();
                   //   js.push_back(j);
                     // sums.push_back(sum-g[j]);
                      //not_over = false;
                      //break;
                  }
                  js.push_back(j);
                  sums.push_back(sum-g[j]);
                  sum = g[j];
              }

          }
       }
       if(start==0)
       start=1;
       else{
           start++;
       }
       long repeat = 0;
       for(int i=start;i<start+period;i++)
           repeat += sums[i];
/*
      cout<<endl<<period<<endl<<start<<endl<<repeat;
       cout<<endl;
       print(js);
       print(sums);
       cout<<total<<endl;
*/
        if(total<=k){
            cout<<"Case #"<<t<<": "<<(total*r)<<endl;
       }else{
            long  ans=0;
            for(int i=0;i<start&&r>0;i++)
            {
                ans+= sums[i];
                r--;
            }
            ans += (r/period)*repeat;
            r = r%period;
            for(int i=start;i<start+r;i++)
                ans += sums[i];

            cout<<"Case #"<<t<<": "<<ans<<endl;

        }

    }
    return 1;
}

