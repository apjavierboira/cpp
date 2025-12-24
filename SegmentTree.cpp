#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
const int inf = 1e9;
 
struct SegTree{
	vector<int> seg;
	vector<int> lazy;
	int n;
 
	void build(vector<int> v){
		n = 1;
		int n1 = v.size();
		while(n < n1) n*=2;
		// 1 2 4 8 16 32 .. .. . 
		// 1 2 4 8
		seg.resize(2*n, inf);
		lazy.resize(2*n, 0);
		for(int i = 0; i<v.size(); i++){
			seg[i+n] = v[i];
		}
		for(int i = n-1; i>0; i--){
			seg[i] = min(seg[2*i], seg[2*i+1]);
		}
	}
	void pushDown(int k){
		if(k<n){
			lazy[2*k] += lazy[k];
			lazy[2*k+1] += lazy[k];
		}
		seg[k] += lazy[k];
		lazy[k] = 0;
	}
 
	int query(int k, int ql, int qr, int l, int r){
		if(r < ql || l > qr) return inf;
		if(ql <= l && r <= qr) return seg[k]+lazy[k];
		int mid = (l+r)/2;
		if(lazy[k] != 0) pushDown(k);
		// l, mid | mid+1, r
		int respIzq = query(2*k,ql,qr,l,mid);
		int respDer = query(2*k+1, ql,qr,mid+1,r);
		return min(respIzq, respDer);
 
	}
	int query(int ql, int qr){
		return query(1, ql, qr, 0, n-1);
	}
 
	void update(int k, int v, int ql, int qr, int l, int r){
		if(r < ql || l > qr) return;
		if(ql <= l && r <= qr){
			lazy[k]+=v;
			return;
		}
		int mid = (l+r)/2;
		//if(lazy[k] != 0) pushDown(k);
		// l, mid | mid+1, r
		update(2*k,v,ql,qr,l,mid);
		update(2*k+1,v,ql,qr,mid+1,r);
		seg[k] = min(seg[2*k], seg[2*k+1]);
	}
	void update(int ql, int qr, int v){
		update(1,v,ql,qr,0,n-1);
	}
	void pointUpdate(int idx, int val){
		idx+=n;
		seg[idx] = val;
		idx/=2; 
		while(idx > 0){
			seg[idx] = max(seg[2*idx], seg[2*idx+1]);
			idx/=2;
		}
	}
};
 
// <= x;
// 1 3 6 8
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin>>n>>q;
	vector<int> v(n);
	for(int i = 0; i<n; i++) v[i] = i+1;
	for(int& i : v) cin>>i;
	//iota(v.begin(),v.end(),1);
	SegTree seg;
	seg.build(v);
	while(q--){
		int t; cin>>t;
		if(t== 1){
			int l,r; cin>>l>>r; l--; r--; int u; cin>>u;
			seg.update(l,r,u);
		}
		else{
			int l,r; cin>>l; l--;
			cout<<seg.query(l,l)<<"\n";
		}
	}
}