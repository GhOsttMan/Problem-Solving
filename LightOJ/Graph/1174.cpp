#include<bits/stdc++.h>
using namespace std;

int Level[105];
int Level2[105];
bool Mark[105];
vector<int>v[105];

void init(int N)
{
    for(int i=0; i < N-1 ; i++)
    {
        Mark[i]=false;
    }
}

void BFS(int S)
{
    Level[S]=0;
    queue<int>Q;
    Q.push(S);
    Mark[S]=true;

    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();

        for(int i=0;i<v[x].size();i++)
        {
            int a=v[x][i];

            if(Mark[a]==false)
            {
                Mark[a]=true;
                Level[a]=Level[x]+1;
                Q.push(a);
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);

    for(int i=1; i<=T ; i++)
    {
        int N,E;
        scanf("%d %d",&N,&E);

        for(int j=1; j <= E ;j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int s,e,Ans=-1;
        scanf("%d %d",&s,&e);
        memset(Mark,false,sizeof(Mark));
        BFS(s);
        for(int j=0 ; j < N; j++) Level2[j]=Level[j];
        memset(Mark,false,sizeof(Mark));
        BFS(e);

        for(int j=0; j< N ;j++)
        {
            Ans=max(Ans,Level[j]+Level2[j]);
        }
        printf("Case %d: %d\n",i,Ans);
        for(int j=0;j<N;j++) v[j].clear();
    }
}
