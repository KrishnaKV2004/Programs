import pandas as pd
import numpy as np

ser_1 = pd.Series([1,3,5,7,9])
ser_2 = pd.Series([2,4,6,8,10])

a = ser_1 + ser_2
b = ser_1 - ser_2
c = ser_1 * ser_2
d = ser_1 / ser_2

print(a)
print(b)
print(c)
print(d)