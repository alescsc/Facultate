function rez = simpsoncompus(f,a,b,m)

rez = 0;
h = (b-a)/(2*m);

for i = 1:2*m+1
    x(i)=a+h*(i-1);
    y(i)=f(x(i));
    if((i == 1) || (i == 2*m+1))
        rez = rez + y(i);
    end
end

for i = 1:m
    rez = rez + 4*y(2*i);
end

for i = 1:m-1
    rez = rez + 2*y(2*i+1);
end

rez = (h/3)*rez;
end