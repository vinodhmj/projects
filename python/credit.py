def credit(n, mode = "verify"):
    output = False

    # ALGORITHM

    # initialize variables
    tenFactor = int(10)
    lastDigit = int(0)
    remNumbers = int(n)
    digitList = [None] * 15
    sumOfDigits = int(0);

    # split into digits
    if mode == "verify":
        lastDigit = int(n % tenFactor)
        remNumbers = int(n / tenFactor)
    
    for index in range(15, 0, -1):
        digit = int(remNumbers % tenFactor)
        remNumbers = int(remNumbers / tenFactor)
        if index % 2 != 0: # odd
            digit = digit * 2
            if digit > 9:
                digit = (digit / tenFactor) + (digit % tenFactor)

        digitList[index-1] = int(digit)
        sumOfDigits += int(digit)

    if mode == "verify":
        if ((sumOfDigits + lastDigit) % 2 == 0):
            output = True
    elif mode == "calculate":
        output = tenFactor - (sumOfDigits % 2)
    else:
        output = None
    
    return output
    
def main():
    print(credit(4578423013769219))
    print(credit(4578423013769219, "verify"))
    print(credit(457842301376921, "calculate"))


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()

