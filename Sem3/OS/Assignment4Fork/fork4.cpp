#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    pid_t pid, pid1;

    /* fork a child process */
    pid = fork();
    if (pid < 0) {/* error occurred */
        cout << stderr << "Fork Failed";
        return 1;
    }

    else if (pid == 0) {/* child process */
        pid1 = getpid();
        cout << "\nchild: pid = " << pid; /* A */
        cout << "\nchild: pid1 = " << pid1; /* B */
    }

    else {/* parent process */
        pid1 = getpid();
        cout << "\nparent: pid = " << pid; /* C */
        cout << "\nparent: pid1 = " << pid1; /* D */
        // wait(NULL);
    }

    return 0;
}