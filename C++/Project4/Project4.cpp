#include <iostream>
#include <string>
using namespace std;
string st;
int a[260],n,k=0,l;
int main() {
	cin >> st;
	cin >> n;
	l = st.size();
	for (int i = 1; i <= l; i++) {
		a[i] = st[i - 1] - '0';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			if (a[j] > a[j + 1]) {
				for (int k = j; k <= l; k++) {
					a[k] = a[k + 1];
				}
				l--;
				break;
			}
		}
	}
	int i = 1;
	while (a[i] == 0 && k < l - 1) {
		k++;
		i++;
	}
//	cout << i << " " << k<<" "<<l << endl;
	for (int i = k + 1; i <= l; i++) {
		cout << a[i];
	}
	return 0;
}