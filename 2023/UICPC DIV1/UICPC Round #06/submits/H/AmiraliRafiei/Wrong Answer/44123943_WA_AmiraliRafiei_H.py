def smallest_completion_time(Q, M, S, L):
    # Calculate the total time required for 1-second time slots
    time_1s = (S + M - 1) // M

    # Calculate the total time required for Q-second time slots
    time_Qs = (L + M - 1) // M

    # Calculate the smallest completion time
    total_time = max(time_1s, time_Qs * Q)
    return total_time

# Read input values
Q, M, S, L = map(int, input().split())

# Call the function and print the result
result = smallest_completion_time(Q, M, S, L)
print(result)
