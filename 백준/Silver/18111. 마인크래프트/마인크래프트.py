import sys

n, m, b = map(int, input().split())

maps = [list(map(int, input().split())) for _ in range(n)]
max_block = 0
min_block = 256
min_time = float("inf")
height_dic = {}
result_block = 0

for i in maps:
    tmp_max = max(i)
    tmp_min = min(i)
    if tmp_max > max_block:
        max_block = tmp_max
    elif tmp_min < min_block:
        min_block = tmp_min
    for height in i:
        if height in height_dic:
            height_dic[height] += 1
        else:
            height_dic[height] = 1


for crruent_block in range(min_block, max_block + 1):
    tmp_block = b
    time = 0

    for height, count in height_dic.items():
        if crruent_block < height:
            pop_block_num = height - crruent_block
            tmp_block += pop_block_num * count
            time += (pop_block_num) * 2 * count
        elif crruent_block > height:
            input_block = crruent_block - height
            tmp_block -= input_block * count
            time += (input_block) * count
    if tmp_block >= 0 and time <= min_time:
        if time < min_time or (time == min_time and crruent_block > result_block):
            min_time = time
            result_block = crruent_block


print(min_time, result_block)
