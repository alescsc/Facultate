function x = broyden1(F, x0, k)
n = length(x0);
x = x0;
A = eye(n, n);

for i = 1:k
    x = x0 - inv(A)*F(x0);
    delta = x - x0;
    Delta = F(x) - F(x0);
    A = A + ((Delta - A*delta)*delta')/(delta'*delta);
    x0 = x;
end