import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib.widgets as wgt

from json import load

with open('data.json') as f:
    data = load(f)

index = int(input("Enter number of dislocations: "))
while index != -1:
    plot = sns.histplot(data[index], stat="percent", kde=True)
    plot.set(xlabel='Steps', ylabel='Percent of runs')
    plt.show()
    
    index = int(input("Enter number of dislocations: "))
