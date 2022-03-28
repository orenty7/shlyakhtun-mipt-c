import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib.widgets as wgt

from json import load

with open('data.json') as f:
    data = load(f)

finished = False
while True:
    print("Which crystal you want to explore?")
    print("1. Line")
    print("2. Flat")
    print("3. Exit")
    action = int(input("Enter number: "))
    print()
    if action == 3:
        break
    elif action == 1:
        
        while True:
            print("What you want to explore?")
            print("1. One dislocation")
            print("2. Many dislocations")
            print("3. Main menu")
            choise = int(input("Enter number: "))
            if choise == 1:
                formatted_data = list(map(lambda arr: sum(arr)/len(arr), data['lab 3']['one dislocation']))
                plot = sns.histplot(formatted_data, kde=True)
                plot.set(xlabel='Steps', ylabel='Width of crystal')
                plt.show()                
            elif choise == 2:
                index = int(input("Enter number of dislocations(-1 to exit): "))
                while index != -1:
                    plot = sns.histplot(data['lab 3']['area'][index], stat="percent", kde=True)
                    plot.set(xlabel='Steps', ylabel='Percent of runs')
                    plt.show()
                    index = int(input("Enter number of dislocations(-1 to exit): "))

            elif choise == 3:
                break
            else:
                print("Incorrect choise")
            
    elif action == 2:

        index = int(input("Enter number of dislocations(-1 to exit): "))
        while index != -1:
            plot = sns.histplot(data['lab 1'][index], stat="percent", kde=True)
            plot.set(xlabel='Steps', ylabel='Percent of runs')
            plt.show()
            
            index = int(input("Enter number of dislocations: "))
    else:
        print("Wrong number")