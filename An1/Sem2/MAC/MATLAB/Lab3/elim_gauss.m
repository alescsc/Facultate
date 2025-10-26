function [A,x] = elim_gauss(A,b)

n = length(A)

for j = 1:n - 1
    if abs(A(j,j)) == 0
        break;
    end
    for i = j + 1:n
        for k = j + 1:n
            A(i,k) = A(i,k) - (A(i,j)/A(j,j))*A(j,k);
        end
        b(i) = b(i) - (A(i,j)/A(j,j))*b(j);
    end
end

for i = n:-1:1
    for j = i + 1:n
        b(i) = b(i) - A(i,j)*x(j);
    end
    x(i) = b(i) / A(i,i);
end
