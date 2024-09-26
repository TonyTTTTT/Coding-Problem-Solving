#include <unistd.h>
#include <iostream>

int main() {

    for (int i=0; i<2; i++) {
        pid_t PID = fork();
        if (PID < 0) std::cout << "error when fork()" << std::endl;
        else if (PID == 0) {
            printf("This is child process, pid: %d\n", getpid());
        } else {
            printf("This is parent process, pid: %d\n", getpid());
        }
    }

    sleep(2);
    while (true) {
        printf("pid: %d\n", getpid());
        sleep(1);
    }

    return 0;
}