
import numpy as np
# this is our function
def func(x):
    return np.exp(2.*x)
# this returns the relative error, where x is the new value and y # is the old value

def errFunc(x, y):
    return np.abs((x-y)/x)
# initialize values, most of which are given in the problem
# sumSave will be a variable used to track the last sum (for error)
# sumErr is the ratio the value changed from last time
# output will be a dict to store output values
xMin = 0.
xMax = 1.
sumTolerance = 0.0001
sumSave = 0.
sumErr = 1.
m=0
output = {}

while sumErr > sumTolerance:
	m=m+1
	n = 2**m + 1
	dx = (xMax-xMin)/float(n-1)
	approx = 0.
    
	# this is the normal Simpson's rule to take care of the odd 1/3's
	approx = func(xMin)/3. + func(xMax)/3. + 4.*func(xMin + dx)/3.
	
    # notice the range(), it starts at 2 now and steps in 2's
	for i in range(2, n-1, 2):
        x = xMin + dx * float(i)
    		
            # we add the next two values here, which is why we step by 2's
		approx = approx + 2.*func(x)/3. + 4.*func(x + dx)/3.
    	approx = dx * approx
    	sumErr = errFunc(approx, sumSave) 
    	sumSave = approx
    	output[n] = (approx, sumErr)


print ''
print 'Integration using extended Simpson\'s rule:' 
print '------------------------------'
print ' n | integral value | change'
print '------------------------------'
for obj in sorted(output.items()):
    print '{0:3d} {1:13f} {2:12f}'.format(obj[0], obj[1][0], obj[1][1]) 
print '------------------------------'
print ''
print 'Actual analytic answer:', 0.5 * (func(xMax)-func(xMin))
