# Author: Tao Tao   Date Sep 28
#the chatbot greet the user

import random

print("Hi dear user, do you want to talk with me?")
resp = input()

yeses = ["yes","y","of course","certainly", "certainly yes", "sure"]
noses = ["no", "n","no way", "of course not", "never","absolutely not"]

#check resp whether it is in the list

if resp in yeses:
    print("Oh, yeah! I am happy to talk to you too.\
and let us get started.")
elif resp in noses:
    print("Oh, no, why don't you want to talk with me? I am sad.")
else:
    print("I don't understand you, whatever.")

#continue talking and aske user to propose question

print("Ask me anything you want to know.")
a = input()
answer1 = random.randint(1,6)
answer2 = random.randint(0,5)
answer3 = random.randint(0,5)

#print("** Trace answer1 = "+ str(answer1))
#print("** Trace answer2 = "+ str(answer2))

#check if the user ask for the name

if "name" in a:
    print("My name is Intelligent Bot!")
else:
    if answer1 % 2 > 0:
        print(yeses[answer2])
    else:
        print(noses[answer2])

print("What is the other question?")
b = input()
#print("** Trace answer3 = " + str(answer3))
if "name"  in b:
    print("My name is Intelligent Bot!")
else:
    if answer1 % 2 > 0:
        print(yeses[answer3])
    else:
        print(noses[answer3])

# say goodbye in different ways randomly

goodbye= ["goodbye","bye","bye bye","see you","see you later","see you \
soon"]

answer4 = random.randint(0,5)
#print("** Trace answer3 = " + str(answer4))
print("Ok enough talking")
print(goodbye[answer4])
input()






    
