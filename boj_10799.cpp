//	@date 2019/09/19
//	@author psunny0104
//	@brief boj_10799_쇠 막대기

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<char> s;
	string input; 
	cin >> input;
	
	int size = input.size();
	int ans = 0;
	int num_pr = 0;

	for (int i = 0; i <size; i++) {
		if (input[i] == '(') {
			s.push(input[i]);
			num_pr++;
		}
		else if (input[i] == ')') {
			if (s.top() == '(') {
				s.push(input[i]);
				num_pr--;
				ans += num_pr;
			}
			else {
				s.push(input[i]);
				num_pr--; 
				ans += 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}