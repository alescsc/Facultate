function x = broyden2(F, x0, k)

n = length(x0);
B = eye(n, n);

for i=1:k
    x = x0 - B * F(x0);
    delta = x - x0;
    Delta = F(x) - F(x0);
    B = B + (delta-B*Delta)*delta'*B/(delta'*B*Delta);
    x0 = x;
end

