function rez = mijloccompus(f,a,b,m)

h = (b-a)/m;

for i=1:m+1
    x(i) = a + h(i-1);
end

rez = 0;

for i = 1:m
    mij(i) = (x(i)+x(i+1))/2;
    rez = rez + f(mij(i));
end

rez = h*rez;
end