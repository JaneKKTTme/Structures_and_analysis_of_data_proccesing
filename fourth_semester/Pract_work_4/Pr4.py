from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import requests
import json

api = 'c91bfc-54f2a6'
url = 'http://aviation-edge.com/v2/public/flights?key=' + api + '&limit=30000'

result = requests.get(url)
open('tmp.json', 'wb').write(result.content)
open('tmp.xml', 'wb').write(result.content)

input_file = open('tmp.json')
data = json.load(input_file)

latitude = []
longtitude = []

for item in data:
	latitude.append(item['geography']['latitude'])
	longtitude.append(item['geography']['longitude'])

m = Basemap()

x, y = m(longtitude, latitude)

m.scatter(x, y, 1, marker='o', color='r')

m.bluemarble()
plt.title('Locations of airplane')
plt.show()
