import random
temp = []
humidity = []

temp_threshold = 75
humidity_threshold= 75
for i in range(100):
    tempx = random.uniform(20, 105)
    temp.append(tempx)
    humidityx = random.uniform(20, 105)
    humidity.append(humidityx)
print("TEMP VALUES")
print("****")
for i in range(len(temp)):
        if(temp[i]>temp_threshold):
            print("Alarm : ", temp[i])
        else:
            print('Safe: ' , temp[i])
print("****")
print("****")
print("HUMIDITY VALUES")
print("****")
for i in range(len(humidity)):
    if (humidity[i] > humidity_threshold):
        print('Alarm: ', temp[i])
    else:
        print('Safe: ' , temp[i])
print("****")
print("****")
#print(humidity)
#print(temp)
