import sys
import re
import pandas as pd

line = "hello world, hello, world, wild world"

line = re.sub(r'[^a-zA-Z ]', '', line)

words = line.split(' ')

count = pd.Series(words).value_counts()


print(count.keys()[0])