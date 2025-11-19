#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=999897; 
/*ll power(ll a,ll n){//递归快速幂 
	if(n==0){
		return 1;
	}
	if(n%2==1){
		return power(a,n-1)%mod*a%mod;
	}
	if(n%2==0){
		ll temp=power(a,n/2)%mod;
		return temp%mod*temp%mod;
	}
}*/
ll power(ll a,ll n){//非递归快速幂 
	ll ans=1;
	while(n){
		if(n&1){
			ans*=a;
		}
		a*=a;
		n>>1;
	} 
	return ans;
} 
int main(){
	ll a,n;
	cin>>a>>n;
	cout<<power(a,n);
	return 0;
} 
