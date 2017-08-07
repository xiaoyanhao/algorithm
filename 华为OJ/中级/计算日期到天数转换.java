import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int year = scanner.nextInt();
        int month = scanner.nextInt();
        int day = scanner.nextInt();

        System.out.println(dateToDays(year, month, day));
        scanner.close();
    }

    public static int dateToDays(int year, int month, int day) {
        int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = day;

        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
            months[1] = 29;
        }

        if (month < 1 || month > 12 || day < 1 || day > months[month - 1]) {
            return -1;
        }

        for (int i = 0; i < month - 1; i++) {
            days += months[i];
        }

        return days;
    }
}
