ans = 1
for i in range(10000):
    ans*=3
    if ans%1000 == 387:
        print(ans%10000000000)
