//David Turner
//Assignment5
//December 5, 2018

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Timer{
	steady_clock::time_point start, end;
	duration<float> duration;
public:
	Timer(){
		start = high_resolution_clock::now();
	}

	~Timer(){
		end = high_resolution_clock::now();
		duration = end - start;
		float seconds = duration.count();
		cout << "This function took " << seconds << "s "<< "to complete." << endl;
	}
	
};
class Sort{
public:
	void selectionSort(int arr[], const int SIZE){
		Timer timer;
		for(int i=0; i<SIZE; i++){
			for(int k=i+1; k<SIZE; k++){
				if(arr[k] < arr[i]){
					int temp = arr[i];
					arr[i] = arr[k];
					arr[k] = temp;
				}
			}
		}
	}
	void bubbleSort(int arr[], const int SIZE){
		Timer timer;
		for(int i=0; i<SIZE; i++){
			bool swapped = false;
			do{
				for(int k=1; k<SIZE; k++){
					if(arr[k-1] > arr[k]){
						int temp = arr[k];
						arr[k] = arr[k-1];
						arr[k-1] = temp;
					}
				}
			}
			while(swapped);
		}
	}
	void insertionSort(int arr[], const int SIZE){
		Timer timer;
		int key, j;
		for(int i=1; i<SIZE; i++){
			key = arr[i];
			j=i-1;

			while(j>=0 && arr[j] > key){
				arr[j+1] = arr[j];
				j = j-1;
			}
			arr[j+1] = key;
		}
	}
	void merg(int inputArr[], int tempArr, int startIndex, int middleIndex, int endIndex){
		int i = startIndex;
		int j = middleIndex + 1;
		int k = startIndex;

		while(i != smiddleIndex+1 && j != endIndex+1){
			if(inputArr[i] > inputArr[j]
				tempArr[k++] = inputArr[j++];
			else
				tempArr[k++] = inputArr[i++];
		}
	}
};
void printArray(int arr[], int n){
	for(int i=0; i<n;i++){
		cout<<arr[i]<<endl;
	}
}
void insertRandomArray(int arr[], int n){
	for(int i=0; i<n;i++){
		arr[i] = ((rand()%10000));
	}
}
void insertAlmostSorted(int arr[], int n){
	for(int i=0; i<n; i++){
		if(i%10
			
			==0){
			arr[i] = ((rand()%10000));
		}
		else{
			arr[i] = i;
		}
	}
}
void insertWrongOrder(int arr[], int n){
	for(int i=n-1; 0<i;i--){
		arr[i] = ((rand()%10000));
	}
}
int main(){
	const int SIZE = 100000;
	int sampleArr[SIZE];

	Sort* sorter = new Sort;
	
	insertWrongOrder(sampleArr, SIZE);

	for(int i=0; i<10;i++){
		sorter->bubbleSort(sampleArr, SIZE);
	}

	system("pause");
	return 0;
}