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
    int t;
    cout<<"Input the number of Test Cases"<<endl;
    cin>>t;
    while(t--)                                  ///A loop for each test case.
    {
        int n;
        cout<<"Input the number of elements in the array."<<endl;
        cin>>n;
        int ar[n];
        cout<<"input the elements."<<endl;
        forp(i,0,n)                             ///Input of array
            cin>>ar[i];
        int dp[2][n+1];
        dp[0][0]=dp[1][0]=1;
        forp(i,1,n)
        {
            dp[0][i]=dp[1][i]=0;                ///dp[0][i] stores longest Zigzag array with i th element increasing.
            forp(j,0,i)                         ///dp[1][i] stores longest Zigzag array with i th element decreasing.
            {
                if(ar[j]<ar[i])
                    dp[0][i]=max(dp[0][i],1+dp[1][j]);
                else if(ar[j]>ar[i])
                    dp[1][i]=max(dp[1][i],1+dp[0][j]);
                else
                    {dp[1][i]=dp[1][i-1];dp[0][i]=dp[0][i-1];}
            }
        }
        cout<<"The maximum length of the zigzag array present in the given array is : "<<max(dp[0][n-1],dp[1][n-1])<<endl;
    }
}


