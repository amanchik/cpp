#include <iostream>
using namespace std;
string root(string s){
    string ans = "";
    for(int i=0;i<s.length();i++)
        if(i==0)
            ans += s[i];
        else if(s[i-1]!=s[i])
            ans += s[i];
    return ans;
}
int  distance(string s){
    int ans = 0;
    for(int i=1;i<s.length();i++)
        if(s[i-1]==s[i])
            ans++;
    return ans;
}
int mod(int a,int b)
{
    return a>b?a-b:b-a;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        string roots[n];
        for(int i=0;i<n;i++)
            roots[i] = root(s[i]);
        bool possible = true;
        for(int i=1;i<n;i++)
            if(roots[i]!=roots[0])
                possible = false;
       if(possible){
           int len = roots[0].length();
           int counts[n][len];
           int sums[n][len];
           int avg[len];
           for(int i=0;i<n;i++)
               for(int j=0;j<len;j++)
                   counts[i][j]=1;
           for(int i=0;i<n;i++){
               int current = 0;
               for(int j=1;j<s[i].length();j++){
                   if(s[i][j]==s[i][j-1]){
                       counts[i][current]++;
                   }
                   else{
                       current++;
                   }
               }
           }


           for(int i=0;i<len;i++){
               int sum = 0;
               for(int j=0;j<n;j++)
                   sum += counts[j][i];
               avg[i] = sum/n;
           }
           int nearest[len];
           for(int i=0;i<len;i++){
               int min = 200;
               for(int j=0;j<n;j++){
                 int mo = mod(counts[j][i],avg[i]);
                 if(mo<min){
                     min = mo;
                     nearest[i] = counts[j][i];
                 }
               }
           }
           /*
           for(int i=0;i<n&&(cout<<endl);i++)
               for (int j = 0; j < len; j++)
                   cout << counts[i][j] << " ";
            cout<<endl;
           for(int i=0;i<len;i++)
               cout<<avg[i]<<" ";
           cout<<endl;
            */

           int min = 0;
           for(int i=0;i<len;i++){
               int temp = 20000;
               for(int j=0;j<n;j++){
                   int sum = 0;
                   for(int k=0;k<n;k++)
                   sum += mod(counts[j][i],counts[k][i]);
                   if(sum<temp)
                       temp = sum;
               }
               min += temp;
           }





           cout<<"Case #"<<t<<": "<<min<<endl;

       }else{
           cout<<"Case #"<<t<<": Fegla Won"<<endl;
       }

    }
    return 1;
}

