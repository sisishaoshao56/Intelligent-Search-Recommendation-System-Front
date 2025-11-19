#include <iostream>
using namespace std;
void demo() {
	static int t = 1;
	cout << t << endl;
	t++;
}
int main() {
	for (int i = 1; i <= 5; i++) {
		demo();
	}
	int t = 1;
	return 0;
}