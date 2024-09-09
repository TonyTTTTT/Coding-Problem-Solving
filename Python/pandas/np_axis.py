import numpy as np
arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
row_sums = arr.sum(axis=1)
col_sums = arr.sum(axis=0)
result = np.max(row_sums) - np.min(col_sums)