""" Generate CSV File """

filename = 'nums.csv'
with open(filename, 'w') as file:
    counter = 5000
    while counter >= 0:
        file.write(str(counter)+', ')
        file.write('\n')
        counter -= 1
