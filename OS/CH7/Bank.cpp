#include<cstdio>
#include<algorithm>
using namespace std;
struct MyProcess
{
    int Allocation[10], Need[10], Work[10];
    int sum;
};
int Avaliable[10],vis[10];
int NumofProcess, NumofResource,SUM;
MyProcess mp[10];
bool cmp(const MyProcess &p1, const MyProcess &p2)
{
    return p1.sum < p2.sum;
}
int check(MyProcess p);
int main()
{
    
    
    for (int i = 1; i <= NumofProcess;i++)
    {
        mp[i].sum = 0;
        for (int j = 1; j <= NumofResource;j++)
        {
            mp[i].Need[j] = mp[i].Work[j] - mp[i].Allocation[j];
            mp[i].sum += mp[i].Need[j];
            SUM += Avaliable[j];
        }
    }
    sort(mp + 1, mp + NumofProcess, cmp);
    int cnt = 0, flag = 1;
    while(cnt<NumofProcess)
    {
        if(flag)
        {
            for (int i = 1; i <= NumofProcess;i++)
            {
                if(vis[i])
                    continue;
                if(check(mp[i]))
                {
                    cnt++;
                    vis[i] = 1;
                    for (int j = 1; j <= NumofResource;j++)
                    {
                        Avaliable[j] += mp[i].Need[j];
                    }
                    break;
                }
                else
                {
                    if(mp[i].sum>SUM)
                    {
                        flag = 0;
                    }
                }
            }
        }
    }
    if(flag)
    {
        printf("Safe");
    }
    else  
    {
        printf("Unsafe");
    }
}
int check(MyProcess p)
{
    int ok = 1;
    for (int i = 1; i <= NumofResource;i++)
    {
        if(p.Need[i]>Avaliable[i])
        {
            ok = 0;
            break;
        }
    }
    return ok;
}
