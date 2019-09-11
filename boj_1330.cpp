//	@date 2019/09/12
//	@author psunny0104
//	@brief boj_1330_두 수 비교하기

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;
	if (A > B ? cout << ">\n" : A == B ? cout << "==\n" : cout << "<\n");

	return 0;
}