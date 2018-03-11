import math
import functools

def main():
    while True:
        try:
            n, k = int(input()), input()
            z = list(map(int, input().split()))
        except EOFError:
            break
        print(math.factorial(n) // functools.reduce(lambda a, b: a * math.factorial(b), z, 1))

if __name__ == '__main__':
    main()

