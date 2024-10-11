import random

array = []

for i in range(10):
    array.append(random.randint(1, 100))

print(array)

for i in range(9):
    for j in range(9):
        if array[j] > array[j+1]:
            aux = array[j]
            array[j] = array[j+1]
            array[j+1] = aux


print(array)