import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class TextAnalyzer {
    public static void parseFile(String file_name) {
        File file = new File(file_name);

        while (! file.exists() || file.isDirectory()) {
            System.out.println("File does not exist. Enter a valid file path:");
            Scanner s = new Scanner(System.in);
            file_name = s.next();
            file = new File(file_name);
        }

        try {
            Scanner fileReader = new Scanner(file);
            int[] myArray = new int[26];

            while (fileReader.hasNext()) {
                String line = fileReader.nextLine().toLowerCase();

                for (int i = 0; i < line.length(); i++) {
                    char cur_char = line.charAt(i);
                    if (Character.isLetter(cur_char)) {
                        myArray[line.charAt(i) - 'a']++;
                    }
                }
            }

            for (int i = 0; i < myArray.length; i++) {
                System.out.println((char)(i + 65) + ", " + myArray[i]);
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        String file_name = "/Users/laurazhang/myLocalGithubRepo/CS6011/Week2/Day10/Midterm/src/wireshark_lab.txt";
        TextAnalyzer.parseFile(file_name);
    }
}