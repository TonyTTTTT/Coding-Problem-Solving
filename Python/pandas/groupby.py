import pandas as pd
data = {'ProductID': [101, 102, 103, 104],
       'Price': [25, 30, 22, 10],
       'Quantity': [10, 15, 8, 25]}
df = pd.DataFrame(data)
df['Total'] = df['Price'] * df['Quantity']
result = df.groupby('Total')['ProductID'].count()
print(result)