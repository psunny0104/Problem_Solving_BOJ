//	@date 2019/09/21
//	@author psunny0104
//	@brief boj_1935_후위 표기식2

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	char op[101] = { '\0', };
	double val[26] = { 0, };
	stack<double> s;

	cin >> N >> op;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}

	for (int i = 0; i < 100; i++) {
		if (op[i] == '\0')
			break;
		if (op[i] >= 'A' && op[i] <= 'Z') {
			s.push(val[op[i]-'A']);
		}
		else
		{
			if (s.size() != 1) {
				double opr_two = s.top();
				s.pop();
				double opr_one = s.top();
				s.pop();
				double res;
				if (op[i] == '+')
					res = opr_one + opr_two;
				else if (op[i] == '*')
					res = opr_one * opr_two;
				else if (op[i] == '-')
					res = opr_one - opr_two;
				else if (op[i] == '/')
					res = opr_one / opr_two;
				s.push(res);
			}
		}
	}

	cout.precision(2);
	cout << fixed;
	cout << s.top() << '\n';
	return 0;
}