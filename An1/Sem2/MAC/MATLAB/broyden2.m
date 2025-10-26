function x = broyden2(F, x0, k)

% F - functie care reprezinta sistemul de ecuatii liniare
% x0 - aproximarea initiala a solutiei
% k - nr max de iteratii

n = length(x0); % determina dimensiunea sistemului (nr de variabile necunoscute)

B = eye(n,n); % aproximarea initiala a inversului Jacobianului, setata
% initial ca matricea identitate

for i = 1 : k
    x = x0 - B * F(x0); % se calculeaza noua aproximare a solutiei
    delta = x - x0
    Delta = F(x) - F(x0);
    B = B + (delta - B * Delta) * delta' * B / (delta' * B * Delta);
    % formula de actualizare Broyden pentru inversa aproximata a
    % Jacobianului
    
    x0 = x;
end