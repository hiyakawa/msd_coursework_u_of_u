import java.net.Socket;
import java.io.IOException;
import java.io.DataInputStream;
import java.io.InputStream;

public class HandleThread implements Runnable {
    private final Socket socket_;

    public HandleThread(Socket socket) {
        socket_ = socket;
    }

    @Override
    public void run() {
        Request request = new Request(socket_);
        request.getRequest();

        if (request.getIsWS()) {
            WebSocketTools.makeHandshake(socket_, request);

            while (true) {
                try {
                    InputStream is  = socket_.getInputStream();
                    DataInputStream dis = new DataInputStream(is);
                    String wsRequest = WebSocketTools.getRequest(dis);

                    if (wsRequest.equals("close")) {
                        socket_.close();
                        break;
                    }

                    WebSocketTools.handleResponse(socket_, wsRequest);
                }
                catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
        }
        else {
            Response response = new Response(socket_, request);
            response.sendResponse();

            try {
                socket_.close();
            }
            catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}