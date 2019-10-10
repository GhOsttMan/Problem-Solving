#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int,int> Pair;
char Grid[15][15];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int Level[200][200];
bool Mark[105][105];
int N;

bool BFS(int x,int y,char E)
{
    queue<Pair>Q;
    Q.push(make_pair(x,y));
    Level[x][y]=0;
    Mark[x][y]=true;

    while(!Q.empty())
    {
        Pair l=Q.front();
        Q.pop();
      //  cout<<Grid[l.f][l.s]<<" "<<E<<endl;
        if(Grid[l.f][l.s]==E)
        {
            return true;
        }
        for(int i=0; i < 4 ; i++)
        {
            int L=l.f+dx[i];
            int R=l.s+dy[i];
          //  cout<<Grid[L][R]<<" "<<Grid[l.f][l.s]<<" "<<Mark[L][R]<<" "<<Mark[l.f][l.s]<<endl;
            if( L >= 1 && L <= N && R >= 1 && R <= N && Grid[L][R]!='#' && (Grid[L][R]=='.' || Grid[L][R] <=E )&& Mark[L][R]==false)
            {
               // cout<<Grid[L][R]<<" "<<Grid[l.f][l.s]<<" "<<Mark[L][R]<<" "<<Mark[l.f][l.s]<<endl;
                Level[L][R]=Level[l.f][l.s]+1;
                Q.push(make_pair(L,R));
                Mark[L][R]=true;
            }
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {
        scanf("%d",&N);
        vector< pair< char, pair< int ,int > > > v;

        for(int I=1;I<=N;I++)
        {
            for(int J=1;J<=N;J++)
            {
                cin>>Grid[I][J];
                if(Grid[I][J] >= 'A' && Grid[I][J] <= 'Z') v.push_back(make_pair(Grid[I][J],make_pair(I,J)));
            }
        }
        sort(v.begin(),v.end());
        int M=0,Ans=0;
        for(int j=0;j<v.size()-1;j++)
        {
            char a=v[j+1].f;
            int x=v[j].s.f;
            int y=v[j].s.s;
            int xx=v[j+1].s.f;
            int yy=v[j+1].s.s;
         //   cout<<a<<" "<<v[j].f<<" "<<v[j+1].f<<" "<<j<<endl;
            memset(Mark,false,sizeof(Mark));
            bool t=BFS(x,y,a);
        //  cout<<t<<endl;
            if(t==false) M=1;
            else Ans+=Level[xx][yy];
        }
        printf("Case %d: ",i);

        if(M==1) printf("Impossible\n");
        else printf("%d\n",Ans);
    }
}
