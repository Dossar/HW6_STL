/* 
 * File:   HW6_STL.cpp
 * Author: Roy Van Liew and Saqib Zahid
 *
 * Last Modified on March 25, 2014, 12:55 PM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack> // C++ library for stack STL
#include <map> // C++ library for map STL
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
        private:
                int data[2][2];
                
    
};
// Matrix Constructor.
Matrix::Matrix(int d)
{
    int i, j;
    for (i = 0; i < 2 ; i++) {
        for (j = 0; j < 2 ; j++)
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
    for (i = 0; i < 2 ; i++) {
        for (j = 0; j < 2 ; j++)
            cout << Mat.data[i][j] << " ";
        cout << endl; // Newline for next row
    }
}
/*
 * END DEFINING CLASS MATRIX.
 */

/*********************
 GENERALIZED STACK STL FUNCTION
 stackVar is used as a general type here. The type is dependent on what's passed to the function
 *********************/
template<class stackVar>
void stackTest(stackVar& A, stackVar& B) {
    
    cout << "========== STACK STL TESTING ==========\n" << endl;
    
    // Create first stack and push the two passed types.
    stack<stackVar> stack1;
    cout << "Pushing to stack:" << endl;
    cout << A << endl;
    cout << B << endl;
    stack1.push(A);
    stack1.push(B);
    
    // Using copy constructor from stack STL.
    stack<stackVar> stack2(stack1);
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
void mapTest(mapVar& A, mapVar& B) {
    
    cout << "========== MAP STL TESTING ==========\n" << endl;
    
    cout << "Creating first map with two key-value pairs." << endl;
    map<const char*, mapVar> map1;
    map1["one"] = A;
    map1["two"] = B;
    cout << "There are " << map1.count("one") << " keys \"one\" with value:\n" << map1["one"] << endl;
    cout << "There are " << map1.count("two") << " keys \"two\" with value:\n" << map1["two"] << endl;
    
    cout << "\nMaking a second map as a copy of the first map." << endl;
    map<const char*, mapVar> map2(map1);
    
    if( map1 == map2 )
        cout << "Both maps are the same." << endl;
    
    // This is for reinitializing the maps
    map<const char*, mapVar> tempMap = map2;
    
    // Erase the same key in both maps.
    cout << "Removing the key \"one\" that had the following element in both maps:\n" << map1["one"] << endl;
    map1.erase( map1.begin() );
    map2.erase( "one" );
    
    if( map1 == map2 )
        cout << "\nElement removed in both maps, both maps are the same.\n" << endl;
    
    
    tempMap.swap( map1 );
    if( tempMap == map2 )
        cout << "Swapped first map with temporary map. Temporary map == second map now." << endl;
    
    cout << "Map element \"two\" of first map is:\n" << map1["two"] << "\n" << endl;
    
    cout << "The size of the first map is " << map1.size() << "." << endl;
    
    map2.clear();
    if( map2.empty() )
        cout << "Emptied the second map.\n" << endl;
    
    
}


/*
 * 
 */
int main() {
    
    // Give values to the types we'll use in the STL tests
    Matrix Mat1, Mat2(1);
    string str1 = "ABC", str2 = "DEF";
    char char1 = 'G', char2 = 'H';
    int int1 = 2, int2 = 3;

    // Stack STL testing
//    stackTest(Mat1,Mat2);
//    stackTest(str1,str2);
//    stackTest(char1,char2);
//    stackTest(int1,int2);
    
    // Map STL testing
//    mapTest(Mat1,Mat2);
    mapTest(str1,str2);
    mapTest(char1,char2);
    mapTest(int1,int2);
    

                    


  return 0;
  
}

