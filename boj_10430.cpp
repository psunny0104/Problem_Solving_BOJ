//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_10430_나머지

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;

	cin >> A >> B >> C;

	cout << (A + B) % C << '\n';
	cout << ((A % C) + (B % C)) % C << '\n';
	cout << (A * B) % C << '\n';
	cout << ((A % C) * (B % C)) % C << '\n';

	return 0;
}