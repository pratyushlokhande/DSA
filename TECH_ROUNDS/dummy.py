import sys

# get all subsequences of a list


def get_subsequences(lst):
    if len(lst) == 0:
        return [[]]
    else:
        return [lst[0:1] + rest for rest in get_subsequences(lst[1:])] + get_subsequences(lst[1:])


def maxLen(N, D, A):
    max_len_subsequence = 1
    for subsequence in get_subsequences(A):
        flag = True
        for i in range(len(subsequence)-1):
            if(abs(subsequence[i+1] - subsequence[i]) < D):
                flag = False
        if flag:
            max_len_subsequence = max(max_len_subsequence, len(subsequence))
    return max_len_subsequence


lst = [1, 2, 3]
d = 1
n = int(sys.stdin.readline().strip())
d = int(sys.stdin.readline().strip())
A = list(map(int, sys.stdin.readline().strip().split()))
print(maxLen(n, d, A))


# # N hungary students
# # m types of dishes
# # Ai dishes of type i
# # favourite dish of each student represented by matrix B of size Nxm
# # B[i][j] = 1 if student i likes dish j
# # find total way to choose exaactly 1 dish for each student
# # if there is no solution return -1

# # total was to select 1 dish for each student
# def get_total_ways(N, M, A, B):
#     # create a matrix of size NxM
#     # each row represents a student
#     # each column represents a dish
#     matrix = [[0 for i in range(M)] for j in range(N)]
#     # fill the matrix with the number of ways to select a dish for each student
#     for i in range(N):
#         for j in range(M):
#             if B[i][j] == 1:
#                 matrix[i][j] = A[j]
#     # for each student, find the maximum number of ways to select a dish
#     for i in range(N):
#         max_value = 0
#         for j in range(M):
#             max_value = max(max_value, matrix[i][j])
#         # if the maximum number of ways is 0, there is no way to select a dish for this student
#         if max_value == 0:
#             return -1
#         # otherwise, subtract the maximum number of ways from the number of ways to select a dish for each student
#         for j in range(M):
#             matrix[i][j] -= max_value
#     # find the total number of ways to select a dish for each student
#     total_ways = 0
#     for i in range(N):
#         total_ways += matrix[i][0]
#     return total_ways


# print(type(int("1")))

# N = 3
# M = 2
# A = [2, 2]
# B = [[1, 0], [1, 1], [1, 1]]

# print(get_total_ways(N, M, A, B))

# -> int(sys.stdin.readline().strip())
