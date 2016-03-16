/*******************************************************************
 Modified Linked List project. 
 Several programming exercises from Big C++ chapter 12 in one file.
 
 Maybe a school administrator may more or less alphabetize names and remove every second name to put into a second class.
 
P12.1: Function that removes every second value from a linked list.
 (and puts them in another linked list).

P12.3: Write a function "sort" that sorts the elements of a linked list (without copying them into a vector).
 
 
********************************************************************/

#include <iostream>
#include <string>
#include <list>
#include <fstream>


using namespace std;

/*
@param namesList is the original linked list created in the main().
 
Removes every second value from a linked list.
make sure that the last character in the textfile isn't a carriage return or that there is 
a line of space after the last entry.
 */


void newclass(list<string>& namesList){
    list<string>::iterator pos, second;
    list<string>::iterator endcondition;
    second = namesList.begin();
    second++;
    

    for(pos=namesList.begin(); pos != namesList.end(); pos++){
            //keep for loop iterator separate from iterator within for loop body.
         endcondition=namesList.end();
        if(second != endcondition){
            second=namesList.erase(second);
            second++;
                }

        }
    
}




/*
@param namesList is the original linked list created in the main().
 
Uses selection sort algorithm to sort linked list.
Only by first letter in list of names or words.
One could just do namesList.sort(), but this is an exercise.
 */

 void selection_sort(list<string>& namesList){
    list<string>::iterator next;
     for (next = namesList.begin(); next != namesList.end(); next++){
         list<string>::iterator min_pos;
         list<string>::iterator pos;
         min_pos = next;
         string min = *next;
         string current = *next;
         
        //Finds value of minimum and the position of minimum value.
        for(pos = next; pos != namesList.end() ; pos++){
            string pos_val = *pos;
            if(pos_val[0] < min[0]){   //alphabetizes one letter only.
            min_pos = pos;
            min = pos_val;
                }
        }

         //Essentially swaps the position of the values.
        if (min_pos != next){
            min_pos = namesList.insert(min_pos, current);
            min_pos++;
            min_pos = namesList.erase(min_pos);
            
            next = namesList.insert(next, min);
            next++;
            namesList.erase(next);
                }
     }
}
 

int main()
{
    
    //Use file of names located on desktop and fills linked list called "nameslist" where each name is a node.
    
    ifstream infile;
    list<string> nameslist;
    string name;
    infile.open("/Users/jasmin_shin/desktop/work_file/portfolio/popularnames.txt");
 
    //file opening error
    if(infile.fail()){
        cout << "file failed to open";
        return 1;
    }
    
    while(!infile.eof()){  //works better than infile >> ch
        getline(infile, name);
        nameslist.push_back(name);
    }
    
    
    list<string>::iterator pos;
    
    for(pos=nameslist.begin(); pos != nameslist.end(); pos++){
        cout << *pos << "\n";
        
    }
    
    nameslist.sort();
    //selection_sort(nameslist);
    
    cout << "\n";
    
    for(pos=nameslist.begin(); pos != nameslist.end(); pos++){
        cout << *pos << "\n";
    }
    
    cout << "\n";
    
    newclass(nameslist);
    
    for(pos=nameslist.begin(); pos != nameslist.end(); pos++){
        cout << *pos << "\n";
    }
    
    
    
    return 0;
}

