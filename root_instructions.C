/***
 Instructions for friends on how to use Root.
 
 
 Open up terminal if you are on mac or linux.
 IDK on Windows.  Just click the icon for ROOT I guess.
 If you are on linux or mac, you should copy this macro file to the folder "macros" in the parent directory "root."  
 Create macro on your favorite text editor i.e. Xcode.
 Name it Name.C
 
:::terminal commands:::
 
source path_to_parent/root/bin/thisroot.sh
root 

 on root do: .x Name.C
 
:::good to know:::
cd
ls
pwd
 
***/

{
    
    //no need header files: they are loaded automatically when you open root.
    
    
    FILE *f = fopen("Users/adlfaj/adjflajf;/data.txt ","r");  //path to file.
    
    Double_t x[100],y[100],z[100],a[2000];  //arrays.  adjust as needed.
    
    while(!feof(f)){
        fscanf(f,"%lf \n", &x[i]);
         //depends on textfile format.  2 columns or 4 columns what not.
        i++;
        
    }
    
    
    for(int i=0; i<293234; i++){
    
        //apply function to data. like add 1 to all y values.
        
    }
    
    
    //xy graphs
    Tgraph g1(500,x,y);
    g1->Draw();
    
    //histograms
    h->Fill(x);
    TH1F* h= new TH1F("h", "example histogram", 100,0,5);
    h->Draw();
    
    
    // when the c1 canvas opens up look for "fit panel."
    
    
}






