#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
       int d,n;
       cin>>d>>n;
       int p[n],m[n];
       for(int i=0;i<n;i++)
           cin>>p[i]>>m[i];
       vector<double> v;
       for(int i=0;i<n;i++)
           v.push_back(1.0*(d-p[i])/m[i]);
        sort(v.begin(),v.end(),greater<double>());
        cout.precision(10);
        cout<<"Case #"<<t<<": "<<(d/v[0])<<endl;
    }
    return 1;
}

