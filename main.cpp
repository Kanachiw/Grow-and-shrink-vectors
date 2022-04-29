#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// defining the global variable
double *v;
int count;
int size;
// calling all the functions in the header
void Initialize();
void Shrink();
void PrintVector();
void Grow();
void RemoveElement();
void InsertElement();
void Finalize();
void AddElement();

// main function to run the function definitions
int main(){
    int user_input;
    Initialize();
    do{

        cout<<"Main menu: \n1. Print the array \n2. Append element at the end \n3. Remove last element \n4. Insert one element \n5. Exit \n \nSelect an option: _"<<endl;
        cin >> user_input;
        switch (user_input)
        {
            case 1: cout << "User Input: Print the array" << endl;
                PrintVector();
                break;
            case 2: cout << "Append element at the end" << endl;
                AddElement();
                break;
            case 3: cout << "Remove last element" << endl;
                RemoveElement();
                break;
            case 4: cout << "Insert one element" << endl;
                InsertElement();
                break;
            case 5: cout << " Exit" << endl;
                Finalize();
                break;
            default: cout << "Next time please choose either number 1, 2,3,4 or 5\n" << endl;
                break;
        }
    }
    while (user_input != 5);
    return 0;

}
//function definition
void Initialize() {
    size = 2;
    v = new double[size];
    v[0] = 0;
    v[1] = 0;
}
void PrintVector() {
    if (count==0) {
        cout<< "There are no elements in this array";
    }
    else{
        // Print only values that have user input
        for( int i=0; i<count;i++){
            cout<<"v["<<i<<"] = "<< v[i]<<" ";
        }
    }
    cout<<"\n"<<endl;
}
void Grow() {
    // initialize the new pointer vector nv
    double *nv;
    int  nsize = size*2;
    // define the size of double
    nv= new double [nsize];

    // using the old size loop through and store the v[i] values in nv[i]
    for( int i=0; i<=count;i++){
        if( i<=size) {
            nv[i] = v[i];
        }
            // store new values with a filler of 0
        else {
            nv[i]= 0;
        }
    }

    //Print statements
    cout<< "Vector grown \nPrevious capacity: "<< size<<" Elements\nNew capacity: "<<nsize<< " Elements"<<endl;

    //doubling the size variable + count variable

    size= nsize;

    // saving nv as v
    v=nv;
    cout<< "count: "<< count<< " size: " << size<<endl;

}
void AddElement() {
    int user_input;
    cout<< "Enter new Element"<<endl;
    cin>>user_input;
    if (count== size){
        Grow();
        v[count]= user_input;
        count+=1;
    }

    else{
        v[count]= user_input;
        count+=1;

    }
    PrintVector();



}
void RemoveElement() {
    if (count==0){
        cout<<"There are no elements in this array to be removed\n"<<endl;
    }
    else {
        v[count] = 0;
        count -= 1;

        if ((count / size) <= 3 / 8) {
            Shrink();
        }
        PrintVector();
    }

}
void Shrink() {
    cout<< "Vector Shrunk(less than 30%) \nPrevious capacity:"<<size<<endl;
    size = 0.5 * size;
    cout<<"New Capacity: "<< size<< endl;

}
void InsertElement() {
    int index_num, index_val;
    cout<< "Enter index of the new element _"<<endl;
    cin>> index_num;
    cout<< "Enter  value of the new element_"<<endl;
    cin>> index_val;

    // if number is greater or equal to size we have to grow the function
    if (index_num>=size) {
        while (size < index_num) {
            Grow();
        }
    }
    // check to see if count is greater or less than the value
    if (count<index_num) {
        // if count is less that current replace index_num with count
        v[index_num] = index_val;
        for (int i = count; i < index_num; i++) {
            v[i] = 0;
            count += 1;
        }
        count += 1;

    }
    else {

        for (int i = (count + 1); i >= index_num; i--) {
            v[i] = v[i - 1];

        }
        v[index_num]= index_val;
        count += 1;

    }
    PrintVector();

}


void Finalize() {
    delete[] v;
}

