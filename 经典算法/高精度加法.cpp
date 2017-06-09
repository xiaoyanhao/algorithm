# include <stdio.h>
# include <string.h>
int a[10001], b[10001];
char c[10001], d[10001];
int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int i, j, len_c, len_d;
    scanf("%s %s", c, d);
    len_c = strlen(c);
    len_d = strlen(d);
    for (i = len_c - 1; i >= 0; i--)
        a[len_c - i - 1] = c[i] - 48;
    for (i = len_d - 1; i >= 0; i--)
        b[len_d - i - 1] = d[i] - 48;
    if (len_c < len_d)
        len_c = len_d;
    for (i = 0; i < len_c; i++) {
        a[i] = a[i] + b[i];
        a[i + 1] = a[i + 1] + a[i] / 10;
        if (i != len_c - 1)
            a[i] %= 10;
    }
    for (i = len_c - 1; i >= 0; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}

