function x = conjgrad(A, b, x0, k)

x = x0;
r = b - A * x;
d = r;

for i = 1:k
    if r == 0
        break;
    end
    alfa = (r' * r)/(d' * A * d);
    x = x + alfa*d;
    r_nou = r - alfa * A * d;
    beta = (r_nou' * r_nou)/(r' * r);
    d = r_nou + beta*d;
    r = r_nou;
end
