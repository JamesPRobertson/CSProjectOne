#include <iostream>

int maxArray(int array[], int length);

int main() {
	int largestNumber = -1;
	int arrayLength = -1;
	std::cout << "Please input a length: \n";
	std::cin >> arrayLength;

	int tempArray[arrayLength];

	for(int i = 0; i < arrayLength; i++){
		std::cout << "Please input a number: \n";
		std::cin >> tempArray[i];
	}

	largestNumber = maxArray(tempArray, arrayLength);

	std::cout << "The largest number is: " << largestNumber;
    return 0;
}

int maxArray(int array[], int length){
	if(length == 1){
		return array[0];
	}
	else if(length == 2){
		return std::max(array[0],array[1]);
	}

	int isOdd = 0;
	if(length % 2 != 0){
		isOdd = 1;
	}

	int leftHalf[length / 2];
	int rightHalf[(length / 2) + 1];

	for(int i = 0; i < (length) / 2; i++){
		leftHalf[i] = array[i];
		std::cout << "Filling left array with: " << array[i] << "\n";
	}

	for(int i = (length) / 2; i < length; i++){
		rightHalf[i - (length / 2)] = array[i];
		std::cout << "Filling right array with: " << array[i] << "\n";
	}

	return std::max(maxArray(leftHalf, (length / 2)), maxArray(rightHalf, (length /2 ) + isOdd));
}
