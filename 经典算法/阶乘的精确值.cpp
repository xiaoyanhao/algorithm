/* 输入不超过1000的正整数n,输出 n! = 1*2*3*⋯⋯*n的精确结果。 （1000！约等于4*10的2567次方，可开3000的数组） */ 

# include <stdio.h>
# include <string.h>
const int max = 3000;
int f[max];
int main() {
	int n, i, j;
	while (scanf("%d", &n) != EOF) {
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (i = 2; i <= n; i++) {
			int c = 0;
			for (j = 0; j < max; j++) {
				int temp = f[j] * i + c;
				f[j] = temp % 10;
				c = temp / 10;
			}
		}
		for (i = max - 1; i >= 0; i--) {
			if (f[i]) {
				break;
			}
		}
		for (j = i; j >= 0; j--) {
			printf("%d", f[j]);
		}
		printf("\n");
	}
	return 0;
}

