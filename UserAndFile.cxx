/*
Caleb Hemmestad
C++ 2021
Due: 9/29/21
Lab 3 User and File I/O

An interactive C++ program that computes 
and outputs the mean and population 
standard deviation of a set of four integers 
 */


#include <iostream>
#include <fstream>
#include <cmath>

using namespace std; //So I dont have to do std:: all the time

//Declaring function
float findMean ( int &input1 , int &input2 , int &input3 , int &input4 ) ;

//Declaring function
float findDeviation ( int &input1 , int &input2 , int &input3 , int &input4 , float &mean2 ) ;

int main ( )
{
	ifstream infile;
	infile.open("/Users/caleb/Desktop/C++ Class/Lab 3/InMeanStd.dat") ; //Opens file to use

	ofstream outfile;
	outfile.open("/Users/caleb/Desktop/C++ Class/Lab 3/OutMeanStd.dat") ; //Opens file to use
	
	int input1 , input2 , input3 , input4 ; //Variables for storing numbers from infile
	int number ; //Variable for storing how many numbers you have
	float sum , diffSum , mean1 , variance1 , deviation1 ; //Variables to store information for calc
	//diffSum = the sum of the differences
	
	cout << "How many numbers do you want use? : " ; //Asking user how many numbers they want to use
	cin >> number ;
	float inputMemory [ number ] ; //Variable used for saving the users input for each number to use later
	
	//Asking user for the numbers they want to use
	for ( int x = 0 ; x < number ; x++ ) {	 
		cout << "Enter number " << x+1 << " : " ;
		cin >> inputMemory [ x ] ;
		if ( !cin ) { //Ending program for invalid input
			cout << "Error. Program Ended" ;
			return 0 ;
		}
		sum = sum += inputMemory [ x ] ; //Adding inputted numbers to find the sum
	}
	mean1 = sum/number ; //Dividing sum by the amount of numbers the user entered to find the mean
	
	//Displaying the mean
	cout << "The mean is : " << mean1 << endl ;
	
	//Finding the difference of each number
	for ( int x = 0 ; x < number ; x++ ) {
		inputMemory [ x ] = inputMemory [ x ] - mean1 ; //subtracting mean from each number entered for the difference
	}
	//Squaring the difference of each number
	for ( int x = 0 ; x < number ; x++ ) {
		inputMemory [ x ] = inputMemory [ x ] * inputMemory [ x ] ; // = Difference^2
	}
	//Adding the squared differences to get the sum of the differences
	for ( int x = 0 ; x < number ; x++ ) {
		diffSum = diffSum + inputMemory [ x ] ;
	}
	variance1 = diffSum/number ; //Dividing the sum of the squared difference by the amount of numbers entered to find the variance
	deviation1 = sqrt(variance1) ; //The square root of the variance to find the deviation
	cout << "The deviation is : " << deviation1 << endl ;
	
	//Taking the information form the infile and storing it in variables to use
	infile >> input1 >> input2 >> input3 >> input4 ;
	
	//Function to find the mean
	float mean2 = findMean ( input1 , input2 , input3 , input4 ) ;
	
	//Function to find the deviation
	float deviation2 = findDeviation ( input1 , input2 , input3, input4 , mean2 ) ;
	
	//Outputting the original data into a different file
	outfile << input1 << "\n" << input2 << "\n" << input3 << "\n" << input4 << "\n" ; 
	
	//Outputting the mean calculated from the first file into the same file as before 
	outfile << "The mean is : " << mean2 << "\n" ;
	
	//Outputting the deviation calculated from the first file into the same file as before
	outfile << "The deviation is : " << deviation2 << "\n" ;
	
	infile.close() ; //Closing the original file
	outfile.close() ; //Closing the new file with all the calculations

	return 0;
}

//Definition of the function
float findMean ( int &input1 , int &input2 , int &input3 , int &input4 ) {
	
	//Adding the inputs together to get the sum
	float sum = input1 + input2 + input3 + input4 ; 
	
	//Dividing the sum by the amount of numbers to get the mean
	float mean = sum/4 ; 
	
	return mean ; //Returning the mean to use for other calculations and add to the new file
}

//Defintion of the function
float findDeviation ( int &input1 , int &input2 , int &input3 , int &input4 , float &mean2 ) {
	
	//Substracting the mean from all the inputs to find the difference of each one
	float diff1 = input1 - mean2 ;
	float diff2 = input2 - mean2 ;
	float diff3 = input3 - mean2 ;
	float diff4 = input4 - mean2 ;
	
	//Squaring the differences to get the squared difference
	diff1 = diff1*diff1 ;
	diff2 = diff2*diff2 ;
	diff3 = diff3*diff3 ;
	diff4 = diff4*diff4 ;
	
	//Adding the squared differences to get the sum
	float diffSum = diff1 + diff2 + diff3 + diff4 ;
	
	//Dividing the sum by the amount of numbers to get the variance
	float variance = diffSum/4 ;
	
	//Square rooting the variance to get the deviation
	float deviation = sqrt(variance) ;
	
	return deviation ; //Returning the deviation to use later and add to the new file
}
	
	
	
	
	
	
	

