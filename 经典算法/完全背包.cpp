# include <stdio.h>

int best[100005], need[505], value[505];
int main() {
    int n, m, i, j;
    memset(best, 0, sizeof(best));
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &need[i], &value[i]);
    }
    for (i = 0; i < m; i++) {
        best[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = need[i]; j <= m; j++) {
            if (best[j - need[i]] + value[i] > best[j]) {
                best[j] = best[j - need[i]] + value[i];
            }
        }
    }
    printf("%d\n", best[m]);
    return 0;
}

