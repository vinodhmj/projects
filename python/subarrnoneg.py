def doDrama(sum, max_sum, istart, iend, ostart, oend):
    if sum == max_sum:
        if(iend - istart) > (oend - ostart):
            ostart = istart
            oend = iend
            return max_sum, ostart, oend
        elif(iend - istart) == (oend - ostart):
            ostart = ostart if ostart < istart else istart
            oend   = oend if ostart < istart else iend
            return max_sum, ostart, oend
        
    elif sum > max_sum:
        max_sum = sum
        ostart = istart
        oend = iend
    return max_sum, ostart, oend
    
def max_sum(num_list):
    #program to find sub array with max sum and no negative numbers

    output = []
    length = len(num_list)

    # sanity
    if length == 0:
        return length
    elif length == 1 & num_list[0] > 0:
        return num_list[0]
        
    sum = max_sum = istart = iend = ostart = oend = 0
    reset = True

    for index, val in enumerate(num_list, start=0):
        if val < 0:
            reset = True
            max_sum, ostart, oend = doDrama(sum, max_sum, istart, iend, ostart, oend)
            sum = 0
            continue

        sum = sum + val

        if reset:
            istart = iend = index
            reset = False
        else:
            iend = index

        if (index == length-1) & (sum > max_sum):
            max_sum, ostart, oend = doDrama(sum, max_sum, istart, iend, ostart, oend)


    output = num_list[ostart:oend+1]
    return output
    
def main():
    num_list = [1,2,5,-7,2,3]
    print(max_sum(num_list))
    


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
