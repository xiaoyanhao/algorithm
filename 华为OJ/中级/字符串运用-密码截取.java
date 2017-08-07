import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String password = scanner.nextLine();
        System.out.println(findLongestPalindrome(password));

        scanner.close();
    }

    public static int findLongestPalindrome(String password) {
        int passwordLen = password.length();
        StringBuilder sb = new StringBuilder("$#");

        for (int i = 0; i < passwordLen; i++) {
            sb.append(password.charAt(i));
            sb.append("#");
        }


        int sbLen = sb.length();
        int p[] = new int[sbLen];
        int mx = 0;
        int id = 0;
        int ans = 0;

        for (int i = 1; i < sbLen; i++) {
            if (mx > i) {
                p[i] = Math.min(p[2 * id - i], mx - i);
            } else {
                p[i] = 1;
            }

            while (i - p[i] >= 0 && i + p[i] < sbLen &&
                    sb.charAt(i - p[i]) == sb.charAt(i + p[i])) {
                p[i]++;
            }

            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }

            ans = Math.max(ans, p[i] - 1);
        }

        return ans;
    }
}
