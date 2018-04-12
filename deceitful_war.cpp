#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
double find_right(vector<double> v, double current)
{
    for(int i=0;i<v.size();i++)
        if(v[i]>current)
            return  v[i];
    return v[0];
}
int find_left(vector<double> v, double current)
{
    for(int i=0;i<v.size();i++)
        if(v[i]>current)
            return  i;
    return -1;
}
int count_below(vector<double> v, double current){
    int count = 0;
    for(int i=0;i<v.size();i++)
        if(v[i]<current)
              count++;
    return  count;
}
template<typename Type>
void print(vector<Type> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        vector<double> naomi,ken,all_v;
        vector<int> counts,other;
        double k;
        for(int i = 0;i<n;i++)
        {
            cin>>k;
            naomi.push_back(k);
            all_v.push_back(k);
        }
        for(int i = 0;i<n;i++)
        {
            cin>>k;
            ken.push_back(k);
            all_v.push_back(k);
        }
        sort(naomi.begin(),naomi.end());
        sort(ken.begin(),ken.end());
        sort(all_v.begin(),all_v.end());
        for(int i=0;i<n;i++)
            counts.push_back(count_below(ken,naomi[i]));
        for(int i=0;i<n;i++)
            other.push_back(count_below(naomi,ken[i]));
      //  sort(ken.begin(),ken.end(),greater<double>());
     //   print(naomi);
       // print(ken);
        //print(all_v);
     //   print(other);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(counts[i]>ans){
                ans++;
            }
        }
        int second = 0;
        for(int i=0;i<n;i++){
            if(other[i]>second){
                second++;
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<" "<<(n-second)<<endl;
    }
    return 1;
}
