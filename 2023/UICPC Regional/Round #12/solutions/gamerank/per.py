rank = 25
stars = 0
streak = 0

def thres(rank): return min((35-rank)/5, 5)

for res in raw_input().strip():
    if res == 'W':
        streak += 1
        stars += 1
        if streak >= 3 and rank > 5:
            stars += 1
        if stars > thres(rank) and rank > 0:
            stars -= thres(rank)
            rank -= 1
    else:
        streak = 0
        if 0 < rank <= 20:
            stars -= 1
            if stars < 0:
                if rank < 20:
                    rank += 1
                    stars = thres(rank)-1
                else:
                    stars = 0
            
print rank if rank > 0 else 'Legend'
