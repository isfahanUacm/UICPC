n = int(input())
nums = []

for k in range(n):
    nums.append(int(input()))

k = 0
x = nums[k] * nums[k]
y = sum(nums) - nums[0]
max_ans = x*y

# print("x=",x)
# print("y=",y)

for k in range(1, n):
    x += nums[k]*nums[k]
    y -= nums[k]

    # print("k=",k)
    # print("x=",x)
    # print("y=",y)

    answer = x*y
    # print("answer=", answer)

    if answer > max_ans:
        max_ans = answer
        # print("NEW MAX=", max_ans)

print(max_ans)