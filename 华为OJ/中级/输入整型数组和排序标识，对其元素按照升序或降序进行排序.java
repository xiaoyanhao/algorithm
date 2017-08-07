import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        Integer[] num = new Integer[n];

        for (int i = 0; i < n; i++) {
            num[i] = scanner.nextInt();
        }

        int sortWay = scanner.nextInt();
        sortAndPrint(num, sortWay);

        scanner.close();
    }

    public static void sortAndPrint(Integer[] num, final int sortWay) {
        Arrays.sort(num, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return sortWay == 0 ? o1 - o2 : o2 - o1;
            }
        });

        String numStr = Arrays.toString(num);
        numStr = numStr.substring(1, numStr.length() - 1).replace(", ", " ");

        System.out.println(numStr);
    }
}
