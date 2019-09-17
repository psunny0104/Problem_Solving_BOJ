#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

struct STACK {
	int stack[MAX];
	int stk_size;
	STACK() {
		stk_size = 0;
	}

	void push(int num)
	{
		stack[stk_size++] = num;
	}

	int pop()
	{
		if (stk_size == 0)
			return -1;
		else {
			//pop되는 배열의 초기화 X
			stk_size -= 1;
			return stack[stk_size];
		}
	}

	int size()
	{
		return stk_size;
	}

	bool empty()
	{
		if (stk_size == 0)
			return true;
		else
			return false;
	}

	int top()
	{
		if (stk_size == 0)
			return -1;
		else
			return stack[stk_size - 1];
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	string order;
	STACK s;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push") {
			int input_num;
			cin >> input_num;
			s.push(input_num);
		}
		else if (order == "pop")
			cout << s.pop() << "\n";
		else if (order == "size")
			cout << s.size() << "\n";
		else if (order == "empty")
			cout << s.empty() << "\n";
		else if (order == "top")
			cout << s.top() << "\n";
	}

	return 0;
}