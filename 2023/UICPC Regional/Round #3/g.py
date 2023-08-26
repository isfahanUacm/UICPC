name = {'MiddleEastElites':'MiddleEastElites',
        'Artemis0707':'Artemis',
        'mmd557':'mkh',
        'AKM':'AKM',
        'AmiraliRafiei':'AmiraliRafiei',
        'Kiarash2473':'Kiarash2473',
        'Maya2':'Maya',
        'DejaVu':'AKM'}

import os
import shutil
os.chdir('Submits')

for c in os.listdir():
    os.chdir(c)
    ls = os.listdir()
    for i in ls:
        j = 2
        if("FAILED_OTHER" in i):
            j = 3
        if("AKM" in i):
            j+=1

        if(not os.path.exists(i.split('_')[j])):
            os.mkdir(i.split('_')[j])
        shutil.move(i, i.split('_')[j])
    
    ls = os.listdir()
    for i in ls:
        os.chdir(i)
        for c in os.listdir():
            if(c.split("_")[1]=="WA"):
                if(not os.path.exists("Wrong Answer")):
                    os.mkdir("Wrong Answer")
                shutil.move(c, "Wrong Answer")

            elif(c.split("_")[1]=="AC"):
                if(not os.path.exists("Accept")):
                    os.mkdir("Accept")
                shutil.move(c, "Accept")

            elif(c.split("_")[1]=="TLE"):
                if(not os.path.exists("Time Limit Exceeded")):
                    os.mkdir("Time Limit Exceeded")
                shutil.move(c, "Time Limit Exceeded")

            elif(c.split("_")[1]=="CE"):
                if(not os.path.exists("Compile Error")):
                    os.mkdir("Compile Error")
                shutil.move(c, "Compile Error")

            else:
                if(not os.path.exists("Run-Time Error")):
                    os.mkdir("Run-Time Error")
                shutil.move(c, "Run-Time Error")
        os.chdir('../')

    os.chdir('../')

# os.chdir('submits')
for c in os.listdir():
    os.chdir(c)
    ls = os.listdir()
    for i in ls:
        os.rename(i, name[i])
    os.chdir('../')