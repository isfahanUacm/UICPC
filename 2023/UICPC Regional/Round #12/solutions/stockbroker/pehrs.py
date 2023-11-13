days = int(raw_input())

money = 100

previous_value = int(raw_input())
for i in range(1, days):
    value = int(raw_input())
    if value > previous_value:
        #Stock price is rising. Assume we bought yesterday and sold today
        stock = min(money/previous_value, 100000)
        money = money - stock*previous_value
        money = money + value*stock     
    previous_value = value
print money
