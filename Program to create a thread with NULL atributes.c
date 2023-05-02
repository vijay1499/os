#include<stdio.h>
#include<pthread.h>

char* msg;

void *func() {
    char* exit_msg = "Exit thread function\n";
    printf("In thread function\n");
    pthread_exit(exit_msg);
}

int main() {
    pthread_t thread1;
    void* exit_status;
    printf("In main thread\n");
    pthread_create(&thread1, NULL, func, NULL);
    pthread_join(thread1, &exit_status);
    msg = (char*)exit_status;
    printf("%s\n", msg);
    return 0;
}

