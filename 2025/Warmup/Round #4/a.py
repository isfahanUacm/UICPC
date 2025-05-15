import os
import shutil

# Base folders
folders = ['A', 'B', 'C', 'D', 'G', 'H', 'I', 'J', 'K', 'L']

teams = {
    'AKM':'DejaVu',
    'Binary':'BinaryBrainz',
    'bit':'Bits',
    'xor1234':'Xor',
    'Maya2':'Maya',
    'MEYSAMpd':'MEYSAMpd',
    'Choom':'Choom',
    'random1234567':'random1234567',
    'MasihRoughani':'Masih',
    'DejaVu':'DejaVu',
    'MinaAbbspr' : 'Mina',
    'Ma' : 'Maaaa', 
    'RuntimeTerrors' : 'RuntimeTerrors',
    'matinabbasi' : 'Matin',
    'ThisIsLian' : 'LI',
    'FarzadMoradi' : 'Farzad',
    'javat' : 'javat',
    'fawtima' : 'fawtima',
    'Etil' : 'Etil_Metil',
    'Codes' : 'Codes_Fall',
    'DeadAtlas' : 'Atlas',
    'InFluX' : 'InFluX'
}

# Mapping verdict codes to folder names
verdict_mapping = {
    'AC': 'Accepted',
    'WA': 'Wrong Answer',
    'RE': 'Run-Time Error',
    'CE': 'Compile Error',
    'TLE': 'Time Limit Exceeded',
    'SUBMIT': 'Submit Failed', 
    'MLE': 'Memory Limit Exceeded'
}

# Function to extract team name and verdict from the file name
def extract_info(filename):
    filename = filename.replace('__', '_')
    parts = filename.split('_')
    code = parts[0]
    verdict = verdict_mapping[parts[1]]

    if verdict == 'Submit Failed':
        team_name = parts[4]
    else:
        team_name = parts[2]
    return code, team_name, verdict

os.chdir('submits')

for foolder in os.listdir():
    os.chdir(foolder)

    list_of_submits = os.listdir()

    for submit in list_of_submits:
        code, team_name, verdict = extract_info(submit)

        if(not os.path.exists(teams[team_name])):
            os.mkdir(teams[team_name])

        os.chdir(teams[team_name])

        if(not os.path.exists(verdict)):
            os.mkdir(verdict)
        
        os.chdir('../')

        shutil.move(submit, teams[team_name] + '/' + verdict)

    os.chdir('../')