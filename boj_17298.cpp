//	@date 2019/09/19
//	@author psunny0104
//	@brief boj_17298 오큰수

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> s_in;
	stack<int> s_out;
	stack<int> s_ans;
	int N,in;

	cin >> N; 
	for(int i  = 0;  i< N; i++){
		cin >> in;
		s_in.push(in);
	}

	s_ans.push(-1);
	s_out.push(s_in.top());
	s_in.pop();

	while(!s_in.empty()){
		if (s_out.top() > s_in.top()) {
			s_ans.push(s_out.top());
			s_out.push(s_in.top());
			s_in.pop();
		}
		else {
			while (!s_out.empty() && s_out.top() <= s_in.top()) { //숫자가 같은 경우도 존재!
				s_out.pop();
			}
			if (s_out.empty()) {
				s_ans.push(-1);
				s_out.push(s_in.top());
				s_in.pop();
			}
		}
	}
	
	while (!s_ans.empty()) {
		cout << s_ans.top() << ' ';
		s_ans.pop();
	}

	return 0;
}