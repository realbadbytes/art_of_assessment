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
    int infd, outfd; // File descriptors
    pid_t pid;
    char prompt[MAX_BUF] = {0}; // input buffer
    char *namedPipe = "mypipe"; // FIFO Pipe
    char pipeCmd[CMD_LEN] = "/bin/ls"; // Command to send to pipe;

    mkfifo(namedPipe, 0666); // Create pipe

    pid = fork(); // Fork

    if (pid == 0) //Child
    {
        printf("Preparing to write to pipe...\n");
        if ((infd = open(namedPipe, O_WRONLY)) == -1) // write only
            printf("Could not open pipe in write mode!?\n");
        else 
            printf("Pipe opened in write mode!\n");
        write(infd, pipeCmd, strlen(pipeCmd)+1); // write cmd
        printf("/bin/ls written to pipe! \n");
        close(infd);
        exit(0); // murder child
    }

    if (pid != 0) // Parent
    {
        char cmd[CMD_LEN];

        printf("Reading CMD from pipe...\n");
        if ((outfd = open(namedPipe, O_RDONLY)) == -1) // read only
        {
            printf("Could not open pipe in read mode!?\n");
            exit(1);
        }

        read(outfd, cmd, CMD_LEN);
        close(outfd);
        printf("Running: %s\n", cmd);
        remove(namedPipe);
        execl(cmd, cmd, NULL);
    }

    return 0;
}
