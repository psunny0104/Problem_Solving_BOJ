//	@date 2019/09/18
//	@author psunny0104
//	@brief boj_10773_Á¦·Î

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K, num, sum = 0;
	stack<int> s;
	
	cin >> K;
	while (K--) {
		cin >> num;
		if (num == 0) {
			sum -= s.top();
			s.pop();
		}
		else {
			s.push(num);
			sum += num;
		}
	}
	cout << sum << '\n';

	return 0;
}
