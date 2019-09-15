//	@date 2019/09/15
//	@author psunny0104
//	@brief boj_2742_±âÂï N

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	N++;
	while (N-- && N>0) {
		cout << N << "\n";
	}
	return 0;
}