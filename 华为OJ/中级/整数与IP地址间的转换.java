import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String strIp = scanner.next();
        int intIp = scanner.nextInt();
        System.out.println(ipToInt(strIp));
        System.out.println(intToIp(intIp));

        scanner.close();
    }

    public static int ipToInt(String ip) {
        String[] ipSeg = ip.split("[.]");
        int intIp = 0;

        for (String seg : ipSeg) {
            intIp = (intIp << 8) + Integer.parseInt(seg);
        }

        return intIp;
    }

    public static String intToIp(int ip) {
        String strIp = "";

        for (int i = 0; i <= 3; i++) {
            strIp = (ip & 0xff) + "." + strIp;
            ip >>>= 8;
        }

        return strIp.substring(0, strIp.length() - 1);
    }
}
