/*
	Bruce Zheng
	9/3/2012
	Solution for Chapter 4 Exercise 14
	Uses the Sieve of Eratosthenes to print all primes from 1 to any positive integer
*/

#include "std_lib_facilities.h"

int main (){
	//Determine and print all prime numbers from 1 to user inputted max
	cout << "Enter the upper limit to find primes for\n";
	int max;
	cin >> max;
	
	vector<int> primecandidates;
	for(int i = 2; i <= max; ++i){
		primecandidates.push_back(i);	
	}

	//Precondition: primecandidates is a vector with consecutive numbers from 2 to max
	int numprimes = primecandidates.size();

	int counter1 = 0; 
	while(counter1 < numprimes){
		int counter2 = counter1 + 1;
		int subtractor = 0;
		while(counter2 < numprimes){
			if(primecandidates[counter2] % primecandidates[counter1] > 0)
				primecandidates[(counter2 - subtractor)] = primecandidates[counter2];
			else
				++subtractor;
			++counter2;
		}
		++counter1;
		numprimes -= subtractor;
	} 
	/*
		Postcondition: numprimes = actual number of primes contained in precondition primecandidates
		primecandidates has all primes from 2 to max sorted in indicies from 0 to numprimes 
		All elements from index numprimes and on are complete jibberish
	*/
	
	cout << "The primes from 1 to " << max << " are:\n";
	for(int i = 0; i < numprimes; ++i){
		cout << primecandidates[i] << " ";
	}
	cout << "\n";
	keep_window_open();
}