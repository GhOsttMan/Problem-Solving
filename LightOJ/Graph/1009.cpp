#include<bits/stdc++.h>

using namespace std;
#define Max 20005
int Team1,Team2;

void BFS(int Source,vector<int>List[Max],int Mark[Max])
{
    queue<int>Q;
    Q.push(Source);
    Mark[Source]=1;
    Team1++;


    while(!Q.empty())
    {

        int N=Q.front();
        Q.pop();

        for(int I=0;I<List[N].size();I++)
        {
            if(Mark[N]==1)
            {
                if(Mark[List[N][I]]==0)
               {
                    Mark[List[N][I]]=2;
                    Team2++;

                    Q.push(List[N][I]);
               }
            }
            else  if(Mark[N]==2)
            {
                 if(Mark[List[N][I]]==0)
               {
                    Mark[List[N][I]]=1;
                    Team1++;

                    Q.push(List[N][I]);
               }
            }
        }
    }
}
int main()
{
    int Node,Edge,X,Y,T;

    scanf("%d",&T);

    for(int Test=1;Test<=T;Test++)
    {

        int Mx=0;
        int Max1=0;
        scanf("%d",&Edge);
        vector<int>List[Max];
        int Mark[Max];
        memset(Mark,-1,sizeof(Mark));
        for(int I=1;I<=Edge;I++)
        {

            scanf("%d %d",&X,&Y);
            List[X].push_back(Y);
            List[Y].push_back(X);
            Mark[X]=0;
            Mark[Y]=0;
            Mx=max(Mx,max(X,Y));
        }
        for(int I=1;I<=Mx;I++)
        {
            Team1=Team2=0;
            if(Mark[I]==0)
            {
               // cout<<I<<endl;
                BFS(I,List,Mark);
            }
            Max1+=max(Team1,Team2);
        }

        printf("Case %d: %d\n",Test,Max1);
    }
    return 0;
}

