from random import shuffle

size = 10
nums = list(range(1, size+1))
shuffle(nums)

nombre = "datasets/for_sorting/dataset.txt"
file = open(nombre, "w")
for num in nums:
    file.write(str(num)+ " ")
file.close()
print("Dataset Generado")