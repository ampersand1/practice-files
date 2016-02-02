//
// lab3.C
// alpha coefficients
//
// Created by jasmin on 3/4/15.
//
//


{
    /* opening up data file*/
   FILE *f = fopen("/Users/jasmin_shin/desktop/180a/lab3/uncorrected-p_vs_c.txt","r");
    
    
    
    //part 1  -coefficients
    
    /*************************************************************/
     
    //p: momentum
    //c: corrected counts
     
    TF1 *f1 = new TF1("f1","0.5507*Gaus(x,446.3,162.4)",0,1000);
    TF1 *f2 = new TF1("f2","0.464423*Gaus(x,984.786,11.7359)",800,1500);
    TF1 *f3 = new TF1("f3","0.110406*Gaus(x,1021.32,9.3864)",900,1500);
    
    
    
    Double_t p[200],c[200],p_errors[200];
    

    Int_t i = 0;
    
    while (!feof(f)){
        fscanf(f,"%lf %lf \n",&p[i],&c[i]);
        i++;
    }
    
    
    for(int i=0; i < 200 ;i++){
        p_errors[i]= sqrt(c[i]);
    }
    
    //graph essentials
    TGraphErrors g1(62,p,c, );
    g1.GetXaxis()->SetTitle("P (kev/c)");
    g1.GetYaxis()->SetTitle("counts/P");
    g1->SetTitle("Corrected Momentum Spectrum");
    
    
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(1);
    g1->Draw("ap");
    
    f1->SetLineColor(9);
    f2->SetLineColor(8);
    
    
    f1->Draw("same");
    f2->Draw("same");
    f3->Draw("same");
    
    
    /************************************************************/
    
    
    //part2 - eta- eta^2/F relation
     /*************************************************************/
    
    Double_t eta[200],eta_squared_F[200];
    
    
    Int_t i = 0;
    
    while (!feof(f)){
        fscanf(f,"%lf %lf \n",&eta[i],&eta_squared_F[i]);
        i++;
    }
    
    
    TGraph g1(62,eta,eta_squared_F);
    g1.GetXaxis()->SetTitle("\\eta");
    g1.GetYaxis()->SetTitle("\\eta^2F");
    g1->SetTitle("\\eta vs. \\eta^2F");
    
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(4);
    
    
    
    g1->Draw("ap");
    
    /*************************************************************/
    
    //part 3 - Kurie Plot
    
    /************************************************************/
    
    
    Double_t m_e = 511; //kev
    Double_t p[200], counts[200], Kurie_y[200], Kurie_x[200], Kurie_x_final[200], Kurie_y_final[200], k_error[200];
        //Kurie_x is just energy
    Int_t i= 0;
    
    
    while (!feof(f)){
        fscanf(f,"%lf %lf \n",&p[i],&counts[i]);
        i++;
    }
    
    
    Double_t p0=-.00000878677;
    Double_t p1= 2.97073;
    Double_t p2= -0.205297;
    Double_t p3= 1.39808;
    Double_t p4= -0.164548;
    Double_t p5= -0.218212;
    Double_t p6= 0.10195;
    Double_t p7= -0.0137379;
    
    Double_t background = 33;// corrected 0.0367458;
    //Double_t background = 0;  //for no background
    
    
    for(int i=0; i < 200 ;i++){
        Kurie_x[i]= sqrt(p[i]*p[i]+m_e*m_e)-511;   //m_e in kev, 662 in kev.
        
        
        
        p[i]= p[i]/m_e;  //just to get eta.   p is just eta beyond this point.
        Kurie_y[i]= p0+ p1*p[i] + p2*(p[i]*p[i]) +
                    p3*(p[i]*p[i]*p[i]) + p4*(p[i]*p[i]*p[i]*p[i]) +
                    p5*(p[i]*p[i]*p[i]*p[i]*p[i]) + p6*(p[i]*p[i]*p[i]*p[i]*p[i]*p[i]) +
                    p7*(p[i]*p[i]*p[i]*p[i]*p[i]*p[i]*p[i]);
        Kurie_y[i]= Kurie_y[i]*m_e*m_e;
        
        if(Kurie_y[i] != 0){
            Kurie_y_final[i]=(counts[i]-background)/ Kurie_y[i];  //can't divide by 0;
            
            if(Kurie_y_final[i] >0){
                k_error[i]= sqrt(sqrt(counts[i]-background)/Kurie_y[i]);
                Kurie_x_final[i]= Kurie_x[i];
                Kurie_y_final[i]= sqrt(Kurie_y_final[i]);
                
            }
        }
    }
    
    g1= new TGraphErrors(61,Kurie_x_final,Kurie_y_final,0,k_error);
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(4);
    g1->Draw("ap");
    
    g1->SetTitle("Kurie Plot");
    g1.GetXaxis()->SetTitle("Energy (keV)");
    g1.GetYaxis()->SetTitle("\\sqrt{N \\over p^2 F}");
    
     /*************************************************************/
    
    //part 4 - not corrected spectrum
    
    /************************************************************/
     
     Double_t p[200],c[200], x[200],y[200];
     
     
     Int_t i = 0;
     
     while (!feof(f)){
     fscanf(f,"%lf %lf \n",&p[i],&c[i]);
     i++;
     }
    
    for(int i=0; i < 200 ;i++){
        x[i]=p[i]*p[i];
        
    }
    
     //graph essentials
     TGraph g1(62,p,c);
     g1.GetXaxis()->SetTitle("P (kev/c)");
     g1.GetYaxis()->SetTitle("counts/P");
     g1->SetTitle("not corrected Momentum Spectrum");
     
     g1->SetMarkerStyle(8);
     g1->SetMarkerColor(1);
     g1->Draw("ap");
    
     /*************************************************************/
    
    //part 5 - f value
    
    /************************************************************/
     


    double e_not=534.282966;
    double p_not= 911.8637;
    //double x;
         
     TF1 *eta_squared_F = new TF1("eta_squared", "(-0.00000878677 + 2.97073*x - 0.205297*(x*x) + 1.39808*(x*x*x)  - 0.164548*(x*x*x*x) - 0.218212*(x*x*x*x*x) + 0.10195*(x*x*x*x*x*x) - 0.0137379*(x*x*x*x*x*x*x))*(534.282966-511)*(534.282966-511)",0,1000);
    
    
    //(534.282966-511*(sqrt(x*x+1)-511))*(534.282966-511*(sqrt(x*x+1)-511))
     
    eta_squared_F->Integral(0,p_not/511);
    
    
    
    
}










