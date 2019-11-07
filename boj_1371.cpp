//	@date 2019/11/07
//	@author psunny0104
//	@brief boj_1371_가장 많은 글자

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	char input[5002];
	int cnt[27] = { 0, };
	int max = 0;
	vector<char> ans;
	
	while(cin.getline(input, sizeof(input))){
		int size = strlen(input);
		for (int i = 0; i < size; i++) {
			if(0<=input[i]-'a' && input[i]-'a'<=25)
				cnt[input[i]-'a']++;
			if (cnt[input[i]-'a'] >= max)
				max = cnt[input[i] - 'a'];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] == max)
			ans.push_back('a' + i);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}

	return 0;
}