#include<bits/stdc++.h>
using namespace std;

int Array[22][4];
int dp[22][4];
int N;

int recur(int i,int color)
{
    if(i==N) return 0;
    if(dp[i][color]!=-1) return dp[i][color];
    int Min1=INT_MAX;

    if(color==1)
    {
        Min1=min(Array[i+1][2]+recur(i+1,2),Array[i+1][3]+recur(i+1,3));        
    }
    else if(color==2)
    {
        Min1=min(Array[i+1][1]+recur(i+1,1),Array[i+1][3]+recur(i+1,3));        
    }
    else if(color==3)
    {
        Min1=min(Array[i+1][1]+recur(i+1,1),Array[i+1][2]+recur(i+1,2));       
    }

    return dp[i][color]=Min1;
}
int main()
{
    int T;

    scanf("%d",&T);

    for(int I=1;I<=T;I++)
    {
        scanf("%d",&N);

        memset(dp,-1,sizeof(dp));
        memset(Array,0,sizeof(Array));
        for(int i=0;i<N;i++)
        {
            for(int J=1;J<=3;J++)
            {
                scanf("%d",&Array[i][J]);
            }
        }
        int Ans=min(Array[0][1]+recur(0,1),min(Array[0][2]+recur(0,2),Array[0][3]+recur(0,3)));

        printf("Case %d: %d\n",I,Ans);
    }
}
