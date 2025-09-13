import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

for num in range(1, 101):
    print(f"{num} is {'prime' if is_prime(num) else 'not prime'}")
