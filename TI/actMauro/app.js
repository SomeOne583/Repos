var button = document.getElementById("boton");

button.onclick = function() {
        var p = document.createElement("button");
        document.body.appendChild(p);
        var l = prompt("Introduce letra");
        p.innerText = l;
}