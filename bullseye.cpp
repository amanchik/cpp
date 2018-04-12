
#include <iostream>
using namespace std;
long square_root(long n){
    long x = n;
    long y = (x + n/x)/2;
    while(y<x) {
        x = y;
        y = (x + n/x)/2;
    }
    return  x;
}
int main()
{
    int T;
    cin>>T;
    for (int c=1;c<=T;c++){
        long r,t;
        cin>>r>>t;
        long right = square_root(8*t+(2*r-1)*(2*r-1));

        cout<<"Case #"<<c<<": "<<(right+1-2*r)/4<<endl;
    }
    return 1;
}

