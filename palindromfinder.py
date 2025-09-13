word = input("Enter a word: ").lower().replace(" ", "")

def reverse(word):
    wordreverse = [""] * len(word)
    for i in range(0, len(word)):
        wordreverse[i] = word[len(word) - 1 - i]
    return "".join(wordreverse)

if word == reverse(word):
    print("The word is a palindrome")
else:
    print("The word is not a palindrome")
