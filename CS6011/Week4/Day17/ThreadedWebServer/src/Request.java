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
    private String httpVersion_;
    private String key_;
    private boolean fileExists_;
    private boolean isWS_ = false;

    public Request(Socket clientSocket) {
        clientSocket_ = clientSocket;
    }

    public String getFilePath(String fileName) {
        return "/Users/laurazhang/myLocalGithubRepo/CS6011/Week4/Day17/ThreadedWebServer/src/resources/" + fileName;
    }

    public void getRequest() {
        InputStream requestStream = null;

        try {
            requestStream = clientSocket_.getInputStream();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        assert requestStream != null;
        Scanner sc = new Scanner(requestStream, StandardCharsets.UTF_8);

        if (sc.hasNextLine()) {
            readHeader(sc);
        }
    }

    private void readHeader(Scanner sc) {
        String firstLine = sc.nextLine();
        System.out.println(firstLine + " from thread " + Thread.currentThread().threadId());

        String[] firstLineWords = firstLine.split("\s");

        fileName_ = firstLineWords[1];
        File file = new File(getFilePath(fileName_));
        fileExists_ = file.exists() && (!file.isDirectory());

        httpVersion_ = firstLineWords[2];

        while (sc.hasNextLine()) {
            String pair = sc.nextLine();

            if (pair.isEmpty()) {
                break;
            }

            String[] pairs = pair.split(": ");
            String key = pairs[0];
            String value = pairs[1];
            requestHeader_.put(key, value);
        }

        isWS_ = WebSocketTools.isWebSocket(requestHeader_);

        if (isWS_) {
            key_ = requestHeader_.get("Sec-WebSocket-Key");
        }

        // reference: https://stackoverflow.com/questions/5920135/printing-hashmap-in-java
        requestHeader_.forEach((key, value) -> System.out.println(key + " : " + value));
    }

    public String getKey() {
        if (!isWS_) {
            throw new RuntimeException();
        }

        return key_;
    }

    public boolean getIsWS() {
        return isWS_;
    }

    public boolean getFileExists() {
        return fileExists_;
    }

    public String getFileName() {
        return fileName_;
    }

    public String getHttpVersion() {
        return httpVersion_;
    }
}