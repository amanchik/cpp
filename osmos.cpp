#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename Type>
void print(vector<Type> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int process(vector<int> v,int i, long current,int ans) {
    //cout<<i<<" "<<current<<" "<<ans<<endl;
    if(i==v.size()){
        return ans;
    }
    if(current>v[i]) {
        return process(v,i+1,current+v[i],ans);
    }else{
        int add = process(v,i,2*current-1,ans+1);
        int del = ans + v.size()-i;
        return del < add ? del : add;
    }
}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int a,n;
        cin>>a>>n;
        vector<int> v;
        int x;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        //print(v);
        if(a==1){
            cout<<"Case #"<<t<<": "<<v.size()<<endl;
        }else {
            cout<<"Case #"<<t<<": "<<process(v,0,a,0)<<endl;
        }
    }
    return 1;
}
