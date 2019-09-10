//	@date 2019/09/10
//	@author psunny0104
//	@brief boj_10818_최소, 최대
//	sort 사용 버전

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> v;
	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cout << v.front() << " " << v.back() << "\n";

	return 0;
}