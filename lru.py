class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None


class List:
    def __init__(self):
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.length = 0

    def remove(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.length -= 1

    def pop(self) -> Node:
        node = self.tail.prev
        self.remove(node)
        return node

    def append(self, node: Node):
        self.head.next.prev = node
        node.next = self.head.next
        self.head.next = node
        node.prev = self.head
        self.length += 1

    def __len__(self):
        return self.length


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.ht = {}
        self.ll = List()

    def get(self, key: int) -> int:
        if (key in self.ht):
            node = self.ht[key]
            self.ll.remove(node)
            self.ll.append(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.ht:
            self.ht[key].value = value
            node = self.ht[key]
            self.ll.remove(node)
            self.ll.append(node)
        else:
            if (len(self.ll) == self.capacity):
                node = self.ll.pop()
                self.ht.pop(node.key)
            node = Node(key, value)
            self.ht[key] = node
            self.ll.append(node)


if __name__ == "__main__":
    lRUCache = LRUCache(2)
    print(lRUCache.put(1, 1))
    print(lRUCache.put(2, 2))
    print(lRUCache.get(1))
    print(lRUCache.put(3, 3))
    print(lRUCache.get(2))
    print(lRUCache.put(4, 4))
    print(lRUCache.get(1))
    print(lRUCache.get(3))
    print(lRUCache.get(4))
