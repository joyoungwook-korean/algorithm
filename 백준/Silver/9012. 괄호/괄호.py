def output(str):
    list_str = list(str)
    temp = 0
    for i in list_str:
        if i == "(":
            temp += 1
        else:
            temp -= 1

        if temp < 0:
            return -1
    return temp


n = int(input())
result = [""] * (n + 1)
for i in range(0, n):
    s = str(input())
    output_result = output(s)
    if output_result == -1 or output_result > 0:
        result[i] = "NO"
    else:
        result[i] = "YES"

for i in result:
    print(i)
