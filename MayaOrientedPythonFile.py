import random

arrf=[]#1차원 배열 미로 결과 인덱스

n = int(input("숫자 입력 : \n"))

#arrf.append(1)
#arrf.append(n*n-2)

for i in range(1, n, 2):
    for j in range(1, n, 2):
        arrf.append(i * n + j)

for i in range(2, n - 1, 2):
     arrf.append(i * n + n - 2)

for i in range(2, n - 1, 2):
    arrf.append((n - 2) * n + i)
    

list = []
for i in range(1, n - 2, 1):
    for j in range(2, n - 2, 2):
        if i % 2 == 0:
            list.append(i * n + j - 1)
        else:
            list.append(i * n + j)

arrs=[]
a = int((n-3)/2)
b = a*a*2
for i in range(0,b-a,1):
    if i%(a*2)<a:
        arrs.append(list[i])
        arrs.append(list[i + a])

arrrd = []
for i in range (0,b-1,1):
    if i%2==0:
        arrrd.append(arrs[i])
        arrrd.append(arrs[i+1])
        arrf.append(random.choice(arrrd))
        arrrd=[]

print(sorted(arrf)) #오름차순 정렬
print(len(arrf)) #인덱스 개수 출력

IXlist = []
for i in sorted(arrf):
    IXlist.append('pPlane1.f[%d]' %i) #마야 MEL 코딩용 인덱스 출력

print(IXlist)
