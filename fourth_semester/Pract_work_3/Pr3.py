import requests
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as ticker

s_city = "Kerch"
city_id = 0
appid = "afb68b2793f4077e3aa24012aee58ed3"

try:
	res = requests.get("http://api.openweathermap.org/data/2.5/find", params={'q': s_city, 'type': 'like', 'units': 'metric', 'APPID': appid})
	data = res.json()
	cities = ["{} ({})".format(d['name'], d['sys']['country'])
	for d in data['list']]
	print("city:", cities)
	city_id = data['list'][0]['id']
	print('city_id=', city_id)
except Exception as e:
    print("Exception (find):", e)
    pass

n = 40
first = [0 for x in range(n)]
second = [0 for x in range(n)]

try:
        res = requests.get("http://api.openweathermap.org/data/2.5/forecast",
                           params={'id': city_id, 'units': 'metric', 'lang': 'ru', 'APPID': appid})
        data = res.json()
	i = 0
	sum = 0
	k = 0
	tmp = ""
        for d in data['list']:
		tmp = d['dt_txt'][8:10] + '.' + d['dt_txt'][5:7] + '\n' + d['dt_txt'][11:16]
		#print( tmp, '{0:+3.0f}'.format(d['main']['temp']), d['weather'][0]['description'] )
		first[i] = tmp
		second[i] = float(d['main']['temp'])
		i = i + 1
except Exception as e:
        print("Exception (forecast):", e)
        pass

def format_date(x, pos=None):
    thisind = np.clip(int(x + 0.5), 0, n - 1)
    return first[thisind]

fig, axes = plt.subplots()

ind = np.arange(n)

X = first
Y = second

plt.plot(ind, Y, 'o-')
axes.xaxis.set_major_formatter(ticker.FuncFormatter(format_date))
axes.set_title("Kerch")
axes.set_xlabel("Day and time")
axes.set_ylabel('Temperature')
fig.autofmt_xdate()

plt.show()
