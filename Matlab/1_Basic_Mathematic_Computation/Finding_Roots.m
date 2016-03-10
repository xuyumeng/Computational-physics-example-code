syms x y a b c
y = solve('a*x^2+b*x+c=0','x')

y = solve('x^2-5=0')
vpa(y,10)

f = @(x) x^2-5;
x = fzero(f,1)


