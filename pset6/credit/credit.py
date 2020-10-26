from sys import exit

while True:
    try:
        ccInput = int(input("Number: "))
        if ccInput > 0:
            break
    except:
        continue

ln = (len(str(ccInput)))

if (ln is not 13) and (ln is not 15) and (ln is not 16):
    print("INVALID\n", end="")
    exit(1)

ccDigits = [];
for i in range(ln):
    ccDigits.append(ccInput % 10)
    ccInput = ccInput // 10
    i += i

sum1 = 0
for i in range(1, ln, 2):
    sumTemp = ccDigits[i] * 2
    if sumTemp >= 10:
        d1 = sumTemp // 10
        d2 = sumTemp % 10
        sumTemp = d1 + d2
    sum1 = sum1 + sumTemp

sum2 = 0
for i in range(0, ln, 2):
    sum2 = sum2 + ccDigits[i]
sumFinal = sum1 + sum2

if (sumFinal % 10 is not 0):
    print("INVALID\n", end="")
else:
    if ((ln == 13 or ln == 16) and (ccDigits[12] == 4 or ccDigits[15] == 4)):
        print("VISA\n", end="")
    elif ((ln == 15 and ccDigits[14] == 3) and (ccDigits[13] == 4, 7)):
        print("AMEX\n", end="")
    elif ((ln == 16 and ccDigits[15] == 5) and (ccDigits[14] == 1, 2, 3, 4, 5)):
        print("MASTERCARD\n", end="")
    else:
        print("INVALID\n", end="")