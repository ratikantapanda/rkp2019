import numpy as np
import matplotlib.pyplot as plt
cvalues = [20.1, 20.8, 21.9, 22.5, 22.7, 22.3, 21.8, 21.2, 20.9, 20.1]
c= np.array(cvalues)
f=c*9/5 + 32
plt.plot(c)
plt.show()