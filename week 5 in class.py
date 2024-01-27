print("What is the temperature?")
temp = int(input())
if temp < 0:
    temp = "cold"
elif 0 <= temp <= 10:
    temp = "fresh"
elif temp > 10:
    temp = "warm"
print("Is it precipitating? (1-true, 0-false)")
pre = int(input())

if pre == 1:
    if temp == "cold":
        print(temp,", snow")
    else:
        print(temp,", rain")
else:
    print(temp)
    
    

    
