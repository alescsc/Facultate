# script care primeste un unic argument un director (facem verificari)
# sa se parcurga fisierele din directorul dat ca parametru si sa se afiseze nr
# total de lini
# sa se genereze un output de forma:
# fisier 1 : nr linii
# fisier 2 : nr linii

if test $# -gt 1
then
    echo "Usage $0 arg"
    exit
fi

for fisier in "$1"/*.txt
do
    var=`basename $fisier`
    echo "$var : `$wc -l`"
done
