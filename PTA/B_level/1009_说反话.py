speech = input()
words = speech.split(" ")
words = words[::-1]

i = 0
length = len(words)
for w in words:
    i += 1
    print( w, end="")
    if i < length:
        print(" ", end="")
