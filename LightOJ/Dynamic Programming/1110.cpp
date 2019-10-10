#include<bits/stdc++.h>
using namespace std;
int N,La,Lb;
string a,b;

int dp[150][150];
string ANS[150][150];

string Min(string p , string q)
{
    //cout<<"Min "<<p<<" "<<q<<endl;
    if(p.size() < q.size()) return q;
    else if(p.size() > q.size()) return p;
    int k=p.size();

    for(int i=k-1;i>=0;i--)
    {

        if(p[i] < q[i]) return p;
        else if(q[i] < p[i])  return q;
    }
    return p;
}

void LCS(int p,int q)
{
    for(int i=p;i>=0;i--)
    {
        for(int j=q;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i+1][j+1];
                ANS[i][j]=ANS[i+1][j+1]+a[i];
            }
            else
            {
                //                      dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                if(dp[i][j+1] > dp[i+1][j])
                {
                    dp[i][j]=dp[i][j+1]; ANS[i][j]=ANS[i][j+1];
                }
                else if(dp[i][j+1] < dp[i+1][j])
                {
                    dp[i][j]=dp[i+1][j]; ANS[i][j]=ANS[i+1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j+1];
                  //  cout<<ANS[i][j+1]<<" "<<ANS[i+1][j]<<endl;
                    ANS[i][j]=Min(ANS[i][j+1],ANS[i+1][j]);
                  //  cout<<ANS[i][j]<<endl;
                }
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
       // cout<<T<<endl;
        for(int j=0;j<145;j++)
        {
            for(int k=0;k<145;k++)
            {
                dp[j][k]=0;
                ANS[j][k]="";
            }
        }
        cin>>a>>b;

        La=a.size(); Lb=b.size();

        LCS(La-1,Lb-1);

        printf("Case %d: ",i);

        if( dp[0][0] > 0 )
        {
            reverse(ANS[0][0].begin(),ANS[0][0].end());
            cout<<ANS[0][0]<<"\n";
        }
        else printf(":(\n");
    }

}

