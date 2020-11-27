#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int t;
int n, c0, c1, h;
int num[1001];
int main()
{
    
    cin >> t;
    while(t--)
    {
        scanf("%d%d%d%d", &n, &c0, &c1, &h);
        //cout << n << " " << c0 << " " << c1 << " " << h << endl;
        getchar();
        for (int i = 1; i <= n;i++)
        {
            num[i] = getchar() - '0';
        }
        getchar();
        long long sum = 0;
        if(c1>c0+h)
        {
            for (int i = 1; i <= n;i++)
                if(num[i]==1)
                {
                    num[i] = 0;
                    sum += h;
                }
        }
        else if(c0>c1+h)
        {
            for (int i = 1; i <= n;i++)
                if(num[i]==0)
                {
                    num[i] = 1;
                    sum += h;
                }
        }
        
        for (int i = 1; i <= n;i++)
        {
            
            if(num[i]==1)
            {
                sum += c1;
            }
            else
            {
                sum += c0;
            }
            
            //cout << num[i] << " " << sum << endl;
        }
        cout << sum << endl;
    }
    return 0;
}