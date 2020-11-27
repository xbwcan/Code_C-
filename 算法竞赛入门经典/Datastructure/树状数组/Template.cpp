
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int maxn = 20000 + 10;
const int maxv = 100000 + 10;
int maxx;
int a[maxn], c[maxn], d[maxn], BIT[maxv];
 
int lowerbit(int x)
{
    return x&-x;
}
int sum(int i)
{
    int ret = 0;
    while(i > 0)
    {
        ret += BIT[i];
        i -= lowerbit(i);
    }
    return ret;
}
void add(int i, int x)
{
    while(i < maxv)
    {
        BIT[i] += x;
        i += lowerbit(i);
    }
}
 
int main()
{
    freopen("output.txt", "w", stdout);
    int T, N, i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(i = 1; i <= N; i++) scanf("%d", &a[i]);
 
        memset(BIT, 0, sizeof(BIT));
        for(i = 1; i <= N-1; i++)
        {
            c[i] = sum(a[i]-1);
            add(a[i], 1);
        }
        memset(BIT, 0, sizeof(BIT));
        for(i = N; i >= 2; i--)
        {
            d[i] = sum(a[i]-1);
            add(a[i], 1);
        }
        long long ret = 0;
        for(i = 2; i <= N-1; i++) ret += c[i]*(N-i-d[i]) + d[i]*(i-1-c[i]);
        printf("%lld\n", ret);
    }
    return 0;
}