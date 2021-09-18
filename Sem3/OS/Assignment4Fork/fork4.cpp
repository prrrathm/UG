#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, pid1;

    /* fork a child process */
    pid = fork();
    if (pid < 0) {/* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    else if (pid == 0) {/* child process */
        pid1 = getpid();
        printf("\nchild: pid = %d",pid); /* A */
        printf("\nchild: pid1 = %d",pid1); /* B */
    }

    else {/* parent process */
        pid1 = getpid();
        printf("\nparent: pid = %d",pid); /* C */
        printf("\nparent: pid1 = %d",pid1); /* D */
        // wait(NULL);
    }

    return 0;
}