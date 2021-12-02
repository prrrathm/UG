#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main() {
    pid_t pid;
    /* fork a child process */
    pid = fork();

    if (pid < 0) {/* error occurred */
        cout << stderr << "Fork Failed";
        return 1;
    }

    else if (pid == 0) {/* child process */
        execlp("/bin/ls","ls",NULL);
        cout << "LINE J";
    }

    else {/* parent process */
        /* parent will wait for the child to complete */
        // wait(NULL);
        cout << "Child Complete";
    }

    return 0;
}