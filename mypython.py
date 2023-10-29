import numpy as np
import pandas as pd
from matplotlib.pyplot import scatter, show, xlabel, ylabel, title
import matplotlib as plt
import random
import os
from tensorflow.keras.datasets import fashion_mnist
from tensorflow.keras.layers import Dense,Flatten
import tensorflow as tf
  

DATAPOINTS = 200
FEATURES = 6

def creating_data():
    #name, age, gender, height, married or no,weight
    data = []
    ranges = [[6,46],[0,1],[100,200],[50,100],[0,1]]
    first_n = ["charlie","max","joseph","jack","shaldon","pasquale","aidan","cooper","sean","wayde","calvin","tommy","terry","james","daniel"]
    last_n = ["c","m","j","j","s","p","a","c","s","w","c","t","t","j","d"]
    for i in range(DATAPOINTS):
        temp = [] 
        for n in range(FEATURES):
            if n == 0:
                fname_i = random.randint(0,len(first_n)-1)
                lname_i = random.randint(0,len(last_n)-1)
                full_n = first_n[fname_i] + " " + last_n[lname_i]
                temp.append(full_n)

            else:
                num = int(random.randint(ranges[n-1][0],ranges[n-1][1]))
                #print("num is: ", num)          
                temp.append(num) 

        #print("temp: ", temp)
        data.append(temp)            
        #print(data[i])
        
    return data


def initialise_keras_data():
    (x_train,y_train),(x_test,y_test) = fashion_mnist.load_data()
    return x_train,y_train,x_test,y_test

def plot_data(x,y,feature_name):
    scatter(x,y)
    xlabel(f"feature {feature_name}")
    ylabel("weight")
    title(f"weight vs {feature_name}")
    show()

def create_model_and_use(x,y,x_test,y_test):
    model = tf.keras.Sequential([
        Flatten(input_shape = (28,28)),
        Dense(124,activation = "relu"),
        Dense(90,activation = "relu"),
        Dense(70,activation = "relu"),
        Dense(40,activation = "relu"),
        Dense(10,activation = "softmax"),
    ])

    model.compile(optimizer = "adam",loss = tf.keras.losses.SparseCategoricalCrossentropy(from_logits = True),metrics = ["accuracy"])

    model.fit(x,y,epochs = 10,validation_data = (x_test,y_test))

    test_loss, test_acc = model.evaluate(x_test,y_test)

    print(test_loss," ",test_acc)


def main():

    regression_data = creating_data()
    
    #SEPERATE THE NAMES AND NUMBERS
    names = []
    numbers = []

    random.shuffle(regression_data)

    for dp in range(DATAPOINTS):
        tmp = []
        for f in range(FEATURES):
            if f == 0:
                names.append(regression_data[dp][0])

            else:
                tmp.append(regression_data[dp][f])
    
    
        numbers.append(tmp)
    
    numbers = np.array(numbers)


    #SAVE THE NUMBERS
    with open("/home/kali/Documents/regression_names.txt","w") as f:
        f.write(str(names).replace("]","").replace("[",""))

    np.savetxt("/home/kali/Documents/regression_numbers.txt",numbers)
    

    #FETCH THE DATA BACK FROM FILES
    numbers = np.array(np.loadtxt("/home/kali/Documents/regression_numbers.txt"))
    
    label_columns = "weight"
    data_columns = ["age", "gender", "height", "married or no"] 

    y = numbers[:,3:4]
    x = np.concatenate((numbers[:,:3],numbers[:,4:5]),axis=1)
    
    for ind,data in enumerate(data_columns):
        #plot_data(x[:,ind:ind+1],y,data_columns[ind])
        pass

    x_train,y_train,x_test,y_test = initialise_keras_data()

    create_model_and_use(x_train,y_train,x_test,y_test)

  
    
    


main()    