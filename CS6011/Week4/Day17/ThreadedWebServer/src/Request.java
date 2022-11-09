import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Request {
    private final Socket clientSocket_;
    private final Map<String, String> requestHeader_ = new HashMap<>();
    private String fileName_;
    private boolean fileExists_;
    private String httpVersion;
    private boolean isWSProtocol_ = false;
    private String WSRequestKey_;

    public Request(Socket clientSocket) {
        clientSocket_ = clientSocket;
    }

    public String getFilePath(String fileName) {
        return "/resources/" + fileName;
    }

    private void checkIfFileExists() {
        File file = new File(getFilePath(fileName_));
        fileExists_ = file.exists() && !file.isDirectory();
    }

    private void printKeyValueMap() {
        requestHeader_.forEach((key, value) -> System.out.println(key + " : " + value));
    }

    private void readRequestHeader(Scanner requestHeaderScanner) {
        // read the first line for the fileName
        // e.g. GET /tutorials/other/top-20-mysql-best-practices/ HTTP/1.1
        String GETInfo = requestHeaderScanner.nextLine();
        System.out.println(GETInfo + " thread: " + Thread.currentThread().threadId());
        String[] GETInfoArray = GETInfo.split("\s");
        fileName_ = GETInfoArray[1];
        checkIfFileExists();
        httpVersion = GETInfoArray[2];
        System.out.println(GETInfo);
        // keep reading the following key-value pairs and store them in requestHeader
        while (requestHeaderScanner.hasNextLine()) {
            // e.g. Host: localhost
            String keyValueString = requestHeaderScanner.nextLine();
            // end at the blank line
            if (keyValueString.isEmpty()) {
                break;
            }
            String[] keyValuePair = keyValueString.split(": ");
            String key = keyValuePair[0];
            String value = keyValuePair[1];
            requestHeader_.put(key, value);
        }
        isWSProtocol_ = WebSocketTools.isWebSocket(requestHeader_);
        if (isWSProtocol_) {
            WSRequestKey_ = requestHeader_.get("Sec-WebSocket-Key");
        }
        printKeyValueMap();
    }

    public Boolean getIsFileValid() {
        return fileExists_;
    }

    public String getFileName() {
        return fileName_;
    }

    public String getHttpVersion() {
        return httpVersion;
    }

    public void getRequest() {
        InputStream requestStream = null;
        try {
            requestStream = clientSocket_.getInputStream();
        } catch (IOException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
        assert requestStream != null;
        Scanner requestHeaderScanner = new Scanner(requestStream, StandardCharsets.UTF_8);
        if (requestHeaderScanner.hasNextLine()) {
            readRequestHeader(requestHeaderScanner);
        }
    }

    public boolean getIsWebSocket() {
        return isWSProtocol_;
    }

    public String getWSRequestKey() {
        if (!isWSProtocol_) {
            throw new RuntimeException("This is not a web socket!");
        }
        return WSRequestKey_;
    }
}