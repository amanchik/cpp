#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        string s;
        cin>>s;
        vector<char> ans;
        for(int i=0;i<s.length();i++)
            if(i==0)
                ans.push_back(s[i]);
            else if(s[i]>=ans[0])
                ans.insert(ans.begin(),s[i]);
            else
                ans.push_back(s[i]);

        cout<<"Case #"<<t<<": ";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 1;
}