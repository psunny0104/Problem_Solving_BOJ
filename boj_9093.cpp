//	@date 2019/09/18
//	@author psunny0104
//	@brief boj_9093_단어 뒤집기

#include <iostream>
#include <stack>
#define MAX 1002
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	cin.get();
	while (N--) {
		char input[MAX] = { '\0', };
		cin.getline(input, MAX);
		stack<char> s;
		for (int i = 0; i < MAX; i++) {
			if (input[i] == ' ' || input[i] == '\0') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				if (input[i] == '\0') {
					input[i] = '\n';
					if (N > 0)
						cout << input[i];
					break;
				}
				cout << input[i];
			}
			else {
				s.push(input[i]);
			}
		}
	}

	return 0;
}