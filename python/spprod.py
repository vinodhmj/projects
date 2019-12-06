def spprod(arey, location):
    #program special product.
    # special product is defined as...
    # nah.. takes too long to explain

    spproduct = 0;
    length = len(arey)

    # sanity
    if length == 0 | length == 1:
        return
 
    spleft = spright = 0
    valAtLocation = arey[location]
    
    for index, val in enumerate(arey, start=0):
        if index < location:
            if arey[index] > valAtLocation:
                spleft = index
        elif index > location:
            if arey[index] > valAtLocation:
                spright = index
                break

    spproduct = spleft * spright
    return spproduct
    
def main():
    arey = [1,2,5,-7,2,3]
    print(spprod(arey, 4))

# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
