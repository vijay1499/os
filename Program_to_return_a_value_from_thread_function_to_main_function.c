#include <stdio.h>
#include <pthread.h>
#include<stlib.h>

struct arg_struct
{
    int arg1;
    int arg2;
    int arg3;
};

void *print_the_arguments(void *arg)
{
    struct arg_struct *ar = (struct arg_struct *)arg;
    scanf("%d", &ar->arg3);
    scanf("%d", &ar->arg2);
    int *c = malloc(sizeof(int));
    *c = ar->arg2 + ar->arg3;
    pthread_exit(c);
}

int main()
{
    pthread_t some_thread;
    struct arg_struct args;
    args.arg1 = 5;
    args.arg2 = 7;
    void *a;
    pthread_create(&some_thread, NULL, &print_the_arguments, &args);
    pthread_join(some_thread, &a); /* Wait until thread is finished */
    printf("%d\n", *(int *)a);
    free(a);
    return 0;
}

