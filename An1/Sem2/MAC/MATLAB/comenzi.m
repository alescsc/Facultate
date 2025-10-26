%COMENZI LABURI

%lab 1

%lab 2

%lab 3

%FACTORIZAREA PA = LU
A = [2 1 5; 4 4 -4; 1 3 1];
[L,U,P] = lu(A);
b = [9; -8; 4];
x = A\b

x0 = zeros(3,1) % creeaza o matrice de 3 linii si o coloana de zerouri

A=[4 -2 2; -2 2 -4; 2 -4 11];
A == A' % verificare daca matricea este egala cu transpusa sa

eig(A) % returneaza valorile proprii ale matricei

chol(A) % factorizarea Cholesky

F=@(x) [x(2)-x(1)^3;x(1)^2+x(2)^2-1];

x = fsolve(F,[1;1]) % comanda pt rezolvarea sistemelor neliniare