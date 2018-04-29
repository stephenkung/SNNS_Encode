import random
pattern_file = open('D:\A-Project\encode\encode.pat','w')
for i in range(10000):
	x1 = (random.randint(0,100))/100   #[0.01~1]
	x2 = (random.randint(0,100))/100   #[0.01~1]
	x3 = (random.randint(0,100))/100   #[0.01~1]
	x4 = (random.randint(0,100))/100   #[0.01~1]
	x5 = (random.randint(0,100))/100   #[0.01~1]
	print ('x1:',x1,';x2:',x2,';x3:',x3,';x4',x4,';x5',x5)
	
	y1 = round(((10*x1)**2 + 25*x2 + 30*x3 + 40*x4 + 50*x5 + 5)/250,4)
	y2 = round(((9*x2)**2 + 20*x1 + 35*x3 + 40*x4 + 50*x5 + 15)/250,4)
	y3 = round(((8*x3)**2 + 20*x1 + 30*x2 + 45*x4 + 50*x5 + 25)/250,4)
	y4 = round(((7*x4)**2 + 20*x1 + 30*x2 + 40*x3 + 55*x5 + 35)/250,4)
	y5 = round(((6*x5)**2 + 20*x1 + 30*x2 + 40*x3 + 50*x4 + 45)/250,4)
	print ('y1:',y1,';y2:',y2,';y3:',y3,';y4',y4,';y5',y5)
	
	pattern_file.write("# Input pattern "+str(i+1)+":\n")
	pattern_file.write(str(x1)+' '+str(x2)+' '+str(x3)+' '+str(x4)+' '+str(x5)+'\n')
	pattern_file.write("# Output pattern "+str(i+1)+":\n")
	pattern_file.write(str(y1)+' '+str(y2)+' '+str(y3)+' '+str(y4)+' '+str(y5)+'\n')
	
		
	