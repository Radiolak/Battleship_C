int my_strlen_0(char const * str)
{
    int i = 0;

    while (str[i] == '\0') {
        i++;
    }
    return (i);
}
