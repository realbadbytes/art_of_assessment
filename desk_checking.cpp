
/*
desk checking strategy:

track each variable at each line
statement       i       buf         c
for (i=0;       0       -           -
...
if(i<length)..  1       buf[1]='B'  B

tracing through this example, buffer out-of-bound write occurs
when \n appears more than len bytes into sock buffer
*/

int read_line(int sock, char *buf, size_t length)
{
    int i, c = 0, n;

    for (i = 0; ; i++)
    {
        n = read(sock, (void *)&c, 1);

        if (n != 1)
            return -1;

        if (c == '\n')
            break;

        if (i < length)
            buf[i] = c;
    }

    buf[i] = '\0';
    return 0;
}

int main()
{
    return 0;
}
