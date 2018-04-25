#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
      //  long a[n];
        vector<long> even;
        vector<long> odd;
        vector<long> v;
        vector<long> a;
        long tmp;
        for(int i=0;i<n;i++) {
            cin >> tmp;
            v.push_back(tmp);
            if(i%2==0)
                odd.push_back(tmp);
            else
                even.push_back(tmp);
        }
       // trouble_sort(a,n);
        sort(v.begin(),v.end());
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int oj =0 ,ej = 0;
        for(int i=0;i<n;i++)
            if(i%2==0) {
                a.push_back(odd[oj]);
                oj++;
            }
            else {
                a.push_back(even[ej]);
                ej++;
        }

        int ans = -1;
        for(int i=0;i<n;i++)
            if(a[i]!=v[i]) {
                ans = i;
                break;
            }
        if(ans==-1)
        cout<<"Case #"<<t<<": OK"<<endl;
        else
        cout<<"Case #"<<t<<": "<<ans<<endl;

    }
    return 0;
}
