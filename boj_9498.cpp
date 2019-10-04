//	@date 2019/10/04
//	@author psunny0104
//	@brief boj_9498_시험 성적

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int scr;
	cin >> scr;
	if (scr >= 90)
		cout << 'A' << '\n';
	else if (scr >= 80)
		cout << 'B' << '\n';
	else if (scr >= 70)
		cout << 'C' << '\n';
	else if (scr >= 60)
		cout << 'D' << '\n';
	else 
		cout << 'F' << '\n';

	return 0;
}