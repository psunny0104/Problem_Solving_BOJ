#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tmp;
	vector<int> v;
	
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}