import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String command = scanner.nextLine();
        System.out.println(moveCoordinate(command));
        scanner.close();
    }

    public static String moveCoordinate(String command) {
        String[] commands = command.split(";");
        int[] point = new int[2];

        for (String cmd : commands) {
            move(cmd, point);
        }

        return point[0] + "," + point[1];
    }

    public static void move(String cmd, int[] point) {
        if (cmd.matches("(A|D|W|S)\\d{1,2}")) {
            char direction = cmd.charAt(0);
            int step = Integer.parseInt(cmd.substring(1));

            switch (direction) {
                case 'A':
                    point[0] -= step;
                    break;
                case 'D':
                    point[0] += step;
                    break;
                case 'W':
                    point[1] += step;
                    break;
                case 'S':
                    point[1] -= step;
                    break;
                default:
                    break;
            }
        }
    }
}
