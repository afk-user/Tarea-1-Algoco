from random import shuffle

size = 100
nums = list(range(1, size//2+1))
nums2 = list(range(size//2+1,size+1))
shuffle(nums2)
nums = nums+nums2

nombre = "datasets/for_sorting/dataset.txt"
file = open(nombre, "w")
for num in nums:
    file.write(str(num)+ " ")
file.close()
print("Dataset Generado")