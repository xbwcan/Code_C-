#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n, m, num[101][101];
int ok = 0;
int len;
int x1, y1, x2, y2, x3, y3;
int dfs(int cnt);
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        scanf("%d%d", &n, &m);
        len = n * m;
        ok = 0;
        for (int i = 1; i <= n;i++)
        {
            getchar();
            for (int j = 1; j <= m;j++)
            {
                num[i][j] = getchar() - '0';
            }
        }
        getchar();
        dfs(0);
    }
}
int dfs(int cnt)
{
    if(!ok)
    {
        for (int i = 1; i <= len-2;i++)
        {
            for (int j = i + 1; j <= len - 1;j++)
            {
                for (int k = j + 1; k <= len;k++)
                {
                    x1 = i / m;
                    y1 = i % m;
                    if(y1==0)
                    {
                        x1++;
                        y1 += m;
                    }
                    x2 = j / m;
                    y2 = j % m;
                    if(y2==0)
                    {
                        x2++;
                        y2 += m;
                    }
                    x3 = k / m;
                    y3 = k % m;
                    if(y3==0)
                    {
                        x3++;
                        y3 += m;
                    }
                    num[x1][y1] = 1 - num[x1][y1];
                    num[x2][y2] = 1 - num[x2][y2];
                    num[x3][y3] = 1 - num[x3][y3];
                }
            }
        }
    }
}