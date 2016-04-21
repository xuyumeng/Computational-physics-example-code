import matplotlib.pyplot as plt
import numpy as np
import mpl_toolkits.mplot3d
from numpy import genfromtxt

my_data = genfromtxt('lorentz.csv', delimiter=',')

fig = plt.figure()
ax = fig.gca(projection='3d')

ax.plot(my_data[:,0],my_data[:,1],my_data[:,2],label='parametric curve')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')

plt.show()
