char **result;
int count;

void generate(int n, int open, int close, char *str, int pos)
{
    if (pos == 2 * n)
    {
        str[pos] = '\0';
        result[count] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[count], str);
        count++;
        return;
    }

    if (open < n)
    {
        str[pos] = '(';
        generate(n, open + 1, close, str, pos + 1);
    }

    if (close < open)
    {
        str[pos] = ')';
        generate(n, open, close + 1, str, pos + 1);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    result = (char **)malloc(1500 * sizeof(char *));
    count = 0;

    char str[20];

    generate(n, 0, 0, str, 0);

    *returnSize = count;

    return result;
}
