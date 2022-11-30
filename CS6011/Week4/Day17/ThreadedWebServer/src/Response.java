import java.io.*;
import java.net.Socket;
import java.nio.file.Files;

public class Response {
    private final Socket socket_;
    private final boolean isFileValid_;
    private String fileName_;
    private final String httpVersion_;
    private final Request request_;

    public Response(Socket socket, Request request) {
        socket_ = socket;
        request_ = request;
        isFileValid_ = request.getFileExists();
        fileName_ = request.getFileName();
        httpVersion_ = request.getHttpVersion();
    }

    private String getFilePath() {
        if (!isFileValid_) {
            fileName_ = "404NotFound.html";
        }

        return request_.getFilePath(fileName_);
    }

    private void sendResponseHeader(PrintWriter printWriter) {
        printWriter.println(getStatusCode());
        printWriter.println(getContentType());
        printWriter.println("");
    }

    private String getStatusCode() {
        String status = " 404 NOT FOUND";

        if (isFileValid_) {
            status = " 200 OK";
        }

        return httpVersion_ + status;
    }

    private String getContentType() {
        File file = new File(getFilePath());
        String fileContentType = "failed";

        try {
            fileContentType = Files.probeContentType(file.toPath());
        }
        catch (Exception e) {
            e.printStackTrace();
        }

        return "content-type: " + fileContentType;
    }

    private void sendResponseBody(OutputStream os) {
        try {
            InputStream finalFileStream = new FileInputStream(getFilePath());
            finalFileStream.transferTo(os);
            finalFileStream.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void sendResponse() {
        try {
            OutputStream os = socket_.getOutputStream();
            PrintWriter printWriter = new PrintWriter(os, true);
            sendResponseHeader(printWriter);

            Thread.sleep(1000);
            sendResponseBody(os);

            printWriter.close();
            os.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}