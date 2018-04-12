#include <iostream>
#include <bitset>
using namespace std;
long power(long x, long n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else
        return x*power(x,n-1);
}

long base(long n,int b)
{
    long ans = 0;
    int count = 0;
    while (n>0) {
        ans = ans + power(b,count)*(n%2);
        n = n/2;
        count++;
    }
    return ans;
}
string binary(long n){
    string ans = "";
    while (n>0) {
        ans += (n%2);
        n = n/2;
    }
    return ans;
}
long get_first_factor(long n)
{
    for(long x=2;x*x<=n;x++)
        if(n%x==0)
            return x;
    return  -1;
}
bool valid_number(long n){
    if(n%2==0)return false;
    int count = 0;
    int odd = 0;
    int even = 0;
    while (n>0){
        if(n%2==1){
            if(count%2==0)
                odd++;
            else
                even++;
        }
        count++;
        n=n/2;
    }
    return odd == even;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n,j;
        cin>>n>>j;
        long start = ((1L<<(n-1))+1);
        // cout<<start<<endl;
        cout<<"Case #"<<t<<": "<<endl;
        int count = 0;
        for(long i = start;i<=(1L<<n);i++)
        {
            if(!valid_number(i))
                continue;

                string binary = std::bitset<32>(i).to_string();
                cout<<binary;
                for(int j=0;j<9;j++)
                    cout<<" "<<(j+3);
                cout<<endl;
                count++;
                if(count==j)
                    break;

        }
    }
    return 1;
}
