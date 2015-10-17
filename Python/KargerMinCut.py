import random
from random import randint

#loading data from the text file#
with open('kargerMinCut.txt') as req_file:
    mincut_data = []
    for line in req_file:
        line = line.split()
        if line:
            line = [int(i) for i in line]
            mincut_data.append(line)


cuts = []

#extracting edges from the data #   
for i in range(1,100):         
    edgelist = []
    nodelist = []
    for every_list in mincut_data:
        nodelist.append(every_list[0])
        temp_list = []
        for temp in range(1,len(every_list)):
            temp_list = [every_list[0], every_list[temp]]
            flag = 0
            for ad in edgelist:
                if set(ad) == set(temp_list):
                    flag = 1
            if flag == 0 :
                edgelist.append([every_list[0],every_list[temp]])


    #karger min cut algorithm#
    while(len(nodelist) > 2):
        val = randint(0,(len(edgelist)-1))
        target_edge = edgelist[val]
        replace_with = target_edge[0]
        should_replace = target_edge[1]
        for edge in edgelist:
            if(edge[0] == should_replace):
                edge[0] = replace_with
            if(edge[1] == should_replace):
                edge[1] = replace_with
        edgelist.remove(target_edge)
        nodelist.remove(should_replace)
        for i in range((len(edgelist)-1),-1,-1):
            if edgelist[i][0] == edgelist[i][1]:
                edgelist.remove(edgelist[i])

    cuts.append(len(edgelist))
print min(cuts)
