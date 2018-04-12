#include <iostream>
using namespace std;
int main()
{
    string s[6];
    s[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
    s[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    s[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
    s[3]="our language is impossible to understand";
    s[4]="there are twenty six factorial possibilities";
    s[5]="so it is okay if you want to just give up";
    string mapping="abcdefghijklmnopqrstuvxyz";
    mapping['z'-'a']='q';
    mapping['q'-'a']='z';

    for(int i=0;i<3;i++)
        for(int j=0;j<s[i].length();j++)
            if(s[i][j]!=' ')
            mapping[s[i][j]-'a']=s[i+3][j];

    int T;
    cin>>T;
    string str;
    getline(cin,str);

    for (int t=1;t<=T;t++){

        getline(cin,str);
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<str.length();i++)
            if(str[i]==' ')
                cout<<' ';
            else
            cout<<mapping[str[i]-'a'];

        cout<<endl;
    }
    return 1;
}