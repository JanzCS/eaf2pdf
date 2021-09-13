#!/bin/bash
tmpfile=$(mktemp)
./eaf2pdf $1 > $tmpfile
if [ "$2" = 'pdf' ];
then
    pandoc $tmpfile -o output.pdf
else
    pandoc -f markdown -t docx $tmpfile -o output.docx --lua-filter=pagebreak.lua
fi
