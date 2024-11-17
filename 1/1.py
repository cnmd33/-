""""
请编写一个 Python 程序，计算给定矩阵的逆矩阵。要求程序能够读取一个 n x n 的矩阵，并计算其逆矩阵。如果矩阵不可逆，则输出相应的提示信息。
1. **输入**：输入矩阵的维度n，从标准输入一个 n x n 的矩阵，矩阵元素为浮点数。
2. **输出**：输出矩阵的逆矩阵，若矩阵不可逆，则输出 "矩阵不可逆"。
输入:
3
1 2 3
0 1 4
5 6 0
输出
-24.0  18.0   5.0
 20.0 -15.0  -4.0
 -5.0   4.0   1.0
输入
2
1 2
2 4
输出
矩阵不可逆
"""

import numpy as np

n = int(input())
matrix = []
for i in range(n):
    matrix.append(list(map(float, input().split())))
matrix = np.array(matrix)

if np.linalg.det(matrix) == 0:
    print("矩阵不可逆")
else:
    inv_matrix = np.linalg.inv(matrix)
    np.set_printoptions(formatter={'float': '{: .1f}'.format})
    print(np.array2string(inv_matrix, separator=' ', suppress_small=True, max_line_width=np.inf).replace('[', '').replace(']', ''))