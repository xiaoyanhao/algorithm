import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String output = sortByLetterOnly(input);
        System.out.println(output);
        scanner.close();
    }

    private static String sortByLetterOnly(String input) {
        int inputLength = input.length();
        StringBuilder letterStr = new StringBuilder();

        for (int i = 0; i < inputLength; i++) {
            char c = input.charAt(i);

            if (Character.isLetter(c)) {
                letterStr.append(c);
            }
        }

        int  letterStrLen = letterStr.length();

        for (int i = 0; i < letterStrLen - 1; i++) {
            for (int j = 0; j < letterStrLen - 1 - i; j++) {
                char a = letterStr.charAt(j);
                char b = letterStr.charAt(j + 1);

                if (Character.toLowerCase(a) > Character.toLowerCase(b)) {
                    letterStr.setCharAt(j, b);
                    letterStr.setCharAt(j + 1, a);
                }
            }
        }

        StringBuilder sortedStr = new StringBuilder();
        int index = 0;

        for (int i = 0; i < inputLength; i++) {
            char c = input.charAt(i);

            if (Character.isLetter(c)) {
                c = letterStr.charAt(index++);
            }
            sortedStr.append(c);
        }

        return sortedStr.toString();
    }
}
