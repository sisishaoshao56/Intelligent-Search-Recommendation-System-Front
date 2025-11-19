#include<bits/stdc++.h> 
struct student {
	//string name;
	int age;
	int score;
};
void Print(struct student& s) {
	s.age = 0;
	s.score = -9;
}
using namespace std;
int main() {
	student s;
	s.age = 100;
	s.score = 0;
	cout << s.age << " " << s.score << endl;
	Print(s);
	cout << s.age << " " << s.score << endl;
	return 0;
}
