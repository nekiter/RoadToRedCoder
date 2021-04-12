
# Creating the array of lists structure
AMOUNT_OF_BUCKETS = 5
hashtable = []
for i in range(AMOUNT_OF_BUCKETS):
    hashtable.append([]) #O(1)


# O(M) where M is the amount of letters
def hashFunction(text):
    ret = 0
    for letter in text:
        ret += int(ord(letter))
    
    return ret%AMOUNT_OF_BUCKETS


def insertElement(text, value):
    pos = hashFunction(text) #O(M)
    hashtable[pos].append( (text, value)) #O(1)

def deleteElement(text):
    pos = hashFunction(text) #O(M)

    #O(N) where N is the amount of elements on the same bucket
    for storedTuple in hashtable[pos]:
        if storedTuple[0] == text:
            hashtable[pos].remove(storedTuple)
            break

def getValue(text):
    pos = hashFunction(text) #O(M)
    
    #O(N) where N is the amount of elements on the same bucket
    for storedTuple in hashtable[pos]:
        if storedTuple[0] == text:
            return storedTuple[1]


insertElement("BEATRIZ", 10)
insertElement("CAIO", 20)
insertElement("GUSTAVO", 30)
insertElement("ITALO", 40)
insertElement("LUCAS", 50)

print(hashtable)
print("Qual valor de ITALO? ")
print(getValue("ITALO"))