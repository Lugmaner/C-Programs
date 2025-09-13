arraylen = int(input("Enter the number of elements you want to sort: "))
numberlist = [2] * arraylen


for i in range(0, arraylen):
    numberlist[i] = int(input("Enter the " + str(i + 1) + ". number: "))


def sortalg(numberlist):

    for i in range(0, arraylen - 1):
        for j in range(0, arraylen - i - 1):
                   if numberlist[j] > numberlist[j + 1]:
                        numsave = numberlist[j]
                        numberlist[j] = numberlist[j + 1]
                        numberlist[j + 1] = numsave
                   
    return numberlist
                   
print("Sorted list is: ", sortalg(numberlist))
                   
                   