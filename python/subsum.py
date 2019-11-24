def max_sum(num_list):
    #program to find maximum possible sum of subarray in an array of integers

    length = len(num_list)
    if length == 0:
        return length
    elif length == 1:
        return num_list[0]
    
    sum = 0
    max = num_list[0]

    for x in num_list:
        if x < 0 & sum <= x:
                sum = x
                if sum > max:
                    max = sum
                continue

        sum = sum + x
        if sum > max:
            max = sum    

    if num_list[length - 1] > max:
        max = num_list[length - 1]

    return max
    
def main():
    num_list = [-1, -12, -13]
    print(max_sum(num_list))
    


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
