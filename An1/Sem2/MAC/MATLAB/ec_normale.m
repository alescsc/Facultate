function x = ec_normale(A, b)

x = (A' * A)\(A' * b);

r = b-A*x;

norma = norm(r);

disp(x);
disp(norma);