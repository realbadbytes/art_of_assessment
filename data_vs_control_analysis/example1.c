int bob(int c)
{
    if (c == 4)
        fred(c);
    if (c == 72)
        jim();
    for (; c; c--)
        updateState();
}

control flow analysis strategy:
    follow all function calls in function without regard
    for any variables. this is great for full understanding,
    **if** you can really keep track of state changes etc.

data flow analysis strategy:
    follow only calls related to targeted data. For example, c
    we would follow fred(c), but not jim() or updateState().
    faster review and is *favored* to reduce mental context-switching
    in between rabbit-hole function following
