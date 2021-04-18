#!/bin/bash
tmpfile=$(mktemp)
./a.out $1 > $tmpfile
if [ "$2" = 'pdf' ];
then
    pandoc $tmpfile -o output.pdf
else
    pandoc -f markdown -t docx $tmpfile -o output.docx
fi
