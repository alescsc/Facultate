function x = jacobi(A, b, x0, k)
% A - matricea
% b - termenii liberi
% x0 - valoarea initiala a lui x0 (o aproximare)
% k - nr max de iteratii

D = diag(diag(A)); % matr diagonala a lui A

L = tril(A) - D; % partea inferioara a lui A

U = triu(A) - D; % partea superioara a lui A

x = x0; % se seteaza x cu valoarea initiala

for j = 1:k
    x = inv(D) * (b - (L + U) * x); % se calculeaza valoarea aproximativa
    % a lui x facand k iteratii
end