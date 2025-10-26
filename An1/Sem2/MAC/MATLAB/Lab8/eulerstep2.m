function y = eulerstep2(t,y,h)
y = y + h * ydot(t,y);
