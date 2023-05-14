x = input()
charge = int(x)
count = 0

coin_types = [500,100,50,10,5,1]

for coin in coin_types:
    count += charge // coin
    charge %= coin

print(count)
