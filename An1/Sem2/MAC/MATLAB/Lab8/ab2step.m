function z = ab2step(t,i,y,f,h)
z = y(i,:)+h*(3*f(i,:)/2-f(i-1,:)/2);