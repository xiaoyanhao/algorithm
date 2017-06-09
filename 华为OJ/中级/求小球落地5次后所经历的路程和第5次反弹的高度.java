import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int high = scanner.nextInt();
        System.out.println(getJourney(high));
        System.out.println(getTenthHigh(high));
        scanner.close();
    }

    /**
     * 统计出第5次落地时，共经过多少米?
     *
     * @param high 球的起始高度
     * @return 英文字母的个数
     */
    public static double getJourney(int high) {
        int n = 5;
        return high * (3 - 1 / Math.pow(2, n - 2));
    }

    /**
     * 统计出第5次反弹多高?
     *
     * @param high 球的起始高度
     * @return 空格的个数
     */
    public static double getTenthHigh(int high) {
        int n = 5;
        return high / Math.pow(2, n);
    }
}
