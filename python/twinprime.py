#!/usr/bin/env python3

#----------------------------------------------------------------------------
# Created By  : V. Jayakrishnan
# Created Date: 
# version ='1.0'
#----------------------------------------------------------------------------

def isPrime(num):
    """Check if the number is prime"""
    if num> 1:  
        for n in range(2,num):  
            if (num % n) == 0:  
                return False
        return True
    else:
        return False
#----------------------------------------------------------------------------

def twinPrime(num):
    """Function returns the largest twin prime number p, for p<=n"""
    #  https://en.wikipedia.org/wiki/Twin_prime

    output = None;

    # Loop backwards from the incoming number to reach 2
    for value in range(num, 2, -1):
        if isPrime(value) and (isPrime(value+2) or isPrime(value-2)):
            output = int(value);
            break

    return output
#----------------------------------------------------------------------------

def main():
    # test twinPrime method
    assert twinPrime(1) == None
    assert twinPrime(50) == 43

    # print the results
    print("Twin prime of 1: ",twinPrime(1))
    print("Twin prime of 50: ", twinPrime(50))
    
#----------------------------------------------------------------------------
# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()

