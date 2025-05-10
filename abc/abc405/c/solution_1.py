N = int(input())
A = list(map(int, input().split()))
total = sum(A)
sum_pair = sum(a * a for a in A)
print((total*total - sum_pair) / 2)

# / , // 
# / 普通の割り算
# `//` 小数点以下切り落とし