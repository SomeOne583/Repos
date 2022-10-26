var diasp = document.getElementById("dias");
var horasp = document.getElementById("horas");
var minutosp = document.getElementById("minutos");
var segundosp = document.getElementById("segundos");
var examen = Date.parse("6 Nov 2022 16:00:00 GMT");

setInterval(actualizar, 1000);

function actualizar() {
        var ahora = Date.now()
        var espera = examen - ahora;
        var dias = Math.floor(espera / (24 * 60 * 60 * 1000));
        espera = espera % (24 * 60 * 60 * 1000);
        var horas = Math.floor(espera / (60 * 60 * 1000));
        espera = espera % (60 * 60 * 1000);
        var minutos = Math.floor(espera / (60 * 1000));
        espera = espera % (60 * 1000);
        var segundos = Math.floor(espera / 1000);

        diasp.innerText = dias + (dias == 1 ? " día" : " días");
        horasp.innerText = horas + (horas == 1 ? " hora" : " horas");
        minutosp.innerText = minutos + (minutos == 1 ? "minuto" : " minutos");
        segundosp.innerText = segundos + (segundos == 1 ? " segundo" : " segundos");
}