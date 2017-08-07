import java.util.Scanner;

public class Main {
    private static int a = 0;
    private static int b = 0;
    private static int c = 0;
    private static int d = 0;
    private static int e = 0;
    private static int error = 0;
    private static int pri = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String ipAndMask = scanner.next();
            String[] ipAndMaskArr = ipAndMask.split("~");
            String ip = ipAndMaskArr[0];
            String mask = ipAndMaskArr[1];

            if (isIpValid(ip) && isMaskValid(mask)) {
                classifyIp(ip);
            }
        }

        System.out.println(a + " " + b + " " + c + " " + d + " " + e + " " + error + " " + pri);
        scanner.close();
    }

    public static boolean isIpValid(String ip) {
        String[] ipSegments = ip.split("[.]");

        if (ipSegments.length != 4) {
            error++;
            return false;
        }

        for (String ipSegment : ipSegments) {
            try {
                int ipInt = Integer.parseInt(ipSegment);

                if (ipInt > 255 || ipInt < 0) {
                    error++;
                    return false;
                }
            } catch (Exception err) {
                error++;
                return false;
            }
        }

        return true;
    }

    public static boolean isMaskValid(String mask) {
        if (!isIpValid(mask)) {
            return false;
        }

        String[] maskSegments = mask.split("[.]");
        String maskBinary = "";

        for (String maskSegment : maskSegments) {
            maskBinary += Integer.toBinaryString(Integer.parseInt(maskSegment));
        }

        int firstIndexOfZero = maskBinary.indexOf("0");
        int lastIndexOfOne = maskBinary.lastIndexOf("1");

        if (firstIndexOfZero < lastIndexOfOne) {
            error++;
            return false;
        }
        return true;
    }

    public static void classifyIp(String ip) {
        String[] ipSegments = ip.split("[.]");

        int firstSegment = Integer.parseInt(ipSegments[0]);
        int secondSegment = Integer.parseInt(ipSegments[1]);

        if (firstSegment >= 1 && firstSegment <= 126) {
            a++;

            if (firstSegment == 10) {
                pri++;
            }
        } else if (firstSegment >= 128 && firstSegment <= 191) {
            b++;

            if (firstSegment == 172 && secondSegment >= 16 && secondSegment <= 31) {
                pri++;
            }
        } else if (firstSegment >= 192 && firstSegment <= 223) {
            c++;

            if (firstSegment == 192 && secondSegment == 168) {
                pri++;
            }
        } else if (firstSegment >= 224 && firstSegment <= 239) {
            d++;
        } else if (firstSegment >= 240 && firstSegment <= 255) {
            e++;
        }
    }
}
