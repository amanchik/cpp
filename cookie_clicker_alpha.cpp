#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        double c,f,x;
        cin>>c>>f>>x;
        double p = 2;
        double ans = 0;
        while (x*f>c*(p+f)){
            ans += c/p;
            p += f;
        }
        ans += x/p;
        cout.precision(20);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}
