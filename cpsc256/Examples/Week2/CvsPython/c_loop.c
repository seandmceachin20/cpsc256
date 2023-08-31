#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int number_of_iterations;
	int s = 0;
	number_of_iterations = atoi(argv[1])*1000000;
	for (int i = 0; i<number_of_iterations; ++i){
		s +=1;
	}
	printf("C s: %d", s);
	return 0;
} 
