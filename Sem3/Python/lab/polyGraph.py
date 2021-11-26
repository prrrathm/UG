import numpy as np
import matplotlib.pyplot as plt

def PolyCoefficients(x, coeffs):
    y = 0
    for i in range(len(coeffs)):
        y += coeffs[i]*x**i
    return y

x = np.linspace(-20, 20, 10)
coeffs = [-1,3,0,2]
c = [*range(-20,20)]
plt.plot(c, PolyCoefficients(c, coeffs))
plt.show()