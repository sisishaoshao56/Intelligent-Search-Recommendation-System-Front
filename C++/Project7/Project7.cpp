#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > s;
int a[10001],n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.push(a[i]);
	}
	for (; !s.empty();) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}