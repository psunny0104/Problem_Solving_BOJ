//	@date 2019/11/07
//	@author psunny0104
//	@brief boj_1157_단어 공부

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt[26] = { 0, };
	
	int max = 0;
	string input;
	cin >> input;
	
	for (int i = 0; i < input.size(); i++) {
		int diff = 0;
		if ('A' <= input[i] && input[i] <= 'Z') {
			diff = input[i] - 'A';
		}
		else
			diff = input[i] - 'a';
		cnt[diff]++;
		if (cnt[diff] >= max)
			max = cnt[diff];
	}

	vector<char> ans;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == max)
			ans.push_back('A' + i);
	}

	if (ans.size() > 1)
		cout << "?\n";
	else
		cout << ans[0] << '\n';
	
	return 0;
}