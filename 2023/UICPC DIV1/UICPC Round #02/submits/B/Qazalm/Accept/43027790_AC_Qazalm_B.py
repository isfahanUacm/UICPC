def take_contestants_info(contestant_num):
    contestants= {}
    for contestant in range(contestant_num):
        contestant_info= input().split()
        contestants[contestant_info[0]]= [contestant_info[1],contestant_info[2], contestant_info[3]]
    return contestants

def check_eligibility(ith_contestant):
    if started_studies(contestants[ith_contestant][0]):
        return "eligible"
    if birthdate(contestants[ith_contestant][1]):
        return "eligible"
    if int(contestants[ith_contestant][2]) >40:
        return "ineligible"
    return "coach petitions"

def started_studies(date):
    return int(date.split("/")[0]) >= 2010

def birthdate(date):
    return int(date.split("/")[0]) >= 1991

contestant_num= int(input())
contestants= take_contestants_info(contestant_num)
for name in contestants.keys():
    print(f"{name} {check_eligibility(name)}")