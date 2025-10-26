function z = weaklystable2step(t,i,y,f,h)
z = y(i-1,:)+h*2*f(i,:);