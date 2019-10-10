#include<bits/stdc++.h>
using namespace std;

vector<int>v[1003];
bool Mark[1003];
int Count[1003];

void BFS(int S)
{
    Mark[S]=true;
    Count[S]++;
    queue<int>Q;
    Q.push(S);

    while(!Q.empty())
    {
        int a=Q.front();
        Q.pop();

        for(int i=0;i<v[a].size();i++)
        {
            int x=v[a][i];
            if(Mark[x]==false)
            {
                Mark[x]=true;
                Q.push(x);
                Count[x]++;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {
        memset(Count,0,sizeof(Count));
        int K,N,E,Ans=0;
        scanf("%d %d %d",&K,&N,&E);
        vector<int>S;
        for(int j=0;j<K;j++)
        {
            int x;
            scanf("%d",&x);
            S.push_back(x);
        }
        for(int j=1;j<=E;j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        for(int j=0;j<S.size();j++)
        {
            memset(Mark,false,sizeof(Mark));
            BFS(S[j]);
        }
        for(int j=1;j<=N;j++)
        {
            if(Count[j]==K) Ans++;
            v[j].clear();
        }
        printf("Case %d: %d\n",i,Ans);
    }
}
