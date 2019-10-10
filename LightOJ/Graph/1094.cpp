#include<bits/stdc++.h>
using namespace std;

bool mark[30004];
typedef pair<int,int> Pr;
vector<Pr> V[30004];
int dis[30004];
int MaxRoot,Max;

void init(int N)
{
    for(int i=0;i<=N;i++)
    {
        mark[i]=false;
        dis[i]=INT_MIN;
    }
}

void ListCr(int N)
{
    for(int i=0;i<=N;i++)
    {
        V[i].clear();
    }
}

void BFS(int root)
{
    mark[root]=true;
    dis[root]=0;
    queue<int>Q;
    Q.push(root);
    Max=INT_MIN;
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();

        for(int i=0;i<V[x].size();i++)
        {
            int v=V[x][i].second;
            int val=V[x][i].first;

            if(mark[v]==false)
            {
                dis[v]=dis[x]+val;
                if(dis[v] > Max)
                {
                    Max=dis[v];
                    MaxRoot=v;
                }
                mark[v]=true;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int T,i=1;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);

        for(int I=1;I<N;I++)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);

            V[x].push_back(make_pair(w,y));
            V[y].push_back(make_pair(w,x));
        }
        int root=0;
        init(N);
        BFS(root);
        init(N);
        BFS(MaxRoot);

        printf("Case %d: %d\n",i++,Max);
        ListCr(N);
    }
}
