# 덩치
# https://www.acmicpc.net/problem/7568


def calculate_rank(data):
    ranks = [] 

    for i in range(len(data)):
        rank = 1 
        for j in range(len(data)):
          
            if data[i][0] < data[j][0] and data[i][1] < data[j][1]:
                rank += 1
        ranks.append(rank)

    return ranks

n = int(input())
data = [] 
for _ in range(n):
    weight, height = map(int, input().split())
    data.append((weight, height))


ranks = calculate_rank(data)

print(*ranks)