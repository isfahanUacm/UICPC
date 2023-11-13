arr = []
n = int(input())

for i in range(n):
    arr.append(int(input()))

n_stocks = 0
balance = 100
current_price = arr[0]
nxt_price = arr[1]

for i in range(1, len(arr)):
    if nxt_price < current_price:
        balance += n_stocks * current_price
        n_stocks = 0

    elif nxt_price > current_price:
        if n_stocks + balance // current_price < 100000:
            n_stocks += balance // current_price
            balance -= n_stocks * current_price


    else:
        pass
    
    if i >= len(arr) - 1:
        if n_stocks > 0:
            balance += n_stocks * nxt_price
            n_stocks = 0
        break

    current_price = nxt_price
    nxt_price = arr[i + 1]


print(balance)