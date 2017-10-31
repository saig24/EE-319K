// FiFo.c
// Runs on LM4F120/TM4C123
// Provide functions that implement the Software FiFo Buffer
// Last Modified: 4/10/2017 
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
// --UUU-- Declare state variables for FiFo
//        size, buffer, put and get indexes
	uint32_t FIFO[7];// 7 for size = 6 and plus 1
	uint32_t get;
	uint32_t put;
	uint32_t status;

// *********** FiFo_Init**********
// Initializes a software FIFO of a
// fixed size and sets up indexes for
// put and get operations
void FiFo_Init() {
// --UUU-- Complete this
	get = put = 0;
}

// *********** FiFo_Put**********
// Adds an element to the FIFO
// Input: Character to be inserted
// Output: 1 for success and 0 for failure
//         failure is when the buffer is full
uint32_t FiFo_Put(char data) {
	// --UUU-- Complete this routine
	if(put == 6){
		return 0;
	}
	FIFO[put] = data;
	put ++;
  return 1; 
}

// *********** FiFo_Get**********
// Gets an element from the FIFO
// Input: Pointer to a character that will get the character read from the buffer
// Output: 1 for success and 0 for failure
//         failure is when the buffer is empty
uint32_t FiFo_Get(char *datapt)
{
	//--UUU-- Complete this routine
	if(put == 0){
		return 0;
	}
	*datapt = FIFO[get];
	for(int i = 0; i < 6; i ++){
		FIFO[i] = FIFO[i + 1];
	}
	put --;
  return 1;
}



