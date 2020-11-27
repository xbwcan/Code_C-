#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long  t, n, k;
long long  num[1000001];
long long len, sum, cur;
int main()
{
    cin >> t;
    while(t--)
    {
        scanf("%d%d", &n, &k);
        len = n * k;
        cur = n / 2;
        for (int i = 1; i <= len;i++)
            scanf("%ld", &num[i]);
        sum = 0;
        long long l = 1, r = len;
        while(l<=r)
        {
            //cout << l << "   " << r << "  " << endl;
            sum += num[r-cur];
            l += n - cur - 1;
            r -= cur + 1;
        }
        cout << sum << endl;
    }
}