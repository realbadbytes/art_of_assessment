#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int get_user(char *user)
{
    char buf[128];

    // strlen() function calculates the length of string, 
    // EXCLUDING THE TERMINATING NULL BYTE
    // our string user128 is actually 129 bytes long
    // this check passes since there are 128 chars
    // null terminator is then written outside of buf

    if (strlen(user) > sizeof(buf))
        exit(0);

    strcpy(buf, user);
}

int main()
{
    char *user4 = "aaaa\n";
    char *user128 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa \
                     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa \
                     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
    get_user(user4);
    // this causes off-by-one, can write one null byte past buf
    get_user(user128);
    return 0;
}
