import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sentence = scanner.nextLine();
        System.out.println(invertWord(sentence));
        scanner.close();
    }

    public static String invertWord(String sentence) {
     String[] words = sentence.split("[^a-zA-Z]+");
     StringBuilder invertedSentence = new StringBuilder();

     for (int i = words.length - 1; i >= 0; i--) {
         String delimiter = i == 0 ? "" : " ";
         invertedSentence.append(words[i] + delimiter);
     }

     return invertedSentence.toString();
    }
}
