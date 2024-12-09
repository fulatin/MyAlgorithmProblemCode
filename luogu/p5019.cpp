#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=(int)10e5;

int n;
int arr[MAXN+3],st[6*(MAXN+3)];
set<int> pos[6*(MAXN+3)];
int ans;
int currlevel = 0;
int lt(int p){return p<<1;}
int rt(int p){return (p<<1)+1;}

void bt(int p,int l,int r){
	if(l==r){
		st[p] = arr[l];
		pos[p].insert(l);
		return;
	}
	
	int mid = (l+r)>>1;
	
	bt(lt(p),l,mid);
	bt(rt(p),mid+1,r);
	for(int i:pos[lt(p)]){
		for(int j:pos[rt(p)]){
			if(arr[i]==arr[j]){
				pos[p].insert(pos[rt(p)].begin(),pos[rt(p)].end());
				pos[p].insert(pos[lt(p)].begin(),pos[lt(p)].end());
				return;
			}else if(arr[i]<arr[j]){
				pos[p].insert(pos[lt(p)].begin(),pos[lt(p)].end());
			}else{
				pos[p].insert(pos[rt(p)].begin(),pos[rt(p)].end());
			}
		}
	}
}



set<int> findminval(int p,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		return  pos[p];
	}
	
	int mid = (l+r)>>1;
	set<int> val1,val2;
	if(mid>=tl) val1 = findminval(lt(p),l,mid,tl,tr);
	if(mid<tr) val2 = findminval(rt(p),mid+1,r,tl,tr);
	set<int> rtset;
	for(int i:val1){
		for(int j:val2){
			if(arr[i]==arr[j]){
				rtset.insert(val1.begin(),val1.end());
				rtset.insert(val2.begin(),val2.end());
			}else if(arr[i]<arr[j]){
				rtset.insert(val1.begin(),val1.end());
			}else{
				rtset.insert(val2.begin(),val2.end());
			}
		}
	}
	return rtset;
	
}

void solve(int l,int r){
	if(l>r){
		return;
	}	
	set<int> detect = findminval(1,1,n,l,r);
	vector<int> a;
	for(auto e:detect){
		a.push_back(e);
	}
	sort(a.begin(),a.end());
	int rep = arr[a[0]];
	ans += rep-currlevel;
	int tmp = rep;
	rep = currlevel;
	int left = l;
	for(int right:a){
		solve(left,right-1);
		left = right+1;
	}
	solve(left,r);
	rep = tmp;
}
