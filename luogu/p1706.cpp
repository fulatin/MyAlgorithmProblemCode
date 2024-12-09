#include <bits/stdc++.h>

using namespace std;


int n;
bool ok[10];
void solve(vector<int> q){
	if(q.size()==n){
		for(auto i:q){
			cout<<setw(5)<<i;
		}
		cout<<endl;
		return;
	}
	for(int i =1;i<=n;++i){
		if(!ok[i]){
			q.push_back(i);
			ok[i] =  true;
			solve(q);
			q.pop_back();
			ok[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	vector<int> q;
	solve(q);
	
}
