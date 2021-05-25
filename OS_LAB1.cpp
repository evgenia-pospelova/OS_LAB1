
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>


using namespace std;


void *task1(void *flag1)
{
    int a = 1;
    bool *flag =(bool*) flag1;
    while (flag){
        cout << a;
        cout.flush();
        sleep(1);
    }

    return 0;
}
void *task2(void *flag2)
{
    int b = 2;
    bool *flag = (bool*) flag2;
    while (flag) {
        cout << b;
        cout.flush();
        sleep(1);
    }

    return 0;
}

int main(){
    bool flag1 = true;
    bool flag2 = true;
    pthread_t tid;
    pthread_t tid2;
    int *result1, *result2;
pthread_create(&tid, NULL, task1, (void*)&flag1);
pthread_create(&tid2, NULL, task2, (void*)&flag2);
getchar();
flag1 = false;
flag2= false;
pthread_join(tid, (void**)&result1);
pthread_join(tid2, (void**)&result2);


  return 0;
}
