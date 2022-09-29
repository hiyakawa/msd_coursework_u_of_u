import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        int port = 8080;
        ServerSocket serverSocket = new ServerSocket(port);

        while (true) {
            Socket clientSocket = serverSocket.accept();
            InputStream inputStream = clientSocket.getInputStream();

            Scanner sc = new Scanner(inputStream);
            String line = sc.nextLine();

            while (! line.isEmpty()) {
                String result = "200 Success";

                OutputStream outputStream = clientSocket.getOutputStream();
                PrintWriter printWriter = new PrintWriter(outputStream);

                printWriter.print("http/1.x " + result + "\n");
                printWriter.println("Content-type: text/html");
            }


        }
    }
}