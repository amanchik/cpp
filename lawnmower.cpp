#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        string ans = "YES";
        bool not_over = true;
        for(int i=0;i<n&&not_over;i++)
            for(int j=0;j<m;j++)
            {
                int row=0,col=0;
                for(int k=0;k<m;k++)
                    if(a[i][k]>a[i][j])
                        row=1;
                for(int k=0;k<n;k++)
                    if(a[k][j]>a[i][j])
                        col=1;
                if(row==1&&col==1){
                    ans="NO";
                    not_over = false;
                    break;
                }

            }


        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}