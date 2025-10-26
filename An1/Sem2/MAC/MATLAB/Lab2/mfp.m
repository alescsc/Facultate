function xc = mfp(f, a, b, k)

fa = f(a);
fb = f(b);

if sign(fa)*sign(fb) > 0
    error('caz nestudiat')
end

for i = 1:k
    c = (b*f(a) - a*f(b))/(f(a) - f(b));
    fc = f(c);
    if fc == 0
        break;
    end
    if sign(fa)*sign(fc) < 0
        b = c;
        fb = fc;
    else
        a = c;
        fa = fc;
    end
end

xc = (a + b)/2;