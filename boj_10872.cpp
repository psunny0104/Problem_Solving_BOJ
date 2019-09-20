//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_10872_팩토리얼

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = 1;
	
	while (N>=1) {
		ans *= N;
		N--;
	}

	cout << ans << '\n';

	return 0;
}
