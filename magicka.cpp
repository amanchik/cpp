#include <iostream>
#include <vector>
using namespace std;
template<typename Type>
void print(vector<Type> v){
    cout<<"[";
    for(int i=0;i<v.size();i++)
      i == v.size()-1  ? cout<<v[i] : cout<<v[i]<<", ";
    cout<<"]"<<endl;
}
bool can_destroy(vector<char> list,int dd[][26],char c){
    for(int i=0;i<list.size();i++)
        if(dd[c-'A'][list[i]-'A']>0||dd[list[i]-'A'][c-'A']>0)
            return true;
    return false;

}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int c,d,n;
        int cc[26][26];
        int dd[26][26];
        for(int i=0;i<26;i++) {
            for (int j = 0; j < 26; j++) {
                cc[i][j] = -1;
                dd[i][j] = -1;
            }
        }
        cin>>c;
        for(int i=0;i<c;i++){
            string s;
            cin>>s;
            cc[s[0]-'A'][s[1]-'A']=s[2]-'A';
        }
        cin>>d;
        for(int i=0;i<d;i++){
            string s;
            cin>>s;
            dd[s[0]-'A'][s[1]-'A']=1;
        }
        cin>>n;
        string s;
        cin>>s;
        vector<char> list;
        for(int i=0;i<n;i++)
        {
            if(list.size()==0)
                list.push_back(s[i]);
            else if(cc[s[i]-'A'][list[list.size()-1]-'A']>-1){
                char c = cc[s[i]-'A'][list[list.size()-1]-'A'] + 'A';
                list.pop_back();
                list.push_back(c);
            }
            else if(cc[list[list.size()-1]-'A'][s[i]-'A']>-1){
                char c = cc[list[list.size()-1]-'A'][s[i]-'A'] + 'A';
                list.pop_back();
                list.push_back(c);
            }
            else if(can_destroy(list,dd,s[i])){
                list.clear();
            }else{
                list.push_back(s[i]);
            }
        }
        cout<<"Case #"<<t<<": ";
        print(list);

    }
    return 1;
}

