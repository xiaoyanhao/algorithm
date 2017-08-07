import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String a = scanner.next();
            String b = scanner.next();
            System.out.println(processString(a, b));
        }

        scanner.close();
    }

    public static String processString(String a, String b) {
        String c = a + b;
        int len = c.length();
        char[] odd = new char[len / 2];
        char[] even = new char[(len + 1) / 2];
        int oddIndex = 0;
        int evenIndex = 0;

        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                even[evenIndex++] = c.charAt(i);
            } else {
                odd[oddIndex++] = c.charAt(i);
            }
        }

        Arrays.sort(odd);
        Arrays.sort(even);
        convert(odd);
        convert(even);
        oddIndex = evenIndex = 0;
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                stringBuilder.append(even[evenIndex++]);
            } else {
                stringBuilder.append(odd[oddIndex++]);
            }
        }

        return stringBuilder.toString();
    }

    public static void convert(char[] chars) {
        int len = chars.length;

        for (int i = 0; i < len; i++) {
            char c = chars[i];

            if (Character.isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
                int a = Integer.parseInt(String.valueOf(c), 16);
                String b = Integer.toBinaryString(a);
                StringBuilder s = new StringBuilder(b).reverse();

                for (int j = b.length(); j < 4; j++) {
                    s.append('0');
                }

                b = s.toString();
                a = Integer.parseInt(b, 2);
                b = Integer.toHexString(a);
                chars[i] = b.toUpperCase().charAt(0);
            }
        }
    }
}
