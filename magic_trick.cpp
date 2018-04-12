#include <iostream>
using namespace std;
struct Twin{
    int count;
    int ans;
};
Twin compare_arrays(int *a1, int *a2)
{
    Twin twin = {};
    int count = 0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a1[i]==a2[j])
            {
                count++;
                twin.ans = a1[i];
            }
            twin.count=count;

    return  twin;

}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int f1,f2;
        int a1[4][4],a2[4][4];
        cin>>f1;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                cin>>a1[i][j];
        cin>>f2;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                cin>>a2[i][j];
        Twin twin = compare_arrays(a1[f1-1],a2[f2-1]);
        if(twin.count==1){
            cout<<"Case #"<<t<<": "<<twin.ans<<endl;
        }
        else if(twin.count>0){
            cout<<"Case #"<<t<<": Bad magician!"<<endl;
        }else{
            cout<<"Case #"<<t<<": Volunteer cheated!"<<endl;
        }
    }
    return 0;
}
