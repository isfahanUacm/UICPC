def calculate_h_index(n, citations):
    citations.sort(reverse=True)
    h_index = 0

    for i, citation in enumerate(citations):
        if citation >= i + 1:
            h_index = i + 1
        else:
            break

    return h_index

# Read the number of papers
n = int(input())

citations = []
for _ in range(n):
    citation = int(input())
    citations.append(citation)

h_index = calculate_h_index(n, citations)
print(h_index)
