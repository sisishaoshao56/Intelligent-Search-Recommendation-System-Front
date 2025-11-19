#include <bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define ll long long 
#define int long long 
long long read() {
	long long ret = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-')f = -f; ch = getchar(); }
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}
struct note {
	ll l, r, add, sum;

}tree[800068];
void build(int x,int l,int r) {
	tree[x].l = l;
	tree[x].r = r;
	tree[x].add = 0;
	if (l == r) {
		tree[x].sum = read();
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	tree[x].sum = tree[lson].sum + tree[rson].sum;
}
void spread(int x) {
	tree[lson].sum += (tree[lson].r - tree[lson].l + 1) * tree[x].add;
	tree[rson].sum += (tree[rson].r - tree[rson].l + 1) * tree[x].add;
	tree[lson].add += tree[x].add;
	tree[rson].add += tree[x].add;
	tree[x].add = 0;
}
void change(int x, int l, int r, int k) {
	if (l <= tree[x].l && tree[x].r <= r) {
		tree[x].sum += (tree[x].r - tree[x].l + 1) * k;
		tree[x].add += k;
		return ;
	}
	spread(x);
	int mid = (tree[x].l + tree[x].r) / 2;
	if (l <= mid) {
		change(lson, l, r, k);
	}
	if (r > mid) {
		change(rson, l, r, k);
	}
	tree[x].sum = tree[lson].sum + tree[rson].sum;
}
int query(int x, int l, int r) {
	if (l <= tree[x].l && tree[x].r <= r) {
		return tree[x].sum;
	}
	spread(x);
	int mid = (tree[x].l + tree[x].r) / 2;
	int ans = 0;
	if (l <= mid) {
		ans += query(lson, l, r);
	}
	if (r > mid) {
		ans += query(rson, l, r);
	}
	return ans;
}
int n,m;
signed  main() {
	n = read(); m = read();
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int op;
		op = read();
		if (op == 1) {
			int x, y, z;
			x = read(); y = read(); z = read();
			change(1, x, y, z);
		}
		else {
			int x, y;
			x = read(); y = read();
			int o = query(1, x, y);
			cout << o << endl;
		}
	}
	return 0; 
}
