import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int emptySoda = scanner.nextInt();

            if (emptySoda != 0) {
                System.out.println(getSoda(emptySoda));
            } else {
                break;
            }
        }
        scanner.close();
    }

    private static int getSoda(int emptySoda) {
        int base = 3;
        int soda = 0;

        while (emptySoda > base - 1) {
            int newSoda = emptySoda / base;
            int leftSoda = emptySoda % base;
            soda += newSoda;
            emptySoda = leftSoda + newSoda;
        }

        if (emptySoda == base - 1) {
            soda++;
        }

        return soda;
    }
}
