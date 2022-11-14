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
            Map<String, String> jsonMsg = WebSocketTools.parseJSON(curMsg);
            jsonMsgs_.add(jsonMsg);
        }
    }

//    private static synchronized boolean roomExists(String roomName) {
//        for (Room curRoom : rooms_) {
//            if (curRoom.getRoomName().equals(roomName)) {
//                return true;
//            }
//        }
//
//        return false;
//    }

    // using factory pattern
    public static synchronized Room getRoom(String roomName) throws IOException {
        for (Room curRoom : rooms_) {
            if (curRoom.getRoomName().equals(roomName)) {
                return curRoom;
            }
        }

//        if (roomExists(roomName)) {
//            for (Room curRoom : rooms_) {
//                if (curRoom.getRoomName().equals(roomName)) {
//                    return curRoom;
//                }
//            }
//        }

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

//    private boolean isUserInRoom(String user) {
//        return activeUsers.contains(user);
//    }

//    public static synchronized Room getRoomByUser(String user)
//    {
//        for (Room room: rooms_) {
//            if(room.isUserInRoom(user))
//            {
//                return room;
//            }
//        }
//        throw new RuntimeException("User " + user +" is not in any room!");
//    }

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

    public String getRoomName() {
        return roomName_;
    }

}