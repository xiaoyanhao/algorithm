import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int negative = 0;
        int positive = 0;
        double positiveSum = 0.0;

        while (scanner.hasNext()) {
            int n = scanner.nextInt();

            if (n > 0) {
                positive++;
                positiveSum += n;
            } else if (n < 0) {
                negative++;
            }
        }

        scanner.close();
        System.out.format("%d\n%.1f", negative, positive == 0 ? 0.0 : positiveSum / positive);
    }
}
