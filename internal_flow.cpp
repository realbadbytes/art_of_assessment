
/*
analysis:
follow error-checking branches first, these are probably not well tested
then follow pathological path to all branches
read_integer() fail?
malloc() fail()?
etc
remember that "it is possible to trigger paths that logically don't make sense
but based on program state, can and do occur." these paths are strange but
are not prohibited by the implementation.
*/

char *read_string(int fd, int maxlen)
{
    int len;
    char *data;

    if (read_integer(fd, &length) < 0)
        return NULL;

    data = (char *)malloc(len+1);

    if (data == NULL)
        return NULL;

    if (read(fd, data, len) < 0)
    {
        free(data);
        return NULL;
    }

    data[len] = '\0';

    return data;
}

int main()
{
    return 0;
}
