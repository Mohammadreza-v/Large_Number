def Large_Sum(num1, num2): # function for Sum two Large Number
	num1 = list(num1)
	num2 = list(num2)
	Sum = 0
	num = 0
	result = list()
	result_Sum = ''

	if len(num1) < len(num2):
	    num1, num2 = num2, num1

	num1.reverse()
	num2.reverse()

	for i in range(len(num1)):
	    if (i <= len(num2) - 1 ):
	        Sum = int(num1[i]) + int(num2[i]) + num
	    elif (i > len(num2) -1 ):
	        Sum = int(num1[i]) + num
	    result.append(Sum % 10)
	    num = Sum // 10

	result.reverse()

	for i in range(len(result)):
		result_Sum = result_Sum + str(result[i])
	return result_Sum


with open("input.txt", 'r') as file: # read Input file for get two large number
	str1 = str(file.readline()).strip('\n')
	str2 = str(file.readline()).strip('\n')

result = Large_Sum(str1, str2)
with open('Sum.txt', 'a') as file_result: # write result into a file
	file_result.write("\n####################################\nSum is : \n%s"% result)

print(Large_Sum(str1, str2))
