import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int month = scanner.nextInt();
        System.out.println(fibonacci(month));
        scanner.close();
    }

    public static int fibonacci(int month) {
        int beforeLastMonth = 0;
        int lastMonth = 1;
        int rabbit = 1;

        for (int i = 0; i < month - 1; i++) {
            rabbit = lastMonth + beforeLastMonth;
            beforeLastMonth = lastMonth;
            lastMonth = rabbit;
        }

        return rabbit;
    }
}
