function xc = secantei(f, x0, x1, k)

x(1) = x0;
x(2) = x1;

for i = 2:k
    x(i + 1) = x(i) - (f(x(i))*(x(i) - x(i-1)))/(f(x(i)) - f(x(i - 1)));
end

xc = x(k + 1);