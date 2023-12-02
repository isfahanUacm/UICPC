import datetime, heapq

def conv_date(d):
    date_object = datetime.datetime.strptime(d, '%Y-%m-%d %H:%M')
    date_base =  datetime.datetime(2013, 1, 1, 0, 0)
    c = date_object - date_base
    return int(c.total_seconds()) // 60

tt = int(input())

while tt > 0:
    tt -= 1
    
    n, t = map(int, input().split())
    
    s = []
    for i in range(n):
        inp = input().split()
        start = conv_date(inp[1] + ' ' + inp[2])
        end = conv_date(inp[3] + ' ' + inp[4])
        s.append((start, end))
    
    s = sorted(s)
    
    pq = []
    heapq.heapify(pq)
    mx = 0
    for res in s:
        while len(pq) > 0:
            u = heapq.heappop(pq)
            if u <= res[0]:
                heapq.heappush(pq, u)
                break
        
        if len(pq) == 0:
            mx += 1
            heapq.heappush(pq, res[1] + t)
            
    print(mx)