nCards, selectedCard, nSteps = map(int, input().split())
cards = list(range(1, nCards + 1))
selections = []

for i in range(nSteps):
    selections.append(list(map(int, input().split()))[1:])


for selection in selections:
    if selectedCard in selection:
        print("KEEP")
    else:
        print("REMOVE")

