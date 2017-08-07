import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String password = scanner.nextLine();
            boolean valid = validatePassword(password);

            if (valid) {
                System.out.println("OK");
            } else {
                System.out.println("NG");
            }
        }

        scanner.close();
    }

    public static boolean validatePassword(String password) {
        int passwordLen = password.length();

        if (passwordLen <= 8) {
            return false;
        }

        int[] type = new int[4];

        for (int i = 0; i < passwordLen; i++) {
            char c = password.charAt(i);

            if (Character.isDigit(c)) {
                type[0] = 1;
            } else if (Character.isLowerCase(c)) {
                type[1] = 1;
            } else if (Character.isUpperCase(c)) {
                type[2] = 1;
            } else {
                type[3] = 1;
            }
        }

        if (type[0] + type[1] + type[2] + type[3] < 3) {
            return false;
        }

        for (int i = 0; i < passwordLen - 3; i++) {
            String a = password.substring(i, i + 3);
            String b = password.substring(i + 3);

            if (b.contains(a)) {
                return false;
            }
        }

        return true;
    }
}
