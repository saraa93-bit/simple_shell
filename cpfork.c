#include "main.h"
int chilp_pid() {
    pid_t chilp;

    chilp = fork();

    if (chilp < 0) {
        printf(stderr, "Fork failed\n");
        return 1;
    }
    else if (chilp == 0)
    {
        printf("\n");
    }
    else
    {
        printf(error);
    }


    return (0);
}
