from Node import Node

def main():
    x = Hash(hash)
    for i in range(1000000):
        x.add(i)
    for i in range(1000000):
        x.check(i)
    for i in range(1000000):
        x.remove(i)
    print("Done")


class Hash:
    def __init__(self,func,len = 1000000):
        self.func = func
        self.len = len
        self.size = 0
        self.nodes = [None for i in range(len)]

    def check(self, val):
        hack = self.func(val)
        if (hack < 0):
            hack *= -1
        hack %= self.len
        temp = self.nodes[hack]
        while (temp):
            if (temp.val is val):
                return True
            temp = temp.next
        return False

    def add(self, val):
        hack = self.func(val)
        if (hack < 0):
            hack *= -1
        hack %= self.len
        self.nodes[hack] = Node(val, self.nodes[hack])
        self.size+=1

    def remove(self, val):
        hack = self.func(val)
        if (hack < 0):
            hack *= -1
        hack %= self.len
        if (not self.nodes[hack]):
            return
        if (self.nodes[hack].val is val):
            self.nodes[hack] = self.nodes[hack].next
            return
        temp = self.nodes[hack]
        while(temp.next is not None):
            if (temp.next.val is val):
                temp.next = temp.next.next
                return
            temp = temp.next
if __name__ == '__main__':
    main()
