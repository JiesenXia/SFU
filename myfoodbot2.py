#Author: Tao Tao
#Date Oct 6

import random
initLists = input("Execute with new lists (n) or original lists (o)? ==> ")
print()

if initLists == "n":

    print("\nTo start please input the lists exactly using the list format")
    print("Lists should have at least 1 dish and not more than 10 dishes")
    print("Lists with prices correspond exactly to lists with dishes\n")

    vietnamese_dishes = eval(input("List of Vietnamese dishes ==> "))
    vietnamese_dish_prices = eval(input("List of Vietnamese dishes prices ==> "))
    print()
    italian_dishes = eval(input("List of Italian dishes ==> "))
    italian_dish_prices = eval(input("List of Italian dishes prices ==> "))

else:

    print("Now lists are initialized in the program ")

    vietnamese_dishes = ["Pho", "Fried rice", "Pancake", "Steamed sticky rice"]
    vietnamese_dish_prices = [7.5, 6.75, 5.15, 8.25]

    italian_dishes = ["Pizza", "Meatball spaghetti", "Pasta"]
    italian_dish_prices = [7.15, 6.25, 5.0]


# TRACE PRINTING IN ANY CASE
def func1():
    print ("\n*** TRACE Vietnamese ", vietnamese_dishes, vietnamese_dish_prices)
    print ("\n*** TRACE Italian ", italian_dishes, italian_dish_prices)

func1()    

### END OF PROVIDED CODE

#Start of my program
def func2():
    print("What is your name?")
    

print("WELCOME TO THE FOOD ORDERING BOT!")
func2()
name = input()
print("Hello dear " + name)
print("We specialize in Vietnamese and Italian food")
print("You will be able to order two dishes")
print("If you are not sure what to ask we will choose for you!")

#Ask what user wants first

print("What is your specific dish you want to order?")
food1 = input().capitalize()
if food1 in italian_dishes:
    print("It seems that you like Italian style of food.")
    in1=italian_dishes.index(food1)
    cost1=italian_dish_prices[in1]
    print("\n *** TRACE: dish "+str(food1)+" cost "+ str(cost1))
    sug = "n"
elif food1 in vietnamese_dishes:
    print("It seems that you like Vietnamese style of food.")
    in1=vietnamese_dishes.index(food1) 
    cost1=vietnamese_dish_prices[in1]
    print("\n ***TRACE: dish "+str(food1)+" costs "+str(cost1))
    sug = "n"
else:
    print("Since you indicated a dish not avaliable, we are choosing one for you,")
    print("But also, would you like to request that this dish is considered for the future? (y/n)")
    sug = input()
    if sug == "y":
        print("\n ***TRACE: suggested dish "+str(food1))
    else:
        print("That is Ok")
    ind=random.randint(0,1)
    if ind == 0:
        in1=random.randint(0,len(vietnamese_dishes)-1)
        dish1=vietnamese_dishes[in1]
        cost1=vietnamese_dish_prices[in1]
        print("The dish we chose for you is "+str(dish1))
        print("\n ***TRACE: dish "+str(dish1)+" costs "+str(cost1))
    else:
        in1=random.randint(0,len(italian_dishes)-1)
        dish1=italian_dishes[in1]
        cost1=italian_dish_prices[in1]
        print("The dish we chose for you is "+str(dish1))
        print("\n ***TRACE: dish " +str(dish1)+" costs "+str(cost1))

# Ask waht user wants second
print("Do you want to order another dish? (y/n)")
choice = input()
if choice == "n":
    print("Ok! No more dishes for you")
    cost2=0

    
else:
    print("All the available dishes are ")
    print("=================")
    def func3():
        for i in range(len(vietnamese_dishes)):
            print("v"+str(i+1) +" - "+vietnamese_dishes[i])
    func3()
    print("=================")
    def func4():
        for i in range(len(italian_dishes)):
            print("i"+str(i+1) +" - "+italian_dishes[i])
    func4()
    print("=================")
    print("Please choose another dish by indicating the code that we provide")
    print("You may order the same dish as before, if you want")
    print("If you do not coose an existing dish we will choose one for you")
    print("Provide the dish code here(Must be a letter and a number)")
    food2 = input()
    if food2[0] == "v" and int(food2[1]) <= len(vietnamese_dishes):
        in2=int(food2[1])-1
        cost2=vietnamese_dish_prices[in2]
        print("\n *** TRACE: dish "+str(vietnamese_dishes[in2])+" costs "+str(cost2))
        
    elif food2[0] == "i" and int(food2[1]) <= len(italian_dishes) :
        in2=int(food2[1])-1 
        cost2=italian_dish_prices[in2] 
        print("\n ***TRACE: dish "+str(italian_dishes[in2])+" costs "+str(cost2))

    else:
        print("Since you indicated a dish not avaliable, we are choosing one for you,")
        ind=random.randint(0,1)
        if ind == 0:
            in2=random.randint(0,len(vietnamese_dishes)-1)
            dish2=vietnamese_dishes[in2]
            cost2=vietnamese_dish_prices[in2]
            print("The dish we chose for you is "+str(dish2))
            print("\n ***TRACE: dish "+str(dish2)+" costs "+str(cost2))
        else:
            in2=random.randint(0,len(italian_dishes)-1)
            dish2=italian_dishes[in2]
            cost2=italian_dish_prices[in2]
            print("The dish we chose for you is "+str(dish2))
            print("\n ***TRACE: dish " +str(dish2)+" costs "+str(cost2))
    

#Finally tell users about the total cost
cost = cost1 + cost2
print("Please dear "+name+", pay the delivery person the total "+str(cost)+" and a nice tip :)!")
if sug == "y":
    print("Thanks for your suggestion of "+food1)
    print("Nice doing business with you!")
else:
    print("Nice doing business with you!")
       


















