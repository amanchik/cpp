#include <iostream>
using namespace std;
long hcf(long a, long b) {
  //  cout<<a<<" "<<b<<endl;
    if(a==0||b==0)
        return 1;
    if(a%b==0)
        return b;
    else if(b%a==0)
        return a;
    else if(a>b)
        return  hcf(a%b,b);
    else
        return hcf(b%a,a);
}
int power_of(long n){
    for(int i=1;i<=64;i++)
        if((1L<<i)==n)
            return i;
    return 0;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        string fr;
        cin>>fr;
        int index = fr.find('/');
        string ps = fr.substr(0, index);
        string qs = fr.substr(index+1, fr.length()-ps.length()-1);
        long p = stol(ps);
        long q = stol(qs);
        long h = hcf(p,q);
        p = p/h;
        q = q/h;
        int ans = power_of(q);
        //cout<<p<<" "<<q<<" "<<ans<<endl;
        if(ans) {
            ans = 1;
            while(2*p<q) {
                ans++;
                q = q/2;
              //  break;
            }
            cout<<"Case #"<<t<<": "<<ans<<endl;

        }
        else
            cout<<"Case #"<<t<<": impossible"<<endl;

    }
    return 1;
}
