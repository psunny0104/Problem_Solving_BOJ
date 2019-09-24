//	@date 2019/09/24
//	@author psunny0104
//	@brief boj_16194_카드 구매하기 2

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//memo[n]: n개의 카드를 갖기 위해 지불해야 하는 금액의 최솟값
//p[n] = n번째 카드의 가격
//memo[n] = min(p[n],p[n-1]+memo[1]+...+p[n-k]+memo[k]) (k<=n-1)

int memo[1001];
int p[10001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	memo[1] = p[1]; //초기값
	for (int i = 2; i <= N; i++) {
		vector<int> v;

		//p[i]
		v.push_back(p[i]);
		//p[n-1]+memo[1]+...+p[n-k]+memo[k]
		for (int k = 1; k <= i - 1; k++) {
			v.push_back(p[i - k] + memo[k]);
		}
		//max_element는 값이 아닌 위치를 반환하므로 참조자 * 이용
		memo[i] = *min_element(v.begin(), v.end());
	}

	cout << memo[N] << '\n';

	return 0;
}