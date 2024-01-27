def pow1(x,y):
	if y == 0:
		res =1
	else:
		res= x * pow1(x,y-1)
	return res
	
print(pow1(2,3))			
		
