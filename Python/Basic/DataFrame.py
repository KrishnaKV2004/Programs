# pandas is a library we import for Data Analysis

import pandas as pd
import numpy as np

list = [[2,4,6],[3,5,7],[1,2,3]]

df = pd.DataFrame(list,index=['Row 1','Row 2','Row 3'])

print(df)