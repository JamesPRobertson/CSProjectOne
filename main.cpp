//James Robertson
//Miller TTh 9:00 am

#include <iostream>
#include <time.h>

template <typename genericType>
genericType maxArray(genericType array[], int length);

int main() {
	srand(time(nullptr));

	int arrayLength = -1;

	int INTputArray[arrayLength];
	float floatputArray[arrayLength];

	arrayLength = (rand() % 8) + 2;

	for(int i = 0; i < arrayLength; i++){
		INTputArray[i] = rand() % 30;
	}

	for(int i = 0; i < arrayLength; i++){
		std::cout << "INPUTArray[" << i << "]" << ": " << INTputArray[i] << "\n";
	}

	for(int i = 0; i < arrayLength; i++){
		floatputArray[i] = (rand() % 300) / 7.14f;
	}

	std::cout << "Array length: " << arrayLength << "\n";
	std::cout << "This is the max of INTputArray: " << maxArray(INTputArray, arrayLength) << "\n";
	std::cout << "This is the max of floatputArray: " << maxArray(floatputArray, arrayLength) << "\n";

	std::cin.get();

	/*
	int largestNumber = -1;
	int arrayLength = -1;
	std::cout << "Please input a length: \n";
	arrayLength = std::cin.get();

	int inputArray[arrayLength];

	for(int i = 0; i < arrayLength; i++){
		std::cout << "Please input a number: \n";
		std::cin >> inputArray[i];
	}

	largestNumber = maxArray(inputArray, arrayLength);

	std::cout << "The largest number is: " << largestNumber;
    return 0;
    */
}

template <typename genericType>
genericType maxArray(genericType array[], int length){
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

	genericType leftHalf[length / 2];
	genericType rightHalf[(length / 2) + 1];

	for(int i = 0; i < (length) / 2; i++){
		leftHalf[i] = array[i];
		//std::cout << "Filling left array with: " << array[i] << "\n";
	}

	for(int i = (length) / 2; i < length; i++){
		rightHalf[i - (length / 2)] = array[i];
		//std::cout << "Filling right array with: " << array[i] << "\n";
	}

	return std::max(maxArray(leftHalf, (length / 2)), maxArray(rightHalf, (length /2 ) + isOdd));
}
