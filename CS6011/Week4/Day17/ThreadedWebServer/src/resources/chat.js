"use strict";

function main() {
    let ws = new WebSocket("ws://localhost:8080");

    // let name = document.getElementById("nameform");
    // let room = document.getElementById("roomform");
    //
    // name.addEventListener("submit", handleKeyPressCB);
    // room.addEventListener("submit", handleKeyPressCB);

    // ws.onopen = handleOpen;
    // ws.close = handleClose;
    // ws.onerror = handleError;
    // ws.onmessage = handleMsg;
}

function handleKeyPressCB (event) {
    console.log(event.data);
    // event.preventDefault();

    // let message_element = document.getElementsByTagName("input")[0];
    // let message = message_element.value;

    // if (message.toString().length) {
    //     let username = localStorage.getItem("username");

    //     let data = {
    //         type: "message",
    //         username: username,
    //         message: message
    //     };

    //     ws.send(JSON.stringify(data));
    //     message_element.value = "";
}

window.onload = main;

function handleLoad() {
    console.log("Web socket is open.")
}

// function handleOpen(event) {
//     MessageAdd('<div class="message green">You have entered the chat room.</div>');
// }

// function handleClose(event) {
// 	MessageAdd('<div class="message blue">You have been disconnected.</div>');
// }

// function handleError(event) {
// 	MessageAdd('<div class="message red">Connection to chat failed.</div>');
// }

// function handleMsg(event) {
//     let msg = event.data;
//     let msgData = JSON.parse(msg);

//     if (msgData.type == "message") {
//         MessageAdd('<div class="message">' + data.username + ': ' + data.message + '</div>');
//     }
// }


// function MessageAdd(message) {
// 	let chat_messages = document.getElementById("chatmsg");

// 	chat_messages.insertAdjacentHTML("beforeend", message);
// 	chat_messages.scrollTop = chat_messages.scrollHeight;
// }