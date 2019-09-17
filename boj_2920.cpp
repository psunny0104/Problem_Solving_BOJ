//	@date 2019/09/17
//	@author psunny0104
//	@brief boj_2920_À½°è

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int input[9];
	bool asc = true;
	bool des = true;

	for (int i = 1; i <= 8; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= 7; i++) {
		if (input[i] <= input[i + 1]) {
			des = false;
		}
		if (input[i] >= input[i + 1]) {
			asc = false;
		}
	}
	if (asc)
		cout << "ascending" << "\n";
	else if (des)
		cout << "descending" << "\n";
	else
		cout << "mixed" << "\n";
	return 0;
}