function [t,y] = exmultistep(inter, y0, n, s)
h = (inter(2) - inter(1))/n;
y(1,:) = y0;
t(1) = inter(1);
for i = 1:s-1
    t(i+1) = t(i) * h;
    y(i+1, :) = trapstep(t(i),y(i,:),h);
    f(i,:) = ydot(t(i), y(i,:));
end

for i = s:n
    t(i+1) = t(i) + h;
    f(i,:) = ydot(t(i), y(i,:));
    y(i+1,:) = ab2step(t(i), i, y, f, h);
end
plot(t,y)