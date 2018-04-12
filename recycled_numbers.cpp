#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int digits(int n){
    int count = 0;
    while (n>0){
        count++;
        n=n/10;
    }
    return count;
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
int count(int n,int a,int b){
    int num = digits(n);
    int ans = 0;
    vector<int> v;
    for(int i=1;i<num;i++){
        int tens = power(10,i);
        int other = power(10,num-i);
        int recycled = (n%tens)*other + (n/tens);
        if(recycled>n&&recycled<=b)
        if(!(find(v.begin(), v.end(), recycled) != v.end())) {
            v.push_back(recycled);
            ans++;
        }
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int a,b;
        cin>>a>>b;
        long ans = 0;
        for(int i = a;i<=b;i++)
            ans += count(i,a,b);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}
