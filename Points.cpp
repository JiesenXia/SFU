/* Points.cpp - D200 */

#include <iostream>
#include "Points.hpp"
#include <algorithm>

using namespace std;

// Constructor: Constructs a "Points" object that has no points yet
//              (numOfPoints = 0), that has an array "points" not yet allocated
//              (points = NULL), but can contain up to 10 points (arraySize = 10)
//              when it will be allocated.              
Points::Points() : numOfPoints(0), points(NULL), arraySize(10){

}

// Destructor 
Points::~Points() {

  if ( points != NULL ) {
    delete points; // Note: this is deleting an array, has to be delete [] !
    points = NULL;
  }
    
  numOfPoints  = 0; 
  arraySize = 0;
}


// Description:  Insert "thePoint" at the front of the array.
//               Returns true if the point has successfully been inserted,
//               otherwise returns false.
// Requirements: The array is not ordered.
//               Duplicated points are allowed in the array.
//               If the array is full, you need to decide what to do, 
//               but know that the "arraysize" cannot be changed.
//               The first time this method is called, it must allocate
//               memory to the array "points". 
//               This method does not print and only has one "return" statement. 
//               You must implement this method without using "break" statements.
//               No further instructions are given. It is for you to decide 
//               what to do based on what you have learnt this semester and 
//               your software development experience.
bool Points::prepend( int thePoint ) {
	bool resultState = true;
	// if we haven't allocated any memory yet
	if (points == NULL) {
		points = new int[arraySize];
		if(points == NULL) {
			resultState = false;
		} else {
			points[numOfPoints] = thePoint;
			++numOfPoints;
		}
	} else {
		// since arraysize cannot be modified, we can allocate 10 more memory each time
		if (numOfPoints % arraySize == 0) {
			int* new_points = new int[numOfPoints + arraySize];
			if(new_points == NULL) {
				resultState = false;
			} else {

				new_points[0] = thePoint;
				// copy all points to the new points
				for(unsigned int i = 1; i < numOfPoints + 1; ++i) {
					new_points[i] = points[i-1];
				}

				// release the old memory
				delete [] points;

				points = new_points;
				++numOfPoints;
			}
		} else {
			points[numOfPoints] = points[0];  // copy the front point to the end
			points[0] = thePoint;  // insert the point at the front
			++numOfPoints;  // increase the number of points
		}
	}
	
	return resultState;
}


// Description:  Returns the number of Points in the array that have even values.
//               Return 0 if the array contains no even points.
// Requirements: The array must not be modified. 
//               This method does not print and only has one "return" statement. 
//               You must implement this method without using "break" statements.
//               No further instructions are given. It is for you to decide 
//               what to do based on what you have learnt this semester and 
//               your software development experience.
unsigned int Points::evenPointCount( ) {
	unsigned int count = 0;
	for(unsigned int i = 0; i < numOfPoints; ++i) {
		if(points[i] % 2 == 0) {
			++count;
		}
	}
	return count;
  
}

// Description: Prints the content of this object.
void Points::printPoints( ) {
    
  cout << "There are " << numOfPoints << " points in the array." << endl;
  cout << "These points are: ";

  for ( unsigned int index = 0; index < numOfPoints; index++ ) {
    if ( index < numOfPoints-1 ) cout << points[index] << ", ";
    else cout << points[index] << endl;
  }

  return;
}

// Don't worry about this method.
// You are not to use it as part of your Lab Quiz 4!
void Points::sorting() {
	
  sort(points, points + numOfPoints);
	
  return;
}

