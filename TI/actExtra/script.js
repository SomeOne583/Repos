var tab1 = document.getElementById("tab1");
var tab2 = document.getElementById("tab2");
var tab3 = document.getElementById("tab3");
var tab4 = document.getElementById("tab4");
var tab5 = document.getElementById("tab5");

tab2.style.display = "none";
tab3.style.display = "none";
tab4.style.display = "none";
tab5.style.display = "none";

var tab1B = document.getElementById("tab1B");
var tab2B = document.getElementById("tab2B");
var tab3B = document.getElementById("tab3B");
var tab4B = document.getElementById("tab4B");
var tab5B = document.getElementById("tab5B");

tab1B.onclick = function() {
        tab1.style.display = "block";
        tab1B.style.border = "solid";
        tab2.style.display = "none";
        tab2B.style.border = "none";
        tab3.style.display = "none";
        tab3B.style.border = "none";
        tab4.style.display = "none";
        tab4B.style.border = "none";
        tab5.style.display = "none";
        tab5B.style.border = "none";
}

tab2B.onclick = function() {
        tab1.style.display = "none";
        tab1B.style.border = "none";
        tab2.style.display = "block";
        tab2B.style.border = "solid";
        tab3.style.display = "none";
        tab3B.style.border = "none";
        tab4.style.display = "none";
        tab4B.style.border = "none";
        tab5.style.display = "none";
        tab5B.style.border = "none";
}

tab3B.onclick = function() {
        tab1.style.display = "none";
        tab1B.style.border = "none";
        tab2.style.display = "none";
        tab2B.style.border = "none";
        tab3.style.display = "block";
        tab3B.style.border = "solid";
        tab4.style.display = "none";
        tab4B.style.border = "none";
        tab5.style.display = "none";
        tab5B.style.border = "none";
}

tab4B.onclick = function() {
        tab1.style.display = "none";
        tab1B.style.border = "none";
        tab2.style.display = "none";
        tab2B.style.border = "none";
        tab3.style.display = "none";
        tab3B.style.border = "none";
        tab4.style.display = "block";
        tab4B.style.border = "solid";
        tab5.style.display = "none";
        tab5B.style.border = "none";
}

tab5B.onclick = function() {
        tab1.style.display = "none";
        tab1B.style.border = "none";
        tab2.style.display = "none";
        tab2B.style.border = "none";
        tab3.style.display = "none";
        tab3B.style.border = "none";
        tab4.style.display = "none";
        tab4B.style.border = "none";
        tab5.style.display = "block";
        tab5B.style.border = "solid";
}
