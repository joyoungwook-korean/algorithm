# 문제
# 정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는
# 모든 경우의 수를 구하는 프로그램을 작성하라. 예를 들어 1을 입력했을 때
# 다음은 3이 하나라도 포함되어 있으므로 세어야 하는 시각이다

# 00시 00분 03초
# 00시 13분 30초
# 반면에 다음은 3이 하나도 포함되어 있지 않으므로 세면 안 되는 시각이다

# 00시 02분 55초
# 01시 27분 45초

num = int(input())

h,m,s = 0,0,2
cnt = 0

while h != num+1:
    if s == 60:
        s = 0
        m +=1
    if m == 60:
        m = 0
        h +=1
    if '3' in str(h) +str(m) + str(s):
        cnt +=1
    s +=1

print(cnt)

count = 0
for i in range(num+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i)+str(j)+str(k):
                count +=1

print(count)