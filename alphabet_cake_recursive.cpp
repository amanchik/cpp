#include <iostream>
#include <vector>
using namespace std;
bool  is_empty_row(string s){
    for(int i=0;i<s.length();i++)
        if(s[i]!='?')
            return false;
    return true;
}

bool is_filled(string s){
    for(int i=0;i<s.length();i++)
        if(s[i]=='?')
            return false;
    return true;
}
int depth = 0;

bool has_only_one(string s[],int x,int y,int r,int c)
{
    int count = 0;
    for(int i=x;i<r+x;i++)
        for(int j=y;j<c+y;j++)
            if(s[i][j]!='?')
                count++;
    return count == 1;
}
char get_only_one(string s[],int x,int y,int r,int c)
{
    int count = 0;
    for(int i=x;i<r+x;i++)
        for(int j=y;j<c+y;j++)
            if(s[i][j]!='?')
                return s[i][j];
    return '0';
}
bool has_no_one(string s[],int x,int y,int r,int c)
{
    int count = 0;
    for(int i=x;i<r+x;i++)
        for(int j=y;j<c+y;j++)
            if(s[i][j]!='?')
                count++;
    return count == 0;
}
template<typename Type>
void print(vector<Type> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
vector<int> v;
void divide_and_conquer(string s[],int x,int y,int r,int c){
    depth++;
   // if(depth>20){
     //   return;
    //}
    if(has_only_one(s,x,y,r,c)) {
        v.push_back(x);
        v.push_back(y);
        v.push_back(r);
        v.push_back(c);
       // cout<<x<<" "<<y<<" "<<r<<" "<<c<<endl;
        return;
    }
    bool not_found = true;
    for(int i=x;(i<r+x)&&not_found;i++)
        for(int j=y;j<c+y;j++)
            if(s[i][j]!='?'){
                if(j==c+y-1){
                  //  cout<<"horizontal"<<endl;
                    //cout<<(i-x+1)<<" "<<c<<" "<<(r-i+x-1)<<endl;
                    if(i-x+1>0)
                    divide_and_conquer(s,x,y,i-x+1,c);
                    if(r-i+x-1>0)
                    divide_and_conquer(s,i+1,y,r-i+x-1,c);

                }
                else if(i==x+r-1){
                  //  cout<<"vertical"<<endl;
                    //cout<<(j-y+1)<<" "<<r<<" "<<(c-j+y-1)<<endl;
                    if(j-y+1>0)
                    divide_and_conquer(s,x,y,r,j-y+1);
                    if(c-j+y-1>0)
                    divide_and_conquer(s,x,j+1,r,c-j+y-1);

                }
                else{
                    if(has_no_one(s,x,j+1,r,c-j+y-1)){
                      //  cout<<"horizontal"<<endl;
                        //    cout<<(i-x+1)<<" "<<c<<" "<<(r-i+x-1)<<endl;
                        if(i-x+1>0)
                            divide_and_conquer(s,x,y,i-x+1,c);
                        if(r-i+x-1>0)
                            divide_and_conquer(s,i+1,y,r-i+x-1,c);
                    }else{
                       // cout<<"vertical"<<endl;
                        //cout<<(j-y+1)<<" "<<r<<" "<<(c-j+y-1)<<endl;
                        if(j-y+1>0)
                            divide_and_conquer(s,x,y,r,j-y+1);
                        if(c-j+y-1>0)
                            divide_and_conquer(s,x,j+1,r,c-j+y-1);
                    }

                }
                not_found = false;
                break;
            }
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int r,c;
        cin>>r>>c;
        string s[r];
        for(int i=0;i<r;i++)
            cin>>s[i];
        v.clear();
        divide_and_conquer(s,0,0,r,c);
        while(v.size()>0){
            char ch = get_only_one(s,v[0],v[1],v[2],v[3]);
            for(int i=v[0];i<v[0]+v[2];i++)
                for(int j=v[1];j<v[1]+v[3];j++)
                    s[i][j]=ch;
            v.erase(v.begin());
            v.erase(v.begin());
            v.erase(v.begin());
            v.erase(v.begin());
        }
        cout<<"Case #"<<t<<": "<<endl;
        for(int i=0;i<r;i++)
            cout<<s[i]<<endl;
    }
    return 1;
}

