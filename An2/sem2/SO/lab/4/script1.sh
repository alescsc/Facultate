# citeste continu linii de la tastatura si verifica daca sunt prop corecte
# o prop e corecta daca incepe cu litera mare, este urmata de oricate litere mari/mici, virgule, cifre, spatii, se termina cu punct/semnul intrebari/semnul exclamari si nu este permisa folosirea virgulei inainte de si
# daca prop e corecta atunci o afiseaza, altfel afiseaza mesajul "EROARE"

while read line
do
    result=` echo $line | grep -E "^[A-Z][A-Za-z,0-9 ]*[\.\?!]$" | grep -v ", si"`
    if test -z "$result"
    then
	echo "Eroare"
    else
	echo $line
    fi
done

		 


