//deque  双端队列
/*#include<iostream>
#include<queue>
using namespace std;
int n, m;
struct E {
	int num;
	int id;
};
deque<E> q;
int main() {
	cin >> n >> m;
	E e;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		e.num = x; e.id = i;
		if (i == 1) {//第一个特别输出 
			q.push_back(e);
			printf("0\n");
			continue;
		}
		//对于本题，需要弹出队头在前m个数字之外的数弹出
		while (!q.empty() && q.front().id <= i - m - 1) {
			q.pop_front();
		}
		//输出在前m个中最小的数字
		printf("%d\n", q.front().num);
		//维护单调队列,如果x大于等于队尾元素，直接插入，如果小于队尾元素，则需要弹出对微元素 
		while (!q.empty() && q.back().num >= x) {
			q.pop_back();
		}
		q.push_back(e);
	}
	return 0;
}*/
//vector 用法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> a({ 0,1,-2,3 });
	auto b = distance(a.begin(), min_element(a.begin(), a.end()));
	cout << b << endl;
	return 0;
}