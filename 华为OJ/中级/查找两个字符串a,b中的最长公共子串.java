import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();
        String b = scanner.nextLine();
        String lcs = longestCommonSubstring(a, b);
        System.out.println(lcs);
        scanner.close();
    }

    public static String longestCommonSubstring(String a, String b) {
        int aLength = a.length() + 1;
        int bLength = b.length() + 1;
        int[][] p = new int[aLength][bLength];
        int maxLen = 0;
        int endPos = 0;

        for (int i = 0; i < aLength; i++) {
            for (int j = 0; j < bLength; j++) {
                p[i][j] = 0;
            }
        }

        for (int i = 1; i < aLength; i++) {
            for (int j = 1; j < bLength; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    p[i][j] = p[i - 1][j - 1] + 1;
                } else {
                    p[i][j] = 0;
                }

                if (p[i][j] > maxLen) {
                    maxLen = p[i][j];
                    endPos = i;
                }
            }
        }

        return a.substring(endPos - maxLen, endPos);
    }
}
