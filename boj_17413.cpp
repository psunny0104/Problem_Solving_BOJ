//	@date 2019/09/19
//	@author psunny0104
//	@brief boj_17413_단어 뒤집기 2

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	getline(cin,input);
	input += '\n';

	int num = 0;
	stack<char> s;

	while (true) {
		if (num == input.size())
			break;
		if (input[num] == '<') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			while (input[num] != '>') {
				cout << input[num];
				num++;
			}
			cout << input[num];
		}
		else if (input[num] == ' ' || input[num] == '\n') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			if(input[num] == ' ')
				cout << ' ';
		}
		else
			s.push(input[num]);

		num++;
	}

	return 0;
}