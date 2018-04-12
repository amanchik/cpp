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

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int tr;
        cin>>tr;
        int na,nb;
        cin>>na>>nb;
        vector<int> a,b,c,d;
        for(int i=0;i<na+nb;i++){
            string aa,bb;
            cin>>aa>>bb;
            int first = stoi(aa.substr(0,2))*60+stoi(aa.substr(3,2));
            int second = stoi(bb.substr(0,2))*60+stoi(bb.substr(3,2));
            if(i<na){
                a.push_back(first);
                b.push_back(second+tr);
            }else{
                c.push_back(first);
                d.push_back(second+tr);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());

        int left = 0, right  = 0;

        for(int i=0;i<a.size();i++)
            if(d.size()==0||d[0]>a[i]){
                left++;
            }else if(d[0]<=a[i])
                d.erase(d.begin());

        for(int i=0;i<c.size();i++)
            if(b.size()==0||b[0]>c[i]){
                right++;
            }else if(b[0]<=c[i])
                b.erase(b.begin());

        cout<<"Case #"<<t<<": "<<left<<" "<<right<<endl;
    }
    return 1;
}

