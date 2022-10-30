"use strict";

let xTA = document.getElementById("xTA");
let yTA = document.getElementById("yTA");
let resultTA = document.getElementById("resultTA");
let wsResultTA = document.getElementById("wsResultTA");
let button = document.getElementById("addBtn");
let wsOpen = false;
let ws = new WebSocket("ws://localhost:8080");

xTA.addEventListener("keypress", handleKeyPressCB);
yTA.addEventListener("keypress", handleKeyPressCB);
button.addEventListener("click", handleKeyPressCB);

ws.onopen = handleConnectCB;
ws.onmesssage = handleMessageFromWsCB;

function handleKeyPressCB(event) {
    if (event.type == "click" || event.keyCode == 13) {
        let x = parseFloat(xTA.value);
        let y = parseFloat(yTA.value);

        if (isNaN(x)) {
            alert("x has to be a number");
            xTA.value = "<Enter a number>";
            xTA.select();
            return;
        }

        if (isNaN(y)) {
            alert("y has to be a number");
            yTA.value = "<Enter a number>";
            yTA.select();
            return;
        }

        let request = new XMLHttpRequest();
        request.open("GET", "http://localhost:8080/calculate?x=" + x + "&y=" + y);
        request.addEventListener("error", handleAjaxErrorCB);
        request.addEventListener("load", handleAjaxSuccessCB);
        request.send();

        if (wsOpen) {
            ws.send(x + " " + y);
        }
        else {
            wsResultTA.value = "WS is not open...";
        }
    }
}

function handleAjaxErrorCB() {
    console.log("An ajax error occurred");
    resultTA.value = "Server has a problem...";
}

function handleAjaxSuccessCB() {
    console.log("Got a response from the server");
    resultTA.value = this.responseText;
}

function handleConnectCB() {
    wsOpen = true;
}

function handleMessageFromWsCB(event) {
    wsResultTA.value = event.data;
}