function [A,x] = gauss(A, b)
% A este sistemul, b este coloana termenilor liberi
n = length(A); % dimensiunea matricii A

for j = 1: n-1
    if abs(A(j,j)) == 0 % verificam daca pivotul principal A(j,j) este zero
        error('zero pivot encountered!') % daca da, atunci algoritmul se 
        % opreste si afiseaza un mesaj de eroare
    end
    for i = j + 1: n
        mult = A(i,j) / A(j,j); % se calculeaza factorul de multiplicare 
        % care va fi folosit pentru a elimina elementele de sub pivot
        for k = j: n
            A(i,k) = A(i,k) - mult * A(j,k); % se elimina fiecare element
            % prin eliminarea contributiei pivotului
        end
        b(i) = b(i) - mult * b(j); % se aplica aceeasi operatie si asupra
        % vectorului termenilor liberi b
    end
end

for i = n: -1: 1 % se rezolva sistemul de ecuatii invers
    for j = i + 1: n
        b(i) = b(i) - A(i,j) * x(j); % se ajusta termenul liber scazand 
        % contributia necunoscutelor deja eliminate
    end
    x(i) = b(i)/A(i,i); % se determina valoarea necunoscutei x(i)
end

