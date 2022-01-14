#!/bin/bash
tmpfile=$(mktemp)
g++ -std=c++17 -pthread -o eaf2pdf sacgenerator.cpp
./eaf2pdf $1 > $tmpfile
if [ "$2" = 'pdf' ];
then
    pandoc $tmpfile -o output.pdf
else
    pandoc -f markdown -t docx $tmpfile -o output.docx --lua-filter=pagebreak.lua
fi
rm eaf2pdf
