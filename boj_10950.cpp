//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_10950_A+B - 3

#include<iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	int A = 0, B = 0;
	cin >> N;
	while (N--) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
	
	return 0;
}