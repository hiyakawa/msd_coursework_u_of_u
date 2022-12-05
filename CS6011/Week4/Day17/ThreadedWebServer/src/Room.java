import java.net.Socket;
import java.io.IOException;
import java.util.*;

public class Room {
    private final String roomName_;
    private final Set<String> activeUsers;
    private final Set<Socket> activeSockets;
    private static final Set<Room> rooms_ = new HashSet<>();
    private final ArrayList<Map<String, String>> jsonMsgs_;

    private Room(String roomName) throws IOException {
        roomName_ = roomName;
        activeUsers = new HashSet<>();
        activeSockets = new HashSet<>();
        jsonMsgs_ = new ArrayList<>();
        readMessageQueueFromMemory();
    }

    private void readMessageQueueFromMemory() throws IOException {
        ArrayList<String> msgs = PersistentMemoryTools.getMessageHistoryOfRoom(roomName_);

        for (String curMsg: msgs) {
            Map<String, String> jsonMsg = HandlerRunnable.parseJSON(curMsg);
            jsonMsgs_.add(jsonMsg);
        }
    }

    public static synchronized Room getRoom(String roomName) throws IOException {
        // using factory pattern
        for (Room curRoom : rooms_) {
            if (curRoom.roomName_.equals(roomName)) {
                return curRoom;
            }
        }

        Room room = new Room(roomName);
        rooms_.add(room);

        return room;
    }

    public synchronized void addUser(String user) {
        if (activeUsers.contains(user)) {
            throw new RuntimeException();
        }

        activeUsers.add(user);
    }

    public synchronized void removeUser(String user) {
        activeUsers.remove(user);
    }

    public synchronized void addSocket(Socket socket) {
        activeSockets.add(socket);
    }

    public synchronized void removeSocket(Socket socket) {
        activeSockets.remove(socket);
    }

    public synchronized Set<Socket> getActiveSockets() {
        return activeSockets;
    }

    public synchronized void addMessage(Map<String, String> message) throws IOException {
        jsonMsgs_.add(message);
        PersistentMemoryTools.addMessageToMemoryFile(message);
    }

    public synchronized ArrayList<Map<String, String>> getMessageQueue() {
        return jsonMsgs_;
    }

    public boolean userExistsInCurRoom(String user) {
        return activeUsers.contains(user);
    }
}