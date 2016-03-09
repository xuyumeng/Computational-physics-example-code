clc;
syms x y;
syms f_1 f_2 f_3;
syms q_1 q_2;

f_1 = int('sin(x)*x',x)
f_2 = int('sin(x)*y',x)
f_3 = int('4',x)

q_1 = int('x^3+sin(x)',x,1,3)
vpa(q,10)

f = @(x) x.^3+sin(x);
q_2 = quad(f,1,3)
