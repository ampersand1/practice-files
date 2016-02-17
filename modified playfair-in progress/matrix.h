//
//  matrix.h
//  p9.5
// Jasmin Shin


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


#ifndef p9_5_matrix_h

#define p9_5_matrix_h
/*
 remove repeat letter from keyword string.  And takes out j's.
 @param inputstring : is the keyword string user input.
 @reutrn new_keyword: is the old keyword without js and without repeating letters.
 
 */

string remove_repeats(string inputstring){
    string new_keyword;
    new_keyword.push_back(inputstring[0]);  //since new_keyword has no size, I guess you have to push_back variables and not simply replace them.
    for (int i =1; i < inputstring.size(); i++){
        int k = 0;
        char ch = inputstring[i];
        
        for(int j= i; j > 0 ; j--){
            if(ch == inputstring[j-1]){
                k++;
            }
        }
        
        if(k == 0){
            new_keyword.push_back(inputstring[i]);
            
        }
    }
    
    return new_keyword;
}


/*
 Takes whatever is in inputstring out of the abc string.
 @param inputstring: is the user input keyword necessary for encryption.
 @return newabc: is the new abc without the letters in the keyword.
 
 */
string abc_string(string inputstring){
    string abc = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<inputstring.size(); i++){
        for(int j=0; j< abc.size(); j++){
            if(inputstring[i]==abc[j]){
                abc[j]= 'j';
            }
            
        }
    }
    
    string newabc;
    for(int i=0; i< abc.size(); i++){
        if(abc[i] != 'j'){
            newabc.push_back(abc[i]);
            
        }
    }
    
    return newabc;
}


/*
 adds a q between two repeat letters.    ///DOESN'T REMOVE Js.
 @param the original phrase.
 @returns the phrase with a q in between two letters thus lengthening the string.
 */

vector<char> repeatletters(vector<char> phrase){
    vector<char> newphrase;
    
    for(int i=0; i< phrase.size();i++){
        newphrase.push_back(phrase[i]);
        
        if(phrase[i]==phrase[i+1]){
            newphrase.push_back('q');
        }
        
    }
    return newphrase;
    
}

/**************************************************************
 Playfair matrix
 
 Doesn't work with capital letters! 
 Well it doesn't include that in the encryption at least.
 **************************************************************/


vector<char> encrypt(vector<char> phrase, string password){
    
    int k =0;
    
    char playfair[5][5];
    for(int i =0; i < 5; i++){
        for(int j=0; j < 5; j++){
            playfair[i][j]= password[k];
            k++;
        }
    }
    
    char inchar;
    string twoletter;
    vector<char> newphrase(phrase.size());
    char newchar1;
    char newchar2;
    int pos1 =0, pos2=0;
    
    for(int i=0; i < phrase.size(); i++){
        int a1, a2, b1, b2;
        inchar = phrase[i];
        
        if('a' <= inchar  && inchar <= 'z'){
            if(twoletter.size() < 1){
                twoletter.push_back(inchar);
                pos1=i;
                }
            else{
                twoletter.push_back(inchar);
                pos2=i;
                }
            
            /*}
        else if('A' <= inchar  && inchar <= 'Z'){
            twoletter.push_back(phrase[i]-32);
        */
        }else{
            newphrase[i] = phrase[i];  // unsure if work // to put in the stuff like commas and periods.
        }
        
        //!!!!!!!!! check this out   !!
        if(i== phrase.size()-1 && twoletter.size() == 1){
            twoletter.push_back('q');
        }
        
        if(twoletter.size() == 2){
            
            for(int i =0; i<5 ; i++){
                for(int j= 0; j< 5; j++){
                    if(playfair[i][j] == twoletter[0]){
                        a1=i;
                        a2=j;
                        
                    }
                    
                    if(playfair[i][j] == twoletter[1]){
                        b1 = i;
                        b2 = j;
                        
                    }
                }
            }
            
            if(b1 == a1){  //problem with going to the right 1 more from the 5th position)
                if( a2 == 5 || b2 ==5){
                    newchar1 = playfair[a1][0];
                    newchar2 = playfair[b1][0];
                }else{
                    newchar1 = playfair[a1][a2+1];
                    newchar2 = playfair[b1][b2+1];
                }
            }
            if(a2==b2){
                if( a1 == 5 || b1 ==5){
                    newchar1 = playfair[0][a2];
                    newchar2 = playfair[0][b2];
                }else{
                    newchar1 = playfair[a1+1][a2];
                    newchar2= playfair[b1+1][b2];
                }
            }
            if(a1 != b1 && a2 != b2){
                
                newchar1 = playfair[a1][b2];
                newchar2= playfair[b1][a2];
            }
            newphrase[pos1]=newchar1;
            newphrase[pos2]=newchar2;
            twoletter.clear();
        }
    }
    
    return newphrase;
}



void encrypt_file(istream& in, ostream& out, string password){
    vector<char> phrase;
    char ch;
    vector<char> encrypted;
    while(in >> ch){
        phrase.push_back(ch);
    }
    
    phrase=repeatletters(phrase);
    
    for(int i=0; i<phrase.size();i++){
        cout<<phrase[i];
     }
     
     
    
    
    encrypted = encrypt(phrase, password);
    for(int i=0; i < encrypted.size(); i++){
        out.put(encrypted[i]);
    }
}


//void decrypt_file(istream& in, ostream& out, string password){
//rather than encrypt file.  It should encrypt by letter and turn that into the textfile.



#endif
