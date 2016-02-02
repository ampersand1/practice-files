/*
 Using recursion, find the largest element in a vector of integer values.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 A smaller vector is created as long as its size is greater than 1.
 Then, maxVal is assigned at size = 1.  
 maxVal is compared to the current values and assigned accordingly.
 
 @param values is the array of values that the function must sort through.
 @return maxVal is the maximum value of the array.
 */
int maximum(vector<int> values){
    //doesn't care about repeats in arrays

    int maxVal;
    unsigned long valuesLength = values.size();
    int currentVal= values[valuesLength-1];
    
    if (valuesLength > 1){
    vector<int> b(&values[0],&values[valuesLength-1]);
    int bVal = maximum(b);
    if(bVal >= currentVal){
            maxVal = bVal;
    }else{maxVal = currentVal;}
        }else{
            maxVal=values[0];
            }
    return maxVal;
}



int main()
{  //I'm going to use a seed to create a vector of random values.
    int seedN = 0;  //seedN stands for seed number;
    int lowerB, upperB;
    int vector_size;
    cout<< "seed?:";
    cin >> seedN;
    srand(seedN);
    
    
    //user picks upper/lower bound, number of numbers, and the random seed.
    cout << "How many numbers to sort?:";
    cin >> vector_size;
    
    cout << "Lower Bound?:";
    cin >> lowerB;
    
    cout << "Upper Bound?:";
    cin >> upperB;
    
    vector<int> variableslist(vector_size);
    for(int i =0; i < vector_size ; i++){
        variableslist[i] = lowerB+ rand()%(upperB-lowerB+1);
        cout << variableslist[i] << endl;
    }
    
    //apply recursion function
    
    cout << "The maximum is :"  <<  maximum(variableslist);
    
    return 0;
}

