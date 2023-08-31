import sys

number_of_iterations = int(sys.argv[1])*1000000

s = 0
for i in range(number_of_iterations):
	s+=1

print("Python: %d" % s);
