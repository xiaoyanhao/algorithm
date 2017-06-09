import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String output = deleteLeastChar(input);
        System.out.println(output);
        scanner.close();
    }

    private static String deleteLeastChar(String input) {
        Map<Character, Integer> map = new HashMap<>();
        int inputLength = input.length();

        for (int i = 0; i < inputLength; i++) {
            char c = input.charAt(i);
            
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }

        int leastCount = Integer.MAX_VALUE;

        for (char key : map.keySet()) {
            int count = map.get(key);

            if (count < leastCount) {
                leastCount = count;
            }
        }

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < inputLength; i++) {
            char c = input.charAt(i);

            if (map.get(c) != leastCount) {
                stringBuilder.append(c);
            }
        }

        return stringBuilder.toString();
    }
}
