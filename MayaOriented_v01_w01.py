n = int(input('숫자 : '))
list = []
for i in range(1, n - 2, 1):
    for j in range(2, n - 2, 2):
        if i % 2 == 0:
            print(i * n + j - 1)
            list.append(i * n + j - 1)
        else:
            print(i * n + j)
            list.append(i * n + j)

print(list[0:int(len(list)/int((n-3)/2)]))
print(list[int(len(list)/int((n-3)/2)):])


