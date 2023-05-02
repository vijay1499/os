#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h> // need to include this header for sleep()

int main() {
    pid_t a;
    a = fork();
    if (a > 0) {
        sleep(20);
        printf("PID of Parent %d\n", getpid());
    }
    else {
        printf("PID of CHILD %d\n", getpid());
        exit(0);
    }
    return 0;
}

