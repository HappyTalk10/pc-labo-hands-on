#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("私のPIDは %d です\n", getpid());
    return 0;
}
