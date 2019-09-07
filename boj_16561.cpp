//	@date 2019/09/07
//	@author psunny0104
//	@brief boj_16561_3의 배수

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, ans = 0;
	cin >> N;

	for (int i = 3; i <= N; i += 3) { //3 ~ N까지 3씩 더해가며 첫번째 수 선택
		for (int j = 3; j <= N; j += 3) { //마찬가지 방법으로 두번째 수 선택
			if (N - i - j >= 3) //N에서 첫번째 수와 두번째 수를 뺀 값은 무조건 3의 배수 or 0임
				ans++;         //0만 아니면 세 가지 3의 배수의 합으로 표현이 되는 것임 
		}					   //따라서 가장 작은 3의 배수인 >=3 혹은 >0 의 조건을 만족하면 됨
	}

	cout << ans << "\n";

	return 0;
}