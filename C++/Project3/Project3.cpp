#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define int long long 
long long read() {
	long long ret = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-')f = -f; ch = getchar(); }
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}
struct note {
	int l, r, add;
	long long sum;
#define l(x) tree[x].l 
#define r(x) tree[x].r
#define add(x) tree[x].add
#define sum(x) tree[x].sum
}tree[800111];

void build(int x, int l, int r) {
	l(x) = l, r(x) = r, add(x) = 0;
	if (l == r) {
		sum(x) = read();
		return;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	sum(x) = sum(lson) + sum(rson);
}
void spread(int x) {
	sum(lson) += (r(lson) - l(lson) + 1) * add(x);
	sum(rson) += (r(rson) - l(rson) + 1) * add(x);
	add(lson) += add(x);
	add(rson) += add(x);
	add(x) = 0;
}
void change(int x, int l, int r, int k) {
	if (l <= l(x) && r(x) <= r) {
		sum(x) += (r(x) - l(x) + 1) * k;
		add(x) += k;
		return;
	}
	spread(x);
	int mid = (l(x) + r(x)) / 2;
	if (l <= mid) {
		change(lson, l, r, k);
	}
	if (r > mid) {
		change(rson, l, r, k);
	}
	sum(x) = sum(lson) + sum(rson);
}
int query(int x, int l, int r) {
	if (l <= l(x) && r(x) <= r) {
		return sum(x);
	}
	spread(x);
	int mid = (l(x) + r(x)) / 2;
	int ans = 0;
	if (l <= mid) {
		ans += query(lson, l, r);
	}
	if (r > mid) {
		ans += query(rson, l, r);
	}
	return ans;
}
int n, m;
signed main() {
	//ios::sync_with_stdio(false);
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
}
