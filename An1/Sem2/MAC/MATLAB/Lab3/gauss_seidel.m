function x = gauss_seidel(A, b, x0, k)

D = diag(diag(A));
L = tril(A) - D;
U = triu(A) - D;

x = x0;

for i = 0:k
    x = inv(D)*(b-U*x0 - L*x);
    x0 = x;
end
