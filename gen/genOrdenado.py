size = 100000
nums = list(range(1, size+1))

nombre = "datasets/for_sorting/dataset.txt"
file = open(nombre, "w")
for num in nums:
    file.write(str(num)+ " ")
file.close()
print("Dataset Generado")