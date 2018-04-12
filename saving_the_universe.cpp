#include <iostream>
#include <map>
using namespace std;
bool filled(map<string,bool> mapping,string search[],int n){
    for(int i=0;i<n;i++)
        if(!mapping[search[i]])
            return false;
    return true;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int s,q;
        cin>>s;
        string search[s];
        string str;
        getline(cin,str);
        map<string,int> mapping;
        for(int i=0;i<s;i++)
        {
            getline(cin,str);
            mapping[str]=i;
            search[i]=str;
        }
        cin>>q;
        getline(cin,str);
        int ans = 0;
        map<string,bool> what;
        for(int j=0;j<s;j++)
            what[search[j]]= false;
        for(int i=0;i<q;i++){
            getline(cin,str);
            what[str]=true;
            if(filled(what,search,s))
            {
                for(int j=0;j<s;j++)
                    what[search[j]]= false;
                what[str]= true;
                ans++;
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}

