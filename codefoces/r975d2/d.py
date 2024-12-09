def count_winning_starts(n, deadlines):
    dp = [0] * n
    dp[0] = 1
    count = 0
    
    for i in range(1, n):
        if deadlines[i] >= i + 1:
            dp[i] = dp[i-1] + 1
            if dp[i] == n:
                count += 1
        else:
            dp[i] = dp[i-1]
    
    return count

# Example usage:
t = int(input())
for _ in range(t):
    n = int(input())
    deadlines = list(map(int, input().split()))
    print(count_winning_starts(n, deadlines))

