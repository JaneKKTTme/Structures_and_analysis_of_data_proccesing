import requests
import itertools
import glob
#from lxml import etree
import pandas as pd
import xml.etree.ElementTree as ET
from bs4 import BeautifulSoup
from datetime import datetime, date
import matplotlib.pyplot as plt
import numpy as np

def to_receive_data(day, month, year):
    base_url='http://www.cbr.ru/scripts/XML_daily_eng.asp?'
    if day < 10:
        if month >= 10:
            day_url = '0' + str(day) + '/' + str(month) + '/' + str(year)
        else:
            day_url = '0' + str(day) + '/0' + str(month) + '/' + str(year)
    else:
         if month < 10:
             day_url = str(day) + '/0' + str(month) + '/' + str(year)        
         else:
             day_url = str(day) + '/' + str(month) + '/' + str(year)
    url = base_url + 'date_req=' + day_url
    tmp = requests.get(url)
    open('tmp.xml', 'wb').write(tmp.content)
    print url
    return day_url

def to_extract_data(tmp_file, result, d):
    for file in glob.glob(tmp_file):
        tree = ET.parse(file)
        root = tree.getroot()
        for child in root.iter('Valute'):
            if (child.items() == [('ID', 'R01115')]):
                for child_ in child.iter('Value'):
                    result[d] = child_.text 
    return child_.text         

result = {}
i = 0
day = 1
month = 1
year = 2014
n = 1000
first = [0 for x in range(n)]
second = [0 for x in range(n)]
while i < n:
    if month == 12 and day == 32:
        month = 1
        year = year + 1
    if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
        if day == 32:
            day = 1
            month = month + 1
    elif month == 4 or month == 6 or month == 9 or month == 11:
        if day > 30:
            day = 1
            month = month + 1
    elif month == 2:
        if year % 4 != 0 or (year % 100 == 0 and year % 400 != 0):
            if day > 28:  
                day = day + 1         
                month = month + 1
        else:
            if day > 29:
                day = 1
                month = month + 1
    
    data = to_receive_data(day, month, year)
    s = to_extract_data('tmp.xml', result, data)
    first[i] = data
    second[i] = float(s[0:2] + '.' + s[3:])
    day = day + 1
    i = i + 1

df = pd.DataFrame(result, index=['']).T
df.to_csv('List.csv')

X = first
Y = second

plt.plot(X,Y) 
plt.show()
