#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  main.py
#  
#  Copyright 2022 E199416 <E199416@AZ75LT1J1GFB3>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  Description:
#  There's 100 prisoners and their numbers have been randomly put in 
#  100 boxes. One at a time, each prisoner is allowed to go into the room
#  and open any 50 of the sealed to find their number. The boxes must be
#  returned to the original condition. They can't communicate to other 
#  prisoners. If all 100 prisoners find their number in the room, they
#  will all be freed. Else, they'll stay in jail. 
#  
#  Strategy:
#  The best way to do this is for each prisoner to go into the room and 
#  open the box with your number on it. If the number is not yours, then
#  go to the box with that number on it. Ex. Prisoner #1 goes to box #1
#  and box one has #43, go to box #43. Continue to open each box until
#  you find your number. 
#  
#  Goal:
#  1. Make it multithreaded to go faster.
#  2. Count the loops
#

import random
import time

dictBoxes = dict()
prisonerList = list(range(1,101))
randomSlips  = random.sample(range(1, 101),100)
wins  = 0
total = 0

def rndm_slips_in_boxes(keys, values):
    for key in keys:
        #print(key,values[key-1])
        dictBoxes[key] = values[key-1]

def prisoner_search_for_slip(prisoners, boxes):
    foundSlip = 0
    foundNone = 0
    for prisoner in prisoners:
        count = 0
        targetBox = prisoner
        while True:
            if count > 50:
                foundNone += 1
                break
            else:
                #print (prisoner)
                #print (boxes[targetBox])
                if prisoner == boxes[targetBox]:
                    foundSlip += 1
                    break
                else:
                    targetBox = boxes[targetBox]
                    count += 1
    return foundSlip, foundNone




while True:
    total += 1
    dictBoxes = dict()
    prisonerList = list(range(1,101))
    randomSlips  = random.sample(range(1, 101),100)
    rndm_slips_in_boxes(prisonerList, randomSlips)
    #print (dictBoxes)
    winLosses = prisoner_search_for_slip(prisonerList, dictBoxes)
    if winLosses[0] == 100:
        wins += 1
    average = wins/total
    print ("Average: ", average)
    #time.sleep(0.1)
