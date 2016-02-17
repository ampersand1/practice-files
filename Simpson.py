##Note:  I tailored the program to the integral in question.  

from math import exp, fabs, pow
from tabulate import tabulate

I_list = []
N_list = []

p = 0
m=0
condition = True


def f(x) :
    return exp(2*x)
def n(m) :
    return pow(2,m)+1



while condition:
    I_n = 0.0
    end = 1.0
    delta = 1.0/n(m)
    x = 0.0
    t = 0  #t stands for term number 
    
    while x < end: 
        I_n += delta*(f(x))
        
        if t % 2 == 1 :
             if t == n(m) :
                    I_n*(1.0/3.0)
             else :
                I_n*(4.0/3.0)
             
        elif t % 2 == 0 :    
            if t == 0.0 :
                I_n*(1.0/3.0)
            elif t == n(m) :
                I_n*(1.0/3.0)
            else : 
                I_n*(2.0/3.0)    
                    
        x += delta
        t += 1
            
    I_list.append(I_n)
    m += 1
    N_list.append(1/delta)
    
    
    if len(I_list) > 1 :
            p += 1
            if fabs((I_list[p]-I_list[p-1])/I_list[p]) < 0.0001 :
             condition = False      
print '_________'
print '| N | I|'  
print '----------'   
for i,j in zip(N_list,I_list):
    print i,j
    
    
    
