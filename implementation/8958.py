# OX퀴즈
# https://www.acmicpc.net/problem/8958

def quiz():
    str_quiz = input()
    tmp = 0
    result = 0
    for s in str_quiz:
        if s == 'O':
            tmp += 1
        else:
            tmp = 0
        result += tmp
    return result

for _ in range(int(input())):
    print(quiz())