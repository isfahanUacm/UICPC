def calculate_completion_time(Q, M, S, L):
    # Calculate the number of longer batches that can be completed on all machines
    complete_batches = L // (M * Q)

    # Calculate the remaining longer batch slots
    remaining_slots = L % (M * Q)

    # Calculate the total time for longer batches
    total_time = complete_batches * Q

    # Calculate the total time for the remaining longer batch slots
    if remaining_slots > 0:
        total_time += Q

    # Calculate the total time for 1-second time slots
    total_time += S

    return total_time

# Read the input
Q, M, S, L = map(int, input().split())

# Calculate and print the smallest amount of time to complete all the time slots
completion_time = calculate_completion_time(Q, M, S, L)
print(completion_time)
