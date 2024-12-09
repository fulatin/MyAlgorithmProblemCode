from collections import deque, defaultdict

def getConnectedComponents(n, m, queries):
    g = [[] for _ in range(n + 1)]
    for ai, di, ki in queries:
        start_idx = ai
        end_idx = start_idx + di * (ki + 1) - 1
        if di == 1:
            for j in range(ki + 1):
                g[start_idx + j].append(start_idx + j + 1)
        else:
            for k in range(ki + 1):
                g[start_idx + k * di].append(start_idx + (k + 1) * di)

    visited = [0] * (n + 1)
    comps = []
    for i in range(1, n + 1):
        if not visited[i]:
            comp = set()
            stack = deque([i])
            while len(stack) > 0:
                u = stack.pop()
                if u not in comp:
                    comp.add(u)
                    visited[u] = 1
                    for v in g[u]:
                        if not visited[v]:
                            stack.append(v)

            comps.append(comp)

    return len(comps)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        queries = [tuple(map(int, input().split())) for _ in range(m)]
        print(getConnectedComponents(n, m, queries))

