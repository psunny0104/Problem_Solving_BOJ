//	@date 2019/09/10
//	@author psunny0104
//	@brief boj_10818_최소, 최대
//	구현 버전

#include <iostream>
#define MAX 1000001
#define MIN -1000001
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, tmp;
	cin >> N;
	
	int min_val = MAX;
	int max_val = MIN;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > max_val)
			max_val = tmp;
		if (tmp < min_val)
			min_val = tmp;
	}
	cout << min_val << " " << max_val << "\n";

	return 0;
}