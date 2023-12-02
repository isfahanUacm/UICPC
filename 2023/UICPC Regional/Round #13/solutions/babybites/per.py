raw_input()
print ['something is fishy', 'makes sense'][all(x in ['mumble', str(i+1)] for (i, x) in enumerate(raw_input().split()))]
