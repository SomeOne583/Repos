#!/bin/sh
carpeta='.'
problema=''
modo='2'
input=false
output=false
tiempo=false

print_usage() {
        printf "Uso:\n-f\tIndica el directorio donde esta el archivo\n-p\tIndica el nombre del problema (no es necesario el cpp)\n-i\tIndica que habrá un archivo de entrada con el mismo nombre\n-o\tIndica que se va a generar un archivo de salida con el mismo nombre\n-h\tImprime este mensaje de ayuda\n"
}

while getopts 'f:p:s:ioth' flag; do
case "${flag}" in
f) carpeta=./$OPTARG ;;
p) problema=${OPTARG} ;;
s) modo=${OPTARG} ;;
i) input=true ;;
o) output=true ;;
t) tiempo=true ;;
h) print_usage ;;
esac
done

g++ "$carpeta/$problema.cpp" "-O$modo"

if $tiempo
then
if $input && $output
then
time ./a.out < "./inputs/$problema.in" > "./outputs/$problema.o"
elif $input
then
time ./a.out < "./inputs/$problema.in"
elif $output
then
time ./a.out > "./outputs/$problema.o"
else
time ./a.out
fi
else
if $input && $output
then
./a.out < "./inputs/$problema.in" > "./outputs/$problema.o"
elif $input
then
./a.out < "./inputs/$problema.in"
elif $output
then
./a.out > "./outputs/$problema.o"
else
./a.out
fi
fi

rm a.out
