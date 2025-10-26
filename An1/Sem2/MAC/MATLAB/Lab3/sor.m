function x = sor(A, b, x0, omega, k)

D = diag(diag(A));
L = tril(A) - D;
U = triu(A) - D;

x = x0;
for i = 0:k
    x = inv(omega * L + D)*((1-omega)*D*x0 - omega*U*x0) + omega*inv(D + omega*L)*b;
    x0 = x;
end