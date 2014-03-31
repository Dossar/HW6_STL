/* 
 * File:   HW6_STL.cpp
 * Author: Roy Van Liew and Saqib Zahid
 *
 * Last Modified on March 31, 2014, 10:49 AM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack> // C++ library for stack STL
#include <map> // C++ library for map STL
#include <queue> // C++ library for queue and priority queue STLs
#include <list> // C++ library for list
#include <vector> // C++ library for vectors

using namespace std;

/*
 * BEGIN DEFINING CLASS MATRIX. To reduce clutter, just use 2x2 matrix.
 */
class Matrix
{
        public:
                Matrix(int d = 0); // Default constructor
                ~Matrix(); // Destructor
                friend ostream& operator <<(ostream& out, const Matrix& Mat);
                friend bool operator ==(const Matrix& Mat1, const Matrix& Mat2);
                friend bool operator <(const Matrix& Mat1, const Matrix& Mat2);
        private:
                const static int n=2; // To reduce clutter we just have 2x2 matrices.
                int data[n][n];
                
    
};
// Matrix Constructor.
Matrix::Matrix(int d)
{
    int i, j;
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n ; j++)
            data[i][j] = d;
    }
}
// Matrix Destructor
Matrix::~Matrix()
{
}
// Overloaded output operator
ostream& operator <<(ostream& out, const Matrix& Mat){
    int i, j;
    for (i = 0; i < Mat.n ; i++) {
        for (j = 0; j < Mat.n ; j++)
            cout << Mat.data[i][j] << " ";
        cout << endl; // Newline for next row
    }
}
// Overloaded equality operator
bool operator ==(const Matrix& Mat1, const Matrix& Mat2){
    
        int i, j;
        for (i = 0; i < Mat1.n ; i++) {
            for (j = 0; j < Mat1.n ; j++) {
                if (Mat1.data[i][j] != Mat2.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    
}
// Overloaded less than operator
bool operator <(const Matrix& Mat1, const Matrix& Mat2){
    
        int i, j;
        for (i = 0; i < Mat1.n ; i++) {
            for (j = 0; j < Mat1.n ; j++) {
                if (Mat1.data[i][j] < Mat2.data[i][j]) {
                    return true;
                }
            }
        }
        return false;
    
}
/*
 * END DEFINING CLASS MATRIX.
 */

/*********************
 GENERALIZED STACK STL FUNCTION
 stackVar is used as a general type here. The type is dependent on what's passed to the function
 *********************/
template<class stackVar>
void stackTest(stackVar& A, stackVar& B, stackVar& C) {
    
    cout << "========== STACK STL TESTING ==========\n" << endl;
    
    // Create first stack and push the two passed types.
    stack<stackVar> stack1;
    cout << "Pushing to stack:" << endl;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    stack1.push(A);
    stack1.push(B);
    stack1.push(C);
    
    // Using copy constructor from stack STL.
    stack<stackVar> stack2(stack1);
    if( stack1 == stack2 )
        cout << "\nMade a copy of the stack.\n" << endl;
    
    // Pop top element of first stack, output what was popped.
    stackVar top1 = stack1.top();
    stackVar top2 = stack2.top();
    cout << "Popping the top element of first stack:" << endl;
    stack1.pop();
    cout << top1 << endl;
    
    // Show that the two stacks are not equal in size now.
    if( stack1.size() != stack2.size () )
        cout << "\nThe stacks are not the same size due to the pop.\n" << endl;
    
    // Using assignment operator from stack STL, make first stack equal the second stack. 
    cout << "Making first stack equal to the second stack." << endl;
    stack1 = stack2;
    if( stack1.size() == stack2.size() )
        cout << "Both stacks are now the same size." << endl;
    if( !stack1.empty() && !stack2.empty() )
        cout << "Both stacks are not empty.\n" << endl;
    
}

/*********************
 GENERALIZED MAP STL FUNCTION
 mapVar is used as a general type here. The type is dependent on what's passed to the function
 *********************/
template<class mapVar>
void mapTest(mapVar& A, mapVar& B, mapVar& C) {
    
    cout << "========== MAP STL TESTING ==========\n" << endl;
    
    cout << "Creating first map with two key-value pairs." << endl;
    map<const char*, mapVar> map1;
    map1["one"] = A;
    map1["two"] = B;
    map1["three"] = C;
    cout << "There are " << map1.count("one") << " keys \"one\" with value:\n" << map1["one"] << endl;
    cout << "There are " << map1.count("two") << " keys \"two\" with value:\n" << map1["two"] << endl;
    cout << "There are " << map1.count("three") << " keys \"three\" with value:\n" << map1["three"] << endl;
    
    cout << "\nMaking a second map as a copy of the first map." << endl;
    map<const char*, mapVar> map2(map1);
    
    if( map1 == map2 )
        cout << "Both maps are the same." << endl;
    
    // This is for saving original map to reinitialize after modification
    map<const char*, mapVar> tempMap = map2;
    
    // Erase the same key in both maps. In this case, it was in order.
    cout << "Removing the key \"one\" with this value in both maps:\n" << map1["one"] << endl;
    map1.erase( map1.begin() );
    map2.erase( "one" );
    
    if( map1 == map2 )
        cout << "\nElement removed in both maps, both maps are the same.\n" << endl;
    
    tempMap.swap( map1 );
    if( tempMap == map2 )
        cout << "Swapped first map with temporary map. Temporary map == second map now." << endl;
    
    cout << "Map element \"two\" of first map is:\n" << map1["two"] << "\n" << endl;
    
    cout << "The size of the first map is " << map1.size() << " after swap." << endl;
    
    map2.clear();
    if( map2.empty() )
        cout << "Emptied the second map.\n" << endl;
    
}

/*********************
 GENERALIZED PRIORITY QUEUE STL FUNCTION
 pqVar is used as a general type here. The type is dependent on what's passed to the function
 *********************/
template<class pqVar>
void pqTest(pqVar& A, pqVar& B, pqVar& C) {

    cout << "========== PRIORITY QUEUE STL TESTING ==========\n" << endl;
    
    // Create first priority queue and insert 3 elements by priority.
    priority_queue<pqVar> pq1;
    pq1.push(C);
    pq1.push(A);
    pq1.push(B);
    cout << "Order in which push happens does not matter for PQ. Top element:\n" << pq1.top() << endl;
    
    // Make pq2 a copy of the first priority queue pq1.
    cout << "Making a copy of PQ 1." << endl;
    priority_queue<pqVar> pq2(pq1);
    if( pq1.size() == pq2.size() )
        cout << "Both PQ 1 and PQ 2 have " << pq1.size() << " elements." << endl;
    
    // Pop and display the elements removed by priority.
    int i;
    for( i = 0 ; i < 3 ; i++ ) {
        cout << "Popping element from top of PQ 1:\n" << pq1.top() << endl;
        pq1.pop();
    }
    
    if( pq1.empty() )
        cout << "PQ 1 is now empty." << endl;
    
    pq1 = pq2;
    if( !pq1.empty() )
        cout << "Reassigned PQ 1 to PQ 2's contents. It is no longer empty.\n" << endl;
    
}

/*********************
GENERALIZED QUEUE STL FUNCTION
qVar is used as a general type here. The type is dependent on what's passed to the function
*********************/
template<class qVar>
void qTest(qVar& A, qVar& B, qVar& C) {

	cout << "========== QUEUE STL TESTING ==========\n" << endl;

	// Create queue with 3 elements. 
	queue<qVar> q1;
	q1.push(A);
	q1.push(B);
	q1.push(C);
	cout << "Front Element of the Queue:\n" << q1.front() << endl;

	// Make Queue 2 a copy of Queue 1
	cout << "Making a copy of Queue 1 into Queue 2." << endl;
	queue<qVar> q2(q1);
	if (q1.size() == q2.size())
		cout << "Both Queue 1 and Queue 2 have " << q1.size() << " elements." << endl;

	// Pop and display the elements 
	int i;
	for (i = 0; i < 3; i++) {
		cout << "Popping element from front of Queue 1:\n" << q1.front() << endl;
		q1.pop();
	}

	if (q1.empty() && !q2.empty())
		cout << "Queue 1 is now empty, but Queue 2 is not." << endl;

	q1 = q2; // Assign queue q1 to queue q2's contents
	if (!q1.empty())
		cout << "Reassigned Queue 1 to Queue 2's contents. It is no longer empty.\n" << endl;

}

/*********************
GENERALIZED LIST STL FUNCTION
listVar is used as a general type here. The type is dependent on what's passed to the function
*********************/
template<class listVar>
void listTest(listVar& A, listVar& B, listVar& C) {

	cout << "========== LIST STL TESTING ==========\n" << endl;

	// Put in three elements.
	list<listVar> list1;
	list1.push_front(B); // B will wind up being in the middle here.
	list1.push_back(C); // Put C in the back.
	list1.insert( list1.begin() , A ); // Put A in the front.
        cout << "Created first list. First and Last Elements (Respectively):" << endl;
        cout << list1.front() << endl;
        cout << list1.back() << endl;
        
        list1.erase( list1.begin() ); // Remove first element.
        cout << "Removed first element. Now the first element is:\n" << list1.front() << endl;
        
        list<listVar> list2(list1); // Create a copy
        list<listVar> tempList = list1;
        if( list1 == list2 )
            cout << "Created a copy of the first list." << endl;
        
        // Both of these do the same thing (clear the entire list)
        list1.clear();
        list2.erase( list2.begin(), list2.end() );
        if( list1.empty() && list2.empty() )
            cout << "Cleared both lists. They are now empty." << endl;
        
        list1 = tempList;
        
        int i;
        for( i = 0 ; i < list1.size()+1 ; i++ ){
            list1.pop_front();
        }
        if( list1.empty() )
            cout << "Popped everything in first list.\n" << endl;


}

/*
 * 
 */
int main() {
    
    // Give values to the types we'll use in the STL tests
    Matrix Mat1, Mat2(1), Mat3(2);
    string str1 = "ABC", str2 = "DEF", str3 = "GHI";
    char char1 = 'J', char2 = 'K', char3 = 'L';
    int int1 = 2, int2 = 4, int3 = 6;

    // Stack STL testing
    stackTest(Mat1,Mat2,Mat3);
    stackTest(str1,str2,str3);
    // stackTest(char1,char2,char3);
    stackTest(int1,int2,int3);
    
    // Map STL testing
    mapTest(Mat1,Mat2,Mat3);
    mapTest(str1,str2,str3);
    // mapTest(char1,char2,char3);
    mapTest(int1,int2,int3);
    
    // Priority Queue STL testing
    pqTest(Mat1,Mat2,Mat3);
    pqTest(str1,str2,str3);
    // pqTest(char1,char2,char3);
    pqTest(int1,int2,int3);

    // Queue STL testing
    qTest(Mat1, Mat2, Mat3);
    qTest(str1, str2, str3);
    // qTest(char1, char2, char3);
    qTest(int1, int2, int3);

    // List STL testing
    listTest(Mat1, Mat2, Mat3);
    listTest(str1, str2, str3);
    // listTest(char1, char2, char3);
    listTest(int1, int2, int3);                  

  return 0;
  
}

