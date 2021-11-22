import random

n = int(input("미로의 크기 입력 : "))
list = [['■'] * n for i in range(n)]

####### N x N 맵 생성 #######
print("####### N x N 맵 생성 #######")
for i in range(n):
    for j in range(n):
        print(list[i][j], end = '  ')
    print()
print()

####### 벽만 남기고 뚫기 #######

for i in range(1,n-1,1):
    for j in range(1,n-1,1):
        list[i][j] = ' '

####### 출력 #######
print("####### 벽만 남기고 뚫기 #######")
for i in range(n):
    for j in range(n):
        print(list[i][j], end = '  ')
    print()
print()

####### 격자무늬로 벽 생성 #######
for i in range(1,n-1,1):
    for j in range(1,n-1,1):
        if i%2==0 or j%2==0:
            list[i][j] = '■'

####### 출력 #######
print("####### 격자무늬로 벽 생성 #######")
for i in range(n):
    for j in range(n):
        print(list[i][j], end = '  ')
    print()
print()

####### 모든 뚫린 곳의 오른쪽 or 아래 중 하나를 뚫기 (외벽은 건드리지 않게끔 코딩) #######
for i in range(1,n-1,2):
    for j in range(1,n-1,2):
        toss = random.choice([0,1])
        if toss==0:
            if (i+1 < n-1):
                list[i+1][j] = ' '
            else:
                list[i][j+1] = ' '
        else:
            if (j+1 < n-1):
                list[i][j + 1] = ' '
            else:
                list[i+1][j] = ' '

####### 시작지점 뚫기 #######
list[0][1] = ' '

####### 출력 #######
print("####### 모든 뚫린 곳의 오른쪽 or 아래 중 하나를 뚫기 (외벽은 건드리지 않게끔 코딩) #######")
for i in range(n):
    for j in range(n):
        print(list[i][j], end = '  ')
    print()
print()



