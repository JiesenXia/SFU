#Author Name: Tao Tao    Date: Sep 24
#This program is a investor bot, which would cummunicate\
#with human and give investment information
#Firstly, the bot will greet the user

import random


def show():
	print("Rules:\
If you invest for 5 or less year...\
you will get a % equal to 1/2 number of years\
If you invest more than 5 years...\
you will get 2% plus 1/2 number of years as %...\
Additionally, if you invest more than 10 years...\
you will get a random % between 0 and 2, extremes possibly included")
	



print("Hi, there. What is your name?")
name=input()
print("Alright, then How old are you?")
age=int(input())

#Secondly, the bot will tell the rules

print("Ok, let us start with the investment rules, and \
you will be the one who decides\
to invest or not")

show()

#Thirdly, the bot asks the critical information.

print("What is your initial capital?")
capital = int(input())
print("How many years will you invest with me?")
year = int(input())

if year <= 5:
    finalPercent = year // 2
    print("** Trace, percentage is " + str(finalPercent) + " % ")
    reward = year // 2 * 0.01 * capital + capital
    
elif 6 <= year <= 10:
    finalPercent = 2 + year // 2
    print("** Trace, percentage is 2 + " + str(year // 2) )
    reward = finalPercent * 0.01 * capital + capital
   
elif year > 10:
    percent = 2 + year // 2
    addPercent = random.randint(0,2)
    finalPercent = 2 + year // 2 + addPercent
    reward = finalPercent * 0.01 * capital + capital
    print("** Trace, percentage is 2 + " + str(year // 2))
    print("** Trace, random additional percentage is " + str(addPercent) )

#Forthly, the bot does calculations.

print("Your percentage will be: " + str(finalPercent) + " %")
print("The money you will receive back is: " + str(reward))


#Then, the bot call the function based on the situation

#The bot will generate the password

n = age % 7 
passFirst = name[0] * n
passsecond = name[-1]
passw1 = passFirst + passsecond 
if len(passw1) % 2 == 0:
	password = passw1 + "!"
else: password = passw1 + "!!"


print("Now that you see what you will get..."
"would you want to invest with me?"
"Please answer y/n")

ans=input()

#The bot will follow instrutions

if ans == "y":
	print("** Trace remainder n from dividing age by 7 is " + str(n) )
	print("Looking forward to working with you")
	print("Your secret password is: " + password)
	
else: print("Next time! Nice to talk to you anyway!")

input()

#The program ends, all sample run tested










