import java.net.Socket;
import java.net.ServerSocket;
import java.net.InetAddress;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.File;

public class HttpServer {
    public static final String WEB_ROOT =
            System.getProperty("user.dir") + File.separator + "webroot";

    private static final String SHUTDOWN_COMMAND = "/SHUTDOWN";

    public static void main(String[] args) {
        HttpServer server = new HttpServer();
        server.Await();
    }

    public void Await() {
        ServerSocket serverSocket = null;
        int port = 8080;
        try {
            serverSocket = new ServerSocket
                    (port, 1, InetAddress.getByName("127.0.0.1"));
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }

        while (true) {
            Socket socket = null;
            InputStream input = null;
            OutputStream output = null;
            try {
                socket = serverSocket.accept();
                input = socket.getInputStream();
                output = socket.getOutputStream();

                HttpRequest request = new HttpRequest(input);
                request.parse();

                if (request.getUri().equals(SHUTDOWN_COMMAND)) {
                    break;
                }

                // create an HttpResponse object
                HttpResponse response = new HttpResponse(output);
                response.setRequest(request);
                response.sendStaticResource();

                socket.close();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}