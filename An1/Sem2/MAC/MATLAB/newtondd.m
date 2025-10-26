function c = newtondd(x, y, n)
for j = 1:n
    v(j,1) = y(j);
end
for i = 2:n
    for j = 1 : n+1 - i
        v(j,i) = (v(j+1, i-1) - v(j, i-1))/(x(j+i-1) - x(j));
    end
end

for i = 1:n
    c(i) = v(1,i);
end