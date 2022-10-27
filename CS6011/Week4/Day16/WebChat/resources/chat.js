let ws = new WebSocket("ws://localhost:8080");
ws.onopen = handleOpen;
ws.close = handleClose;
ws.onerror = handleError;
ws.onmessage = handleMsg;

function handleMsg(event) {
    let msg = event.data;
    
}

