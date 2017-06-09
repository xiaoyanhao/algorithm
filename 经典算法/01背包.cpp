# include <stdio.h>

int best[100005] = {}, need[505], value[505];
int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &need[i], &value[i]);
    }
    for (i = 1; i <= n; i++) {
        for (j = m; j >= need[i]; j--) {
            if (best[j] < best[j - need[i]] + value[i]) {
                best[j] = best[j - need[i]] + value[i];
            }
        }
    }
    printf("%d\n", best[m]);
    return 0;
}

