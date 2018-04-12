#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
template<typename Type>
void print(vector<Type> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i<v.size()-1)
            cout<<" ";
    }

    cout<<endl;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        map<int,int> m;
        vector<int> v;
        int tmp;
        for(int i=0;i<2*n*n-n;i++) {
            cin>>tmp;
            if(m.count(tmp)) {
                m[tmp] = m[tmp] + 1;
            }else{
                m[tmp] = 1;
                v.push_back(tmp);
            }
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++)
            if(m[v[i]]%2==1)
                ans.push_back(v[i]);
        sort(ans.begin(),ans.end());
        cout<<"Case #"<<t<<": ";
        print(ans);

    }
    return 1;
}
