# author: Armin Fazeli

try:
    n = int(input())

    towns = [[] for _ in range(n)]
    
    for _ in range(n-1):
        edge_input = input().split()
        a, b = int(edge_input[0]) - 1, int(edge_input[1]) - 1
        
        towns[a].append(b)
        towns[b].append(a)

    levels = {0: 0}

    def traverse(start):
        stack = [(start, 0)]
        while stack:
            node, level = stack.pop()
            levels[node] = level
            for t in towns[node]:
                if t not in levels:
                    stack.append((t, level + 1))

    traverse(0)
    town_a = max(levels.keys(), key=lambda a: levels[a])

    levels = {town_a: 0}
    traverse(town_a)
    print(max(levels.values()))

except _:
    pass