
#include <iostream>
using namespace std;
int calc(int i,int j,int W,int H,int a[]){
    int n, w, s, e, c;
    n = i > 0 ? a[W*(i-1)+j] : 10000;
    w = j > 0 ? a[W*i+j-1] : 10000;
    s = i < H-1 ? a[W*(i+1)+j] : 10000;
    e = j < W-1 ? a[W*i+j+1] : 10000;
    c =  a[W*i+j];

    if(c<=n&&c<=w&&c<=s&&c<=e)
        return i*W+j;
    if(c>n&&n<=w&&n<=s&&n<=e)
        return calc(i-1,j,W,H,a);
    if(c>w&&w<n&&w<=s&&w<=e)
        return calc(i,j-1,W,H,a);
    if(c>e&&e<n&&e<w&&e<=s)
        return calc(i,j+1,W,H,a);
    if(c>s&&s<n&&s<w&&s<e)
        return calc(i+1,j,W,H,a);

    return 5;

}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int h,w;
        cin>>h>>w;

        int a[h*w];
        int parent[h*w];

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                cin>>a[i*w+j];
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                parent[i*w+j] = calc(i,j,w,h,a);
        }


        char c[h][w];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                c[i][j]='.';
        }
        char current = 'a';
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(c[i][j]=='.'){
                    c[i][j]=current;
                    for(int k=0;k<h*w;k++)
                        if(parent[k]==parent[i*w+j])
                            c[k/w][k%w]=current;
                    current++;
                }
            }
        }

        cout<<"Case #"<<t<<": "<<endl;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                cout<<c[i][j]<<" ";
            cout<<endl;
        }


       // cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}

