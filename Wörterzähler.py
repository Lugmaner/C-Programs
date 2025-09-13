satz = str(input("Gib einen Satz ein: "))
z = 0
for i in range(0, satz.__len__()):

    if satz[i] == " "and i-1 != " " or i == satz.__len__()-1 and satz[i] != " ":
        z += 1
    else:
        print("...")
print("Der Satz hat " + str(z) + " Wörter.")