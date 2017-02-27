#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define LLMAX 1000000000000000010
#define MAX 100005
#define gcd __gcd
#define mod 1000000007
#define pb(n) push_back(n)
#define fr front()
#define vint vector<int>
#define vstring vector<string>
#define vll vector<long long int>
#define forp(i,a,n) for(int i=(a);i<(n);i++)
#define forn(i,a,n) for(int i=(a);i>=(n);i--)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)

int main()
{
    csl;
    int w,h;
    cout<<"Input width and length."<<endl;
    cin>>w>>h;
    cout<<"Input the number of bad roads"<<endl;
    int n,a,b,c,d;
    cin>>n;
    int bad[2][w+1][h+1];
    ll dp[w+1][h+1];
    forp(i,0,w+1)
    {
        forp(j,0,h+1)
        {
            bad[0][i][j]=bad[1][i][j]=dp[i][j]=0;
        }
    }
    cout<<"Input "<<n<<" bad road coordinates in format 'a b c d' without quotes."<<endl;
    forp(i,0,n)
    {
        cin>>a>>b>>c>>d;
        if(d>b)
            bad[1][c][d]=1;
        else if(c>a)
            bad[0][c][d]=1;
        else if(a>c)
            bad[0][a][b]=1;
        else
            bad[1][a][b]=1;

    }

    dp[0][0]=1;
    forp(i,1,w+1)
    {
        if(bad[0][i][0])
            dp[i][0]=0;
        else
            dp[i][0]=dp[i-1][0];
        if(bad[1][0][i])
            dp[0][i]=0;
        else
            dp[0][i]=dp[0][i-1];
    }
    forp(i,1,h+1)
    {
        forp(j,1,w+1)
        {
            if(!bad[0][j][i])
                dp[j][i]+=dp[j-1][i];
            if(!bad[1][j][i])
                dp[j][i]+=dp[j][i-1];
        }
    }
    cout<<"The number of ways to reach destination are : "<<dp[w][h]<<endl;
}


