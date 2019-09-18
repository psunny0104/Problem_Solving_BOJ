//	@date 2019/09/19
//	@author psunny0104
//	@brief boj_1406_에디터

#include <iostream>
#include <stack>
#include <cstring>
#define MAX 600001
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	char order;
	char input[MAX] = { '\0' };
	cin >> input >> N;
	
	int input_size = strlen(input);
	stack<char> left, right;

	for (int i = 0; i < input_size; i++) {
		left.push(input[i]);
	}

	while (N--) {
		cin >> order;
		if (order == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (order == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (order == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (order == 'P') {
			cin >> order;
			left.push(order);
		}
	}

	int k = left.size();
	for (int i = 0; i < k; i++) {
		right.push(left.top());
		left.pop();
	}

	k = right.size();
	for (int i = 0; i < k; i++) {
		cout << right.top();
		right.pop();
	}

	return 0;
}