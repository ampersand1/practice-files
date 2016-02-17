//
//  playfair.h
//  p9.5
//
//  Created by jasmin on 2/11/16.
//  Copyright (c) 2016 bigc++. All rights reserved.
//

#ifndef p9_5_playfair_h

#define p9_5_playfair_h
#include <vector>

using namespace std

/**************************************************************
 Playfair matrix
 
 *Doesn't work with capital letters.
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
    
    
    for(int i=0; i < phrase.size(); i++){
        int a1, a2, b1, b2;
        inchar = phrase[i];
        
        
        if('a' <= inchar  && inchar <= 'z'){
            if(twoletter.size() == 0){
                twoletter.push_back(phrase[i]);
                
            }else{
                newphrase[i] = phrase[i];  // unsure if work // to put in the stuff like commas and periods.
            }
            
            
            
            if(i== phrase.size()-1 && twoletter.size() == 1){
                twoletter.push_back('q');
            }
            
            
            /*
             vector of characters only.
             and
             another function returns the vector of symbols and their positions.
             have it take into account capital letters
             pos1=i;
             }else{
             twoletter.push_back(phrase[i]);
             }
             
             
             */
            
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
                newphrase.push_back(newchar1);
                newphrase.push_back(newchar2);
                twoletter.clear();
                
            }
        }
        
        return newphrase;
    }


#endif
