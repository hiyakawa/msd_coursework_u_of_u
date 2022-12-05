import java.io.IOException;
import java.net.Socket;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;

public class MyRunnable implements Runnable {
    private Socket clientSocket_;

    MyRunnable(Socket clientSocket) {
        clientSocket_ = clientSocket;
    }

    @Override
    public void run() {
        try {
            Request request = new Request(clientSocket_);
            String fileName = request.getFileName();
            HashMap<String, String> header = request.getHeaderBody();

            Response response = new Response(clientSocket_, fileName, header);
            response.sendResponseHeader();

            if (header.containsKey("Sec-WebSocket-Key")) {
                WebSocketHandler wsRequest = new WebSocketHandler(clientSocket_);

                while (true) {
                    wsRequest.readWsRequest();
                    wsRequest.respondWsRequest();
                }
            }
            else {
                clientSocket_.close();
            }
        }
        catch (IOException | NoSuchAlgorithmException | InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}