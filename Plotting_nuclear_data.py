#Part 1:
    
#De/dx in lecutre 2 and 3.  From the estar, astar, and pstar interfaces, download
#and plot the alphas and protons in liquid water.  

import matplotlib.pyplot as plt



x = []
y = []


readFile = open('astar-liquid-total.txt','r')  
    #set working directory to textfile locations and change astar textfile to pstar and estar.  
sepFile = readFile.read().split('\n')

readFile.close()

for plotPair in sepFile:

	var =plotPair.split(' ') 
	x.append(float(var[0]))   
	y.append(float(var[1]))  



plt.plot(x, y)

plt.title('Alpha Stopping Power vs Energy in Liquid Water')
plt.xlabel('Energy (MeV)')
plt.ylabel('Stopping Power (MeV cm^2/g)')
plt.xscale('log')
plt.yscale('log')

plt.show()

----------------------------------------------------------------------------------------------

#Part2: make Bragg Curve for pstar,estar, astar

import matplotlib.pyplot as plt
import scipy.interpolate as sp

xx=[]
yy=[]


readFile = open('pstar-liquid-total.txt','r')

sepFile = readFile.read().split('\n')

readFile.close()

for plotPair in sepFile:

	var =plotPair.split(' ') 
	xx.append(float(var[0]))     
	yy.append(float(var[1])) 

x1=[] 
y1=[]

x=0.0
f1 = sp.interp1d(xx, yy, kind='cubic')  #fill_value=0)
Ei = 5.5
xstep =0.001

while (Ei > 0):
    y1.append(Ei)
    dEi=f1(Ei)*xstep
    Ei=Ei-dEi
    x=x+xstep
    x1.append(x)


plt.figure()
plt.yscale('log')
plt.xscale('log')


plt.title('Bragg Curve for Electrons')
plt.xlabel('distance (cm)')
plt.ylabel('Stopping Power (MeV cm^2/g)')

plt.plot(x1, f1(y1))
plt.show()






