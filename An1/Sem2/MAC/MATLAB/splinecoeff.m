function coeff = splinecoeff(x,y)

n = length(x);
A = zeros(n,n);
r = zeros(n,1);

for i = 1:n-1
    dx(i) = x(i+1) - x(i);
    dy(i) = y(i+1) - y(i);
end

for i = 2:n-1
    A(i, i-1:i+1) = [dx(i-1) 2*(dx(i-1)+dx(i)) dx(i)];
    r(i) = 3*(dy(i)/dx(i) - dy(i-1)/dx(i-1));
end

A(1,1) = 1;
A(n,n) = 1;

coeff = zeros(n,3);
coeff(:,2)=A\r;

for i = 1:n-1
    coeff(i,3) = (coeff(i+1,2) - coeff(i,2))/(3*dx(i));
    coeff(i,1) = dy(i)/dx(i) - dx(i)*(2*coeff(i,2) + coeff(i+1,2))/3;
end

coeff = coeff(1:n-1,1:3);