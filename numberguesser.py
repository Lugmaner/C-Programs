import random
tries = 0
guessed = False

number = random.randint(1, 100)

while not guessed:

    try:
        guess = int(input("Your guess: "))
    except ValueError:
        print("Please enter an integer.")
        continue

    tries += 1
    if guess < number:
        print("Too low!")
    elif guess > number:
        print("Too high!") 
    else:
        print("You guessed it!")
        print(f"You guessed the number in {tries} tries.")
        guessed = True