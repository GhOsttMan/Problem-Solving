#include<bits/stdc++.h>
using namespace std;

#define MAX 10005
bool Mark[MAX];
bool Vis[MAX];
int Level[MAX];

vector<int>prime;

void seive()
{
    memset(Mark,false,sizeof(Mark));
    for(int i=4; i <= MAX ;i+=2) Mark[i]=true;

    for(int i=3; i * i <= MAX ; i++)
    {
        for(int j=i+i; j <= MAX ;j+=i)
        {
            Mark[j]=true;
        }
    }
    Mark[1]=true;

    for(int i=1; i<= MAX ;i++)
    {
        if(Mark[i]==false) prime.push_back(i);
    }
   // for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";
}

int main()
{
    int T;
    scanf("%d",&T);
    seive();

    for(int i=1 ; i <= T ;i++)
    {
        int N,M;
        memset(Vis,false,sizeof(Vis));

        scanf("%d %d",&N,&M);

        queue<int>Q;

        Q.push(N);
        Level[N]=0;
        Vis[N]=true;

        while(!Q.empty())
        {
            int v=Q.front();
            Q.pop();
          //  cout<<v<<" "<<Level[v]<<endl;
            for(int k=2 ; k < v ; k++)
            {
                if(Mark[k]==false && v%k==0 && Vis[v+k]==false)
                {
                  //  cout<<v<<" "<<k<<endl;
                    Level[v+k]=Level[v]+1;
                    Vis[v+k]=true;
                    Q.push(v+k);
                }
            }
            if(Vis[M]==true || v > M+1000) break;
        }
        printf("Case %d: ",i);

        if(Vis[M]==false) printf("-1\n");
        else printf("%d\n",Level[M]);
    }
}
