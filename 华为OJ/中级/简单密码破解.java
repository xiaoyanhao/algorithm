import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String output = decrypt(input);
        System.out.println(output);
        scanner.close();
    }

    private static String decrypt(String input) {
        int inputLength = input.length();
        StringBuilder password = new StringBuilder();

        for (int i = 0; i < inputLength; i++) {
            char c = input.charAt(i);

            if (Character.isUpperCase(c)) {
                c = (char)((c - 64) % 26 + 'a');
            } else if (Character.isLowerCase(c)) {
                if (c >= 'a' && c <= 'c') {
                    c = '2';
                } else if (c >= 'd' && c <= 'f') {
                    c = '3';
                } else if (c >= 'g' && c <= 'i') {
                    c = '4';
                } else if (c >= 'j' && c <= 'l') {
                    c = '5';
                } else if (c >= 'm' && c <= 'o') {
                    c = '6';
                } else if (c >= 'p' && c <= 's') {
                    c = '7';
                } else if (c >= 't' && c <= 'v') {
                    c = '8';
                } else if (c >= 'w' && c <= 'z') {
                    c = '9';
                }
            }

            password.append(c);
        }

        return password.toString();
    }
}
