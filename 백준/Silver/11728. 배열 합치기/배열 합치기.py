n, m = map(int, input().split())

list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))

result = []
i, j = 0, 0
while i < len(list1) and j < len(list2):
    if list1[i] < list2[j]:
        result.append(list1[i])
        i = i + 1
    else:
        result.append(list2[j])
        j = j + 1

while i < len(list1):
    result.append(list1[i])
    i = i + 1

while j < len(list2):
    result.append(list2[j])
    j = j + 1

print(" ".join(map(str, result)))
