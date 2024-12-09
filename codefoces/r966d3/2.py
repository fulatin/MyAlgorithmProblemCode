cases = int(input())

for i in range(0,cases):
    number = 0
    seats = int(input())
    order = input().split()
    flg = True
    ok = []
    for j in range(0,seats+2):
        ok.insert(j,False)
    ok.insert(int(order[0])-1,True)

    ok.insert(int(order[0])+1,True)
    for j in range(1,seats):
        if not ok[int(order[j])]:
            flg = False
            break
        else:
            ok[int(order[j])+1] = True
            ok[int(order[j])-1] = True
    if flg:
        print("YES")
    else:
        print("NO")
