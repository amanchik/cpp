#include <iostream>
using namespace std;
int get_bit(long num,int i){
    return  (num>>i) & 1;
}

static long A,B,K;
static long counts[32][2][2][2];
long count_pairs(int i, int lessA,int lessB, int lessK){

    //cout<<A<<" "<<B<<" "<<K<<endl;

    //   cout<<"number of times called "<<endl;


   // cout<<"no zeros are "<<get_bit(A,i)<<endl;

    if(i==-1)
        return (lessA && lessB && lessK) ? 1:0;
    if(counts[i][lessA][lessB][lessK]>=0)
        return counts[i][lessA][lessB][lessK];
    int maxA = (lessA || (get_bit(A,i) == 1)) ? 1:0;
    int maxB = (lessB || (get_bit(B,i) == 1)) ? 1:0;
    int maxK = (lessK || (get_bit(K,i) == 1)) ? 1:0;
   // cout<<maxA<<" "<<maxB<<" "<<maxK<<endl;
    long count = count_pairs(i-1,maxA,maxB,maxK);
    if(maxA)
        count += count_pairs(i-1,lessA,maxB,maxK);
    if(maxB)
        count += count_pairs(i-1,maxA,lessB,maxK);
    if(maxA && maxB && maxK)
        count += count_pairs(i-1,lessA,lessB,lessK);
    counts[i][lessA][lessB][lessK] = count;
 //   cout<<i<<" "<<lessA<<" "<<lessB<<" "<<lessK<<endl;
    return  count;

}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int a,b,k;
        cin>>a>>b>>k;
        A=a;
        B=b;
        K=k;
        for(int i=0;i<32;i++){
            for(int j=0;j<2;j++){
                for(int l=0;l<2;l++){
                    for(int m=0;m<2;m++){
                        counts[i][j][l][m] = -245L;
                    }
                }
            }
        }

        cout<<"Case #"<<t<<": "<<count_pairs(31,0,0,0)<<endl;
/*
        for(int i=0;i<32;i++){
            for(int j=0;j<2;j++){
                for(int l=0;l<2;l++){
                    for(int m=0;m<2;m++){
                        cout<<counts[i][j][l][m]<<" ";
                    }
                }
            }
            cout<<endl;
        }
*/
    }


    return 1;
}

