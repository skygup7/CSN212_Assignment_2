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

int bins(int dp[],int r,int k)      ///Binary Search for finding the position of the element
{
	int mid,l=-1;
	while(r-l>1)
	{
		mid=(l+r)/2;
		if(dp[mid]>=k)
		{
			r=mid;
		}
		else
			l=mid;
	}
	return r;
}

int lisop(int a[],int n)            ///The lisop function for finding the length of lis in N*log(N)
{
	int dp[n];
	int nd=1;
	dp[0]=a[0];

	for(int i=1;i<(n);i++)
	{
		if(a[i]<dp[0])
		{
			dp[0]=a[i];
		}
		else if(a[i]>dp[nd-1])
		{
			dp[nd]=a[i];
			nd++;
		}
		else
		{
			dp[bins(dp,nd-1,a[i])]=a[i];
		}
	}

	return nd;
}

int main()                  ///Solution accepted at "https://www.codechef.com/status/D2,skyguptaiit"
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n+5];
		forp(i,0,n){
			cin>>a[i];
			a[i+n]=a[i];    ///Appending the same array for circular like motion
		}
		int maxi=0;
		forp(i,0,n)         ///For each element in array, find the length of longest increasing subsequence.
            maxi=max(maxi,lisop(a+i,n));
        cout<<maxi<<endl;
	}
}
