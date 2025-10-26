function xc = bisectiei(f, a, b, tol)

fa = f(a);
fb = f(b);

if sign(fa)*sign(fb) >= 0
    error('fa*fb < 0 nesatisfacut');
end

while fa*fb < 0
    c = (a + b)/2;
    fc = f(c);
    if fc == 0
        break;
    end
    if sign(fa)*sign(fb) < 0
        b = c;
        fb = fc;
    else
        a = c;
        fa = fc;
    end
end
xc = (a + b)/2;