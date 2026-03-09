#adauga nr mai mari decat 100 date ca argumente


if test $# -lt 2
then
    echo "Usage $0 arg1 arg2 ..."
    exit
fi

var=0
sum=0

for arg
do
    if test $arg -ge 100
       then
	   var=`expr $var + $arg`
	   nr=$arg
	   while test $nr -gt 0
	   do
	       sum=`expr $sum + 1`
	       nr=`expr $nr / 10`
	   done
    fi
done
echo $var > "out.txt"
echo $sum >> "out.txt"
