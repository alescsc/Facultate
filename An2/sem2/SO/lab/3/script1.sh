if test $# -ne 1
then
    echo "Usage $0 directors"
fi

if test ! -d $1
then
    echo "Director invalid"
    exit 2
fi

find "$1" -type f -printf "%s %p\n" | sort -nr | head -5 | while read filesize filename
do
    echo `basename $filename` : $filesize bytes
done
# %s file size
# %p file name

# sa se scrie un script care primeste ca si argument un fisier C
# verificare nr argumente + fisier obisnuit
# se va compila fisierul C
# se va calcula o nota pe baza numarului de warnings si erori

# se va furniza un director ca argument
# se va genera un fisier de iesire cu nume note.txt care va contine pe fiecare linie nr fisier si nota
