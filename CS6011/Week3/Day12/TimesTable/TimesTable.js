"use strict";

let html = '<table border="1">';

for (let i = 0; i < 11; i++) {
    const label = i === 0 ? "" : i;
    html += `<tr><td>${label}</td>`;
    const multipler = i === 0 ? 1 : i;
    
    for (let j = 1; j < 11; j++) {
        html += `<td>${multipler * j}</td>`;
    }
    
    html += "</tr>";
}

document.getElementById("tablez").innerHTML = html + '</table>';
