import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int order = scanner.nextInt();
        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int score = scanner.nextInt();
            students[i] = new Student(name, score);
        }

        sortByScore(students, order);

        for (Student student : students) {
            System.out.println(student.name + ' ' + student.score);
        }

        scanner.close();
    }

    public static void sortByScore(Student[] students, int order) {
        if (order == 0) {
            Arrays.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student s1, Student s2) {
                    return s2.score - s1.score;
                }
            });
        } else if (order == 1) {
            Arrays.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student s1, Student s2) {
                    return s1.score - s2.score;
                }
            });
        }
    }

    private static class Student {
        private String name;
        private int score;

        public Student(String name, int score) {
            this.name = name;
            this.score = score;
        }
    }
}
