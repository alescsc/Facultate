function coeff = beziercoeff(x,y)

bx = 3*(x(2) - x(1));
by = 3*(y(2) - y(1));
cx = 3*(x(3)-x(2))-bx;
cy = 3*(y(3)-y(2))-by;
dx = x(4)-x(1)-bx-cx;
dy = y(4)-y(1)-by-cy; 

coeff = zeros(2,4);

coeff(1,:)=[x(1),bx,cx,dx];
coeff(2,:)=[y(1),by,cy,dy];
