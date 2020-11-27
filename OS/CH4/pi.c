#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>
#include<windows.h>
int cnt = 0;
pthread_mutex_t mutex;
void *generate_random(void *args)
{
    //Sleep(1);
    
    pthread_mutex_lock(&mutex);
    double x, y;
    srand((unsigned int)GetCurrentThreadId());
    x = -1.0 + (double)((double)(rand() % 20) / 10.0);
    y = -1.0 + (double)((double)(rand() % 20) / 10.0);
        
    
    if(x*x+y*y<=1.0)
        cnt++;
    pthread_mutex_unlock(&mutex);
}
int main()
{
    freopen("pi.txt", "w", stdout);
    pthread_mutex_init(&mutex, NULL);
    
    double pi;
    int num = 50000;
    pthread_t tid[num];
    //int id[num];
    for (int i = 0; i < num;i++)
    {
        //id[i] = i;
        int ret = pthread_create(&tid[i], NULL, generate_random, NULL);
        if(ret!=0)
        {
            printf("Warning!");
        }
    }
    for (int i = 0; i < num;i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pi = 4.0*(double)cnt / num;
    printf("%lf\n%d", pi, cnt);
    return 0;
}