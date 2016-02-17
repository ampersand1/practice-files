/*
 Implements the playfair cipher encryption.
 -Modified Big C++ text problem.
 
 -Opens up and Closes files.
 -Writes encryption to file.
 -Removes j uses i instead.
 -Adds Q to the end of phrase with odd number of letters.
 -Doesn't work well with capital letters.
 -leaves punctuation in place.
 -path to cpp_files on my desktop was added for testin convenience.  
 (feel free to change this if you want to test it on your computer)


 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "matrix.h"


using namespace std;

int main(int argc, char* argv[]){
   
    string filename;
    ifstream infile;
    ofstream outfile;
    string cipher;
    string keyword;
    string minuskeyword;

    
    /*
    Command line
     
    no other options than:
    program_name -k(keywordname) textfile_name
    program_name -d -k(keywordname) textfile_name
     
     */
    /*
     bool decrypt = false;
     for(i= 1; i< argc; i++){
        string arg=argv[i];
        if(arg[0] == '-'){
            if(arg[1]=='k'){
                keyword = arg.substr(2);
            }else{
                decypt = true;
            }
        }else{
            filename= arg;
            }
     
     */
    
    
    //finds file to encrypt, creates file objects, opens them.
    
    string filenameextension = "/Users/jasmin_shin/Desktop/cpp_files/";
    //must end file names in .txt
    
    cout << "What is the name of the file? (within cpp_files)";
    getline(cin, filename);
    string infilename = filenameextension + filename;
    string outfilename = filenameextension + filename + "out.txt";
    
    infile.open(infilename.c_str());
    outfile.open(outfilename.c_str());
    
 
    
    if(infile.fail()){
        cout<< "error opening";
        return 1;
    }
    
    
    //encrypts file and puts texts in -out.txt file.
    
    cout << "Keyword?: ";
    getline(cin, keyword);
    
    minuskeyword= abc_string(keyword);
    cipher= remove_repeats(keyword)+ minuskeyword;
    cout << cipher << endl;
    encrypt_file(infile, outfile, cipher);
    
    
    infile.close();
    outfile.close();
    return 0;
    
}


