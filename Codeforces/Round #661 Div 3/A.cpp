#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int x=0,num1=0,num2=0,ok=1;
int main()
{

    int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		sort(a.begin(), a.end());
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			ok &= (a[i] - a[i - 1] <= 1);
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}