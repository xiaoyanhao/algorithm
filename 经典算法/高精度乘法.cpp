# include <stdio.h>
# include <string.h>
char a[401], b[401];
int aa[401], bb[401], sum[401];
int main() {
    memset(sum, 0, sizeof(sum));
    int i, j;
    scanf("%s %s", a, b);
    int len_a = strlen(a), len_b = strlen(b);
    for (i = len_a - 1; i >= 0; i--)
        aa[len_a - 1 - i] = a[i] - '0';
    for (j = len_b - 1; j>= 0; j--)
        bb[len_b - 1 - j] = b[j] - '0';
    for (i = 0; i < len_a; i++) {
        for (j = 0; j < len_b; j++) {
            sum[j + i] += aa[i] * bb[j];
        }
    }
    for (i = 0; i <= 400; i++) {
        if (sum[i] >= 10) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
    for (i = 400; i > 0; i--)
        if (sum[i] != 0)
            break;
    for (j = i; j >= 0; j--)
        printf("%d", sum[j]);
    printf("\n");
    return 0;
    }

