//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_10817_¼¼ ¼ö

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	if (A > B) {
		if (B > C)
			cout << B << "\n";
		else {
			if (A > C)
				cout << C << "\n";
			else
				cout << A << "\n";
		}
	}
	else {
		if (A > C)
			cout << A << "\n";
		else {
			if (B > C)
				cout << C << "\n";
			else
				cout << B << "\n";
		}
	}

	return 0;
}