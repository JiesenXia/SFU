def addPosToElem(lst):
    result = []
    for i in range(len(lst)):
        if i%2 == 0:
            result += [i+lst[i]]
    return result

lst=[0,10,20,30,40,50]
print(addPosToElem(lst))
    
    
        
        
        
