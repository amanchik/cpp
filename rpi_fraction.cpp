#include <iostream>
using namespace std;
long hcf(long a, long b) {
    if(a==0||b==0)
        return 1;
    if(a==b)
        return a;
    else if(a>b)
        return  hcf(a-b,b);
    else
        return hcf(b-a,a);
}
class Fraction
{
public:
    long num, den;
    Fraction(long n, long d) {
        long hc = hcf(n,d);

        num = n/hc; den = d/hc;
    }

    // conversion operator: return float value of fraction
    operator double () const {
        return double(num) / double(den);
    }

    Fraction operator + (Fraction const &c1)
    {
        long n = c1.num*this->den + c1.den*this->num;
        long d = c1.den*this->den;
        long hc = hcf(n,d);
        return Fraction(n/hc,d/hc);
    }

    Fraction operator += (Fraction const &c1)
    {

        return *this + c1;
    }

    Fraction operator * (long  c1)
    {
        long n = this->num*c1;
        long d = this->den;
        long hc = hcf(n,d);
        return Fraction(n/hc,d/hc);
    }
    Fraction operator * (int  c1)
    {
        long n = this->num*c1;
        long d = this->den;
        long hc = hcf(n,d);
        return Fraction(n/hc,d/hc);
    }

    Fraction operator / (Fraction const &c1)
    {
        long n = c1.den*this->num;
        long d = c1.num*this->den;
        long hc = hcf(n,d);
        return Fraction(n/hc,d/hc);
    }
    Fraction operator / (long c1)
    {
        long n = this->num;
        long d = c1*this->den;
        long hc = hcf(n,d);
        return Fraction(n/hc,d/hc);
    }
    Fraction operator / (int c1)
    {
        long n = this->num;
        long d = c1*this->den;
        long hc = hcf(n,d);
        return Fraction(n/hc,d/hc);
    }

};

ostream& operator<<(ostream& os, const Fraction& fr)
{
    os << fr.num << "/"<<fr.den<<endl;
    return os;
}
Fraction wp(string s[],int i){
    long ans = 0;
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.') {
            count++;
            if(s[i][j]=='1')
                ans += 1;
    }
    return Fraction(ans,count);
}
Fraction wpt(string s[],int i,int k){
    long ans = 0;
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.'&&j!=k) {
            count++;
            if(s[i][j]=='1')
                ans += 1;
        }
    return Fraction(ans,count);
}
Fraction owp(string s[],int i) {
    Fraction ans(0,1);
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.') {
        count ++;
        ans = ans + wpt(s,j,i);
    }

    return  ans/count;
}
Fraction oowp(string s[],int i) {
    Fraction ans(0,1);
    long count = 0;
    for(int j=0;j<s[i].length();j++)
        if(s[i][j]!='.') {
            count ++;
            ans = ans + owp(s,j);
        }
    return  ans/count;
}
int main()
{
    /*

    Fraction f1(0,2),f2(2,3);
    cout<<(f1+f2);
    cout<<(f1/f2);
    cout<<(f2/3);
    cout<<(f2*7);
*/


    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        cout.precision(20);
        cout<<"Case #"<<t<<": "<<endl;
        for(int i=0;i<n;i++){
            double rpi = (wp(s,i) + (owp(s,i) * 2)+ oowp(s,i))/4;
            cout<<rpi<<endl;
        }
    }

    return 1;
}
