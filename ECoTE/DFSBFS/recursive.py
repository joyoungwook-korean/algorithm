def test_d(i):
    if i == 100:
        return
    print(i, "번째 재귀함수 시작합니다")
    test_d(i+1)
    print(i, "번째 재귀함수 종료합니다.")

test_d(1)