def valid(rows, cols):
    for i in rows:
        if i not in cols:
            return "impossible"
    return "possible"
rowNcol= input().split(" ")
rows= list(map(int, input().split(" ")))
cols= list(map(int, input().split(" ")))
print(valid(rows, cols))