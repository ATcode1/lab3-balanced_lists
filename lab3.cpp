#include "lab3.h"

int prefix_sum(int array[], int length) {
    int sum = 0;

    for (int i = 0;i<length;i++) {
        sum += array[i];
    }
    return sum;

}

void generator(int array[], int n) {
    
    for (int i = 0;i<n/2;i++) {
        array[i] = 1;
    }

    for (int j = n/2;j<n;j++) {
        array[j] = -1;
    }

}

void fisher_yates(int array[], int n) {

    for (int i = n - 1;i>=1;i--) {

        int j;
        int temp;

	j = rand() % n;
	temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

bool non_negative_sum(int array[], int length) {
        bool result;
        int sum;

	result = true;
	sum = 0;

        for (int i = 0;i<length;i++) {
                sum += array[i];
                if (sum <= -1) {
                        result = false;
                }
        }
        return result;
}

int lowest_depth(int array[], int length){
    int lowest_index; 
    int lowest_sum;  
    int curr_sum;

    lowest_index = 0;
    lowest_sum = 0;
    curr_sum = 0;

    for (int i = 0;i<length;i++) {
        curr_sum += array[i];
        if(curr_sum < lowest_sum) {
            lowest_index = i;
            lowest_sum = curr_sum;
        }

    }

    return lowest_index;
}

int run(int n, int r){
    int x;

    x = 0;

    for (int i = 0;i<r;i++) {
        
	int change_size = 2 * (n+1);
        int array[change_size];

	int lowest_index = lowest_depth(array, change_size);
        int new_array[change_size - 1];

        generator(array, change_size);
        fisher_yates(array, change_size);

	for (int i = 0;i<(change_size - lowest_index - 1);i++) {
		
		new_array[i] = array[lowest_index + 1 + i];
		
		}

    	for (int i = 0;i<lowest_index; i++) {
		
		new_array[change_size - lowest_index + i - 1] = array[i];

		}       	 
	

	if (non_negative_sum(new_array, change_size -1) == true) {
                x += 1; 
        }

    }

    return x; 
}
