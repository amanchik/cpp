#include <iostream>
using namespace std;
long damage(string s){
    long ans = 0,strength=1;
    for(int i=0;i<s.length();i++)
        if(s[i]=='C')
            strength=strength*2;
        else
            ans += strength;
    return ans;
}
int shuffle_index(string s){
    for(int i=s.length()-1;i>0;i--)
        if(s[i]=='S'&&s[i-1]=='C')
            return i-1;
    return -1;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        long d;
        string p;
        cin>>d>>p;
        long ans = 0;
        bool possible = true;
        while (damage(p)>d){
            int i = shuffle_index(p);
            if(i==-1) {
                possible = false;
                break;
            }
            p[i]='S';
            p[i+1]='C';
            ans++;
        }
        if(possible)
            cout<<"Case #"<<t<<": "<<ans<<endl;
        else
            cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;

    }
    return 1;
}

