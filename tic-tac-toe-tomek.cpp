#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        string s[4];
        for(int i=0;i<4;i++)
            cin>>s[i];
        int dots = 0;
        bool over = false;
        string ans = "Draw";
        for(int i=0;i<4;i++)
        {
            int Ts,Os,Xs;
            Ts=Os=Xs=0;
            for(int j=0;j<4;j++)
            {
                if(s[i][j]=='T')
                    Ts++;
                else if(s[i][j]=='O')
                    Os++;
                else if(s[i][j]=='X')
                    Xs++;
                else
                    dots++;
            }
            if((Ts==1&&Os==3)||Os==4)
            {
                ans="O won";
                over = true;
            }
            if((Ts==1&&Xs==3)||Xs==4)
            {
                ans="X won";
                over = true;
            }
        }
        for(int i=0;i<4;i++)
        {
            int Ts,Os,Xs;
            Ts=Os=Xs=0;
            for(int j=0;j<4;j++)
            {
                if(s[j][i]=='T')
                    Ts++;
                else if(s[j][i]=='O')
                    Os++;
                else if(s[j][i]=='X')
                    Xs++;
            }
            if((Ts==1&&Os==3)||Os==4)
            {
                ans="O won";
                over = true;
            }
            if((Ts==1&&Xs==3)||Xs==4)
            {
                ans="X won";
                over = true;
            }
        }
        int Ts,Os,Xs;
        Ts=Os=Xs=0;
        for(int j=0;j<4;j++)
        {
            if(s[j][j]=='T')
                Ts++;
            else if(s[j][j]=='O')
                Os++;
            else if(s[j][j]=='X')
                Xs++;
        }
        if((Ts==1&&Os==3)||Os==4)
        {
            ans="O won";
            over = true;
        }
        if((Ts==1&&Xs==3)||Xs==4)
        {
            ans="X won";
            over = true;
        }
        Ts=Os=Xs=0;
        for(int j=0;j<4;j++)
        {
            if(s[3-j][j]=='T')
                Ts++;
            else if(s[3-j][j]=='O')
                Os++;
            else if(s[3-j][j]=='X')
                Xs++;
        }
        if((Ts==1&&Os==3)||Os==4)
        {
            ans="O won";
            over = true;
        }
        if((Ts==1&&Xs==3)||Xs==4)
        {
            ans="X won";
            over = true;
        }
        if(!over&&dots>0){
            ans = "Game has not completed";
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 1;
}