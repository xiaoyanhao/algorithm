import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 2;
        String[] strings = new String[n];

        for (int i = 0; i < n; i++) {
            strings[i] = scanner.next();
        }

        splitString(strings);
        scanner.close();
    }

    public static void splitString(String[] strings) {
        ArrayList<String> arrayList = new ArrayList<>();

        for (String string : strings) {
            int strLen = string.length();
            int pos = 8;

            while (pos <= strLen) {
                arrayList.add(string.substring(pos - 8, pos));
                pos += 8;
            }

            if (pos - strLen < 8) {
                String s = string.substring(pos - 8, strLen);
                char[] chars = new char[pos - strLen];
                Arrays.fill(chars, '0');
                s += new String(chars);
                arrayList.add(s);
            }
        }

        for (String string : arrayList) {
            System.out.println(string);
        }
    }
}
