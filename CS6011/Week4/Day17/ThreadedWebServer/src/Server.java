import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private final ServerSocket serverSocket_;

    public Server(ServerSocket serverSocket) {
        serverSocket_ = serverSocket;
    }

    public void runServer() {
        Socket clientSocket;
        while (true) {
            try {
                clientSocket = serverSocket_.accept();
                Thread thread = new Thread(new HandlerRunnable(clientSocket));
                thread.start();
            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}