#include<bits/stdc++.h>
using namespace std;
int n,a[100001],dp[100001],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=i+n-1;j++){
			dp[j]=max(dp[j-1]+a[j],a[j]);
		//	cout<<dp[j]<<endl;
			ans=max(dp[j],ans);
		}
		memset(dp,0,sizeof(dp) ); 
	}
	cout<<ans<<endl;
	return 0;
}
