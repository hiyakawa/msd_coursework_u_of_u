import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(8080);
        Socket client = ss.accept();

        InputStream input = client.getInputStream();
        Scanner scanner = new Scanner(input);
        String line = scanner.nextLine();
        System.out.println(line);



    }
}