//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_9613_GCD 합

#include <iostream>
#include <cstring>
using namespace std;

int input[101];
bool is_selected[101];
long long ans; //int 로는 부족함
int one, two;

int GCD(int A, int B)
{
	int a = A;
	int b = B;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void cmb(int idx, int cnt, int n)
{
	if (cnt == 2) {
		//GCD
		one = 0, two = 0;
		for (int i = 0; i < n; i++) {
			if (is_selected[i] == true) {
				if (one == 0)
					one = input[i];
				else
					two = input[i];
			}
		}

		ans += (long long)GCD(one, two);
		return ;
	}
	
	for (int i = idx; i < n; i++) {
		if (is_selected[i] == true)
			continue;

		is_selected[i] = true;
		cmb(i , cnt + 1, n);
		is_selected[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	//조합 만들고, GCD 구한 후 더하자

	cin >> N;
	while (N--) {
		int num;
		cin >> num;

		ans = 0;
		memset(is_selected, 0, sizeof(is_selected));
		memset(input, 0, sizeof(input));

		for (int i = 0; i < num; i++) {
			cin >> input[i];
		}
		
		cmb(0, 0, num);
		
		cout << ans << '\n';
	}

	return 0;
}