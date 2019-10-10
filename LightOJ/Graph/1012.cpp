#include<bits/stdc++.h>
using namespace std;
 
int DR[]={1,-1,0,0,1};
int DC[]={0,0,1,-1};
char Grid[22][22];
int Row,Cul;
 
int Walk(int R,int C,char C1,char C2)
{
    //cout<<R<<" "<<C<<" "<<Cul<<" "<<Row<<endl;
    if(R<0||R>=Row||C<0||C>=Cul)
        return 0;
    if(Grid[R][C]!=C1)
        return 0;
    int Ans=1;
 
    Grid[R][C]=C2;
    for(int I=0;I<4;I++)
    {
        Ans+=Walk(R+DR[I],C+DC[I],C1,C2);
    }
    return Ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++)
    {
        int X,Y;
       // cin>>Cul>>Row;
       scanf("%d %d",&Cul,&Row);
        memset(Grid,'A',sizeof(Grid));
        for(int I=0;I<Row;I++)
        {
            for(int J=0;J<Cul;J++)
            {
                cin>>Grid[I][J];
                //scanf("%c",&Grid[I][J]);
                if(Grid[I][J]=='@')
                {
                    Grid[I][J]='.';
                    X=I;Y=J;
                }
               // cout<<I<<" "<<J<<endl;
            }
        }
       // cout<<X<<" "<<Y<<endl;
      // cout<<FloodFill(X,Y,'.','#')<<endl;
 
      printf("Case %d: %d\n",I,Walk(X,Y,'.','#'));
 
       /* for(int I=0;I<Row;I++)
        {
            for(int J=0;J<Cul;J++)
            {
                cout<<Grid[I][J];
            }
            cout<<endl;
        }*/
    }
    return 0;
}
