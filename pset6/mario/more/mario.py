while True:
    try:
        psize = int(input("Height: "))
        if psize > 0 and psize < 9:
            break
    except:
        continue

for i in range(0, psize, 1):
    print(" " * (psize - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1), end="")
    print("")