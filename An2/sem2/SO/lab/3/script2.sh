if test $# -ne 1
then
    echo "Usage $0 files"
fi

if test ! -f $1
then
    echo "Fisier invalid"
fi



gcc -Wall -o prog $1 2> erori.txt

cat erori.txt | grep "Error"
cat erori.txt | grep "Warning"
