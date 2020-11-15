
def main():
    hash = set()
    for i in range(1000000):
        hash.add(i)
    for i in range(1000000):
        x = i in hash
    for i in range(1000000):
        hash.remove(i)
    print("Done")


if __name__ == '__main__':
    main()
