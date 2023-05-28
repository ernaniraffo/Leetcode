class WordNode:

    def __init__(self):
        self.children = {}
        self.end = False

    def search(self, word: str) -> bool:
        node = self
        for i in range(len(word)):
            if word[i] == '.':
                for child in node.children.values():
                    if child.search(word[i+1:]):
                        return True
                return False
            if word[i] not in node.children:
                return False
            node = node.children[word[i]]
        return node.end


class WordDictionary:

    def __init__(self):
        self.root = WordNode() 

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = WordNode()
            node = node.children[c]
        node.end = True

    def search(self, word: str) -> bool:
        return self.root.search(word)
