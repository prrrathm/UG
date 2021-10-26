def input_matrix(n, matrix):
    for i in range(n):
        a = []
        for j in range(n):
            print("Enter [{0}] [{1}]: ".format(i, j), end="")
            a.append(int(input()))
        matrix.append(a)


def firstDiagonal(matrix, n):
    print("Principal Diagonal: ", end="")
    diag = []
    for i in range(n):
        diag.append(matrix[i][i])

    return diag


def secondDiagonal(matrix, n):
    print("Secondary Diagonal: ", end="")
    diag = []
    for i in range(n):
        for j in range(n):
            if ((i + j) == (n - 1)):
                diag.append(matrix[i][j])

    return diag

n = int(input("Enter the no of rows/columns (for sq. matrix):"))
matrix = []
input_matrix(n, matrix)
print(firstDiagonal(matrix, n))
print(secondDiagonal(matrix, n))