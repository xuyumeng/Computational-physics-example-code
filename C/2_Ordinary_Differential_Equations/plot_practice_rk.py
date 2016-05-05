import matplotlib.pyplot as plt
import numpy as np
import mpl_toolkits.mplot3d
from numpy import genfromtxt

my_data = genfromtxt('./data/p_rk.csv', delimiter=',')

fig = plt.figure()
ax = fig.add_subplot(111)

ax.plot(my_data[:,0],my_data[:,1],label='parametric curve')
ax.set_xlabel('x')
ax.set_ylabel('y')

plt.show()
