import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static final int MAX_N = 50;
    public static boolean[] visit = new boolean[MAX_N];
    public static int[] flag = new int[MAX_N];
    public static int[] v1;
    public static int[] v2;
    public static int n = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        v1 = new int[n / 2];
        v2 = new int[n / 2];

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();

            if (num % 2 == 0) {
                v1[i / 2] = num;
            } else {
                v2[i / 2] = num;
            }
        }

        scanner.close();
        hungarianAlgorithm();
    }

    public static void hungarianAlgorithm() {
        int result = 0;

        for (int i = 0; i < n / 2; i++) {
            Arrays.fill(visit, false);

            if (findPrime(v1[i])) {
                result++;
            }
        }

        System.out.println(result);
    }

    public static boolean findPrime(int a) {
        for (int i = 0; i < n / 2; i++) {
            int b = v2[i];

            if (isPrime(a + b) && !visit[i]) {
                visit[i] = true;

                if (flag[i] == 0 || findPrime(flag[i])) {
                    flag[i] = a;
                    return true;
                }
            }
        }

        return false;
    }

    public static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
}
