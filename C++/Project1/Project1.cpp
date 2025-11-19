/*栈（Stack）：是只允许在一端进行插入或删除的线性表。
top:允许进入和删除的一端
bottom:不允许进入和删除的一端
空栈：不含任何元素的空表
特性：先进后出
基本操作：
1.push()：入栈，在栈顶添加一个元素，没有返回值
2.pop() ：出栈，将栈顶元素删除，没有返回值
3.top() ：获得栈顶元素。
4.size(): 获得栈大小，返回值为unsigned int 类型
5.empty():判断栈是否为空，返回值是bool；空为true

队列（Queue）：是只允许在一端进行插入操作，而在另一端进行删除操作的线性表
入队添加到队尾，出队是从队首出
特性：先进先出
1.push() : 入队。队尾添加一个元素，没有返回值
2.pop()  : 出队。队列头部元素删除，没有返回值
3.front(): 获得头部元素。返回值为队列头部元素
4.size() : 获得队列大小，同stack
5.empty(): 同stack
6.back (): 返回队列尾部元素
*/
//P1165
/*#include <iostream>
#include <stack>
using namespace std;
int  main() {
	stack<int> s;
	stack<int> p;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			int b;
			cin >> b;
			if (p.empty()) {
				p.push(b);
			}
			if (b > p.top()) {
				p.push(b);
			}
			s.push(b);
		}
		if (a == 1) {
			if (s.top() == p.top()) {
				p.pop();
			}
			s.pop();
		}
		if (a == 2) {
			if (p.empty()) {
				cout << 0 << endl;
			}
			else cout << p.top() << endl;
		}
	}
	return 0;
}*/
/*#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int x, y;
	bool operator > (const node& a) const
	{
		if (this->x > a.x) {
			return true;
		}
		else return false;
	}
}k;
priority_queue <node,vector<node>,greater<node> > q;
int main()
{
	k.x = 10, k.y = 100; q.push(k);
	k.x = 12, k.y = 60; q.push(k);
	k.x = 14, k.y = 40; q.push(k);
	k.x = 6, k.y = 80; q.push(k);
	k.x = 8, k.y = 20; q.push(k);
	while (!q.empty())
	{
		node m = q.top(); q.pop();
		printf("(%d,%d) ", m.x, m.y);
	}
}*/
#/*include <iostream>
#include <queue>
using namespace std;
struct node {
	int num, id;
};
priority_queue<node, vector<node>, greater<node> > s;
int main() {
	int n,k;
	node e;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		e.num = x;
		e.id = i;
		s.push(e);
		if (i == 1) {
			cout << "0" << endl;
		}
	}
	for (; !s.empty();) {
	}
	return 0;
}*/
#include <iostream>
#include <queue>
using namespace std;
struct node {
	int num, id;
	bool operator > (const node& a) const {
		if (this->num > a.num) {
			return true;
		}
		else return false;
	}
};
priority_queue<node, vector<node>, greater<node> > s;
priority_queue<node, vector<node>, less<node> > p;
int a[1000010];
int main() {
	int n, k;
	node e;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i <= k) {
			e.id = i;
			e.num = a[i];
			s.push(e);
			continue;
		}
		for (; !s.empty() && s.top().id < i - k;) {
			s.pop();
		}
		cout << s.top().num << " ";
		e.id = i;
		e.num = a[i];
		s.push(e);
		if (i == n) {
			cout << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i <= k) {
			e.id = i;
			e.num = a[i];
			p.push(e);
			continue;
		}
		for (; !p.empty() && p.top().id < i - k;) {
			p.pop();
		}
		cout << p.top().num << " ";
		e.id = i;
		e.num = a[i];
		p.push(e);
		if (i == n) {
			cout << endl;
		}
	}
	return 0;
}
