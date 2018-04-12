#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename Type>
void print(vector<Type> v){
    cout<<"[";
    for(int i=0;i<v.size();i++)
        i == v.size()-1  ? cout<<v[i] : cout<<v[i]<<", ";
    cout<<"]"<<endl;
}
bool  match(string s,vector<char> arr[]){
    for(int i=0;i<s.length();i++)
        if(find(arr[i].begin(), arr[i].end(), s[i]) == arr[i].end())
            return false;
    return true;
}
int main()
{
    int c,d,n;
    cin>>c>>d>>n;
    string s[d];
    for(int i=0;i<d;i++)
        cin>>s[i];
    for(int i=0;i<n;i++){
        vector<char> chars[c];
        string str;
        cin>>str;
        int current = 0;
        bool start_bracket = false;
        for(int j=0;j<str.length();j++){
            if(str[j]=='('){
                start_bracket = true;
            } else if(str[j]==')'){
                start_bracket = false;
                current++;
            } else if(start_bracket){
                chars[current].push_back(str[j]);
            }else{
                chars[current].push_back(str[j]);
                current++;
            }
        }
        int ans = 0;
        for(int j=0;j<d;j++){
            if(match(s[j],chars))
                ans++;
        }
        cout<<"Case #"<<(i+1)<<": "<<ans<<endl;

    }

    return 1;
}

