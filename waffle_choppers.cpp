#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int r,c,h,v;
        cin>>r>>c>>h>>v;
        string s[r];
        for(int i=0;i<r;i++)
            cin>>s[i];
        int product = (h+1)*(v+1);
        int total = 0;
        int rows[r],cols[c];
        for(int i=0;i<r;i++)
            rows[i]=0;
        for(int i=0;i<c;i++)
            cols[i]=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(s[i][j]=='@'){
                    rows[i]++;
                    cols[j]++;
                    total++;
        }
        int ch[h],cv[v];
        for(int i=0;i<h;i++)
            ch[i]=0;
        for(int i=0;i<v;i++)
            cv[i]=0;
        if(total==0){
            cout<<"Case #"<<t<<": POSSIBLE"<<endl;
        }
        else if(total%product==0){
            int box = total/product;
            int prow = total/(h+1);
            int pcol = total/(v+1);
            bool  failed = false;
            int rem = prow;
            int current  = 0;
            for(int i=0;i<r;i++)
                if(rows[i]>rem) {
                failed = true;
                    break;
            }else if(rows[i]==rem){
                if(current<h) {
                    rem = prow;
                    ch[current] = i;
                    current++;
                }else{
                }
            }else{
                rem = rem - rows[i];
            }
            rem = pcol;
            current=0;
            for(int i=0;i<c;i++) {
                if (cols[i] > rem) {
                    failed = true;
                    break;
                } else if (cols[i] == rem) {
                    if(current<v) {
                        rem = pcol;
                        cv[current] = i;
                        current++;
                    }else{
                    }
                } else {
                    rem = rem - cols[i];
             //       cout<<"y "<<rem<<" "<<cols[i]<<endl;
                }
            }
            if(failed)
                    cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
            else {
              //  cout<<"first"<<endl;
                /*
                cout<<prow<<" "<<pcol<<endl;
                for(int i=0;i<r;i++)
                    cout<<rows[i]<<" ";
                cout<<endl;
                for(int i=0;i<c;i++)
                    cout<<cols[i]<<" ";
                cout<<endl;
                    for(int i=0;i<h;i++)
                        cout<<ch[i]<<" ";
                    cout<<endl;
                for(int i=0;i<v;i++)
                    cout<<cv[i]<<" ";
                cout<<endl;
                 */

                    int starti = 0;
                    int startj=0;
                    for(int i=0;i<h;i++) {
                        int endi = ch[i];
                        for (int j = 0; j < v; j++) {
                            int endj = cv[j];
                            int count = 0;
                       //     cout<<starti<<" "<<endi<<" "<<startj<<" "<<endj<<endl;
                            for (int m = starti; m <= endi; m++)
                                for (int n = startj; n <= endj; n++)
                                    if (s[m][n] == '@')
                                        count++;
                            if (count != box) {
                                failed = true;
                                break;
                            }
                            startj = endj+1;
                        }
                        if(failed)
                            break;
                        starti = ch[i]+1;
                        startj=0;
                    }
                if(failed)
                    cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
                    else
                    cout<<"Case #"<<t<<": POSSIBLE"<<endl;


            }


        }else{
            cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
        }

    }
    return 1;
}
