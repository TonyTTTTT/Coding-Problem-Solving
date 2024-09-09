import pandas as pd

data = {'ProductID': [101, 102, 103, 104],
        'Price': [25, 30, 22, 22],
        'Quantity': [10, 15, 8, 12]}

df = pd.DataFrame(data)
df['Total'] = df['Price'] * df['Quantity']

highest_total = df[df['Total'] == df['Total'].max()]
lowest_total = df[df['Total'] == df['Total'].min()]

result = highest_total.append(lowest_total)
print(result)