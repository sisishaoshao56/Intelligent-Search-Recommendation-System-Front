#include <bits/stdc++.h>
using namespace std;
string find (const string &s1,const string &s2){
	int begin=0;
	int ml=0;
	int len1=s1.size();
	int len2=s2.size();
	vector<vector<int> > count(len1+1,vector<int>(len2+1)) ;
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i-1]==s2[j-1]){
				count[i][j]=count[i-1][j-1]+1;
			}
			if(count[i][j]>ml){
				ml=count[i][j];
				begin=i-ml;
			}
		}
	}
	return s1.substr(begin,ml);
	
}
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		if(s2.size()<s1.size()){
			cout<<find(s2,s1)<<endl;
		}
		cout<<find(s1,s2);
	}
	return 0;
} 
