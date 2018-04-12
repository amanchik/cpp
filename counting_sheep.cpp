#include <iostream>
#include <vector>
using namespace std;
bool is_full(int array[]){
    for(int i=0;i<10;i++)
        if(array[i]==0)
            return false;
    return true;
}
vector<int> list_digits(int n){
    vector<int> dts;
    while(n>0) {
        dts.push_back(n%10);
        n = n/10;
    }
    return  dts;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n;
        cin>>n;
        int add = n;
        int digits[] = {0,0,0,0,0,0,0,0,0,0};
        bool found = false;
        for(int i=1;i<=1126;i++){
            vector<int> all = list_digits(n);
            for(int j=0;j<all.size();j++)
                digits[all[j]]=1;
            if(is_full(digits)){
                cout<<"Case #"<<t<<": "<<n<<endl;
                found = true;
                break;
            }
            n += add;
        }
        if(!found)
        cout<<"Case #"<<t<<": "<<"INSOMNIA"<<endl;

    }
    return  0;
}

