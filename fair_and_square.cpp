#include <iostream>
#include <vector>
#include <algorithm>
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
bool  is_square(long n){
    long x = square_root(n);
    if(x*x==n)
        return true;
    else
        return false;
}
bool is_palindrome(long n){
    vector<int> x;
    while (n>0){
        x.push_back(n%10);
        n=n/10;
    }
    int len = x.size();
    for(int i=0;i<len;i++)
        if(x[i]!=x[len-i-1])
            return false;
    return true;

}

long power(long x, long n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else
        return x*power(x,n-1);
}
long flip(long n, bool copy){
    int count = 0;
    long other = 0;
    long duplicate = n;
    int digit = 0;
    if(!copy)
        duplicate = duplicate/10;
    while (duplicate>0){
        other =   other* 10 + (duplicate%10) ;
        count++;
        duplicate = duplicate/10;
    }


    return n* power(10,count) +other;

}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        long a,b;
        cin>>a>>b;
        int ans = 0;

        for(long n=1;n<=10000;n++) {
           long  first,second;
           first = flip(n, true);
           second = flip(n, false);
           first = first * first;
           second = second * second;
           if(is_palindrome(first)&&first>=a&&first<=b)
           {
               cout<<first<<endl;
               ans++;
           }
            if(is_palindrome(second)&&second>=a&&second<=b)
            {
               cout<<second<<endl;
                ans++;
            }

        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}