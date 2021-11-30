def isPrime(num):
    if num> 1:  
        for n in range(2,num):  
            if (num % n) == 0:  
                return False
        return True
    else:
        return False


def twinPrime(n):
    # function returns the largest number p<=n that is a twin prime
    output = None;
    for i in range(n, 2, -1):
        if isPrime(i) and (isPrime(i+2) or isPrime(i-2)):
            output = int(i);
            break

    return output
    
def main():
    print(twinPrime(1))
    print(twinPrime(2))
    print(twinPrime(50))
    


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()

