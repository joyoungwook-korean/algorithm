# 단어 정렬
# https://www.acmicpc.net/problem/1181

n = int(input())
dic_map = {}
for i in range(n):
    dic = input()
    if len(dic) in dic_map:
        if dic not in dic_map[len(dic)]:
            dic_map[len(dic)].append(dic)
    else:
        dic_map[len(dic)] = [dic]

for i in range(51):
    if i in dic_map:
        if len(dic_map[i]) > 1:
            dic_map[i].sort()
            for result_dic in dic_map[i]:
                print(result_dic)
        else:
            print(dic_map.get(i)[0])


# n = int(input())
# words = []
# for _ in range(n):
#     word = input()
#     words.append(word)

# words = sorted(set(words), key=lambda x: (len(x), x))

# for word in words:
#     print(word)
