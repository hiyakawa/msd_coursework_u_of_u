function main() {
    let ws = new WebSocket("ws://localhost:8080");

    ws.onopen = handleOpen;
    ws.close = handleClose;
    ws.onerror = handleError;
    ws.onmessage = handleMsg;

    document.getElementById("chatform").addEventListener("submit", function(event) {
        event.preventDefault();
    
        let message_element = document.getElementsByTagName("input")[0];
        let message = message_element.value;
    
        if (message.toString().length) {
            let username = localStorage.getItem("username");
    
            let data = {
                type: "message",
                username: username,
                message: message
            };
    
            ws.send(JSON.stringify(data));
            message_element.value = "";
        }
    }, false);

    // Username();
}

window.onload = main;

function handleOpen(event) {
    MessageAdd('<div class="message green">You have entered the chat room.</div>');
}

function handleClose(event) {
	MessageAdd('<div class="message blue">You have been disconnected.</div>');
}

function handleError(event) {
	MessageAdd('<div class="message red">Connection to chat failed.</div>');
}

function handleMsg(event) {
    let msg = event.data;
    let msgData = JSON.parse(msg);

    if (msgData.type == "message") {
        MessageAdd('<div class="message">' + data.username + ': ' + data.message + '</div>');
    }
}

// function Username() {
// 	let username = window.prompt("Enter your username:", "");
//     localStorage.setItem("username", username);
// }

function MessageAdd(message) {
	let chat_messages = document.getElementById("chatmsg");

	chat_messages.insertAdjacentHTML("beforeend", message);
	chat_messages.scrollTop = chat_messages.scrollHeight;
}