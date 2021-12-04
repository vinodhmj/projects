# General Assumptions
# Every value is in SI units

import sys
import math

def findRating():
    voltage = 275000
    qc = 41.4
    qr = 19.20
    qs = 14.3
    r75 = 0.0000688
    current = math.sqrt((qc+qr-qs)/r75)
    nConductors = 2
    rating = (math.sqrt(3) * voltage * current * nConductors)/1000000
    return rating
    
def findACClearance(u50, k):
    d = (8 * u50) / (3740 * k - u50)
    return d

def findLIClearance(u50, k):
    d = u50 / (380 + (150 * k))
    return d

def findSIClearance(u50, k):
    d = (8 * u50) / (3400 * k - u50)
    return d

def findInsulatorDistance():
    requiredCreepage = 11.5
    # U160BLP - from datasheet
    # Creepage distance = 0.525
    # Spacing = 0.17
    nDiscs = requiredCreepage/0.525
    d = nDiscs * 0.17
    return d

def findCrossarmLength(dEl, dIns, dFitting, dCond):
    # dDisplacement = dSwing * sin(swingAngle)
    angle = math.radians(23.113) # angle in radians
    dDisplacement = (dIns + dFitting + dCond) * math.sin(angle)
    d = dDisplacement + dEl;
    return d

def findShieldDistance(dCA, dIns, dFitting, dCond):
    angle = math.radians(30) # angle in radians
    d = (dCA/math.tan(angle)) - dCond - dIns - dFitting 
    return d

def ohldesign():
    print("START")

    k = 1.45
    dFitting = 0.35
    dCond = 0.0315
    rating = findRating();
    dIns = findInsulatorDistance()
        
    u50 = 300 * math.sqrt(2)
    dAC = findACClearance(u50, k)
    dSI = findSIClearance(750, k)
    dLI = findLIClearance(850, k)
    
    dEl = max(dAC, dSI, dLI)

    dCrossarm = findCrossarmLength(dEl, dIns, dFitting, dCond)
    dShield   = findShieldDistance(dCrossarm, dIns, dFitting, dCond)
        
    print("MVA Rating", rating)
    print("dIns", dIns)

    print("---------------")
    print("PHASE TO GROUND")
    print("---------------")
    print("k", k)
    print("dAC", dAC)
    print("dLI", dLI)
    print("dSI", dSI)
    print("dEl", dEl)
    print("dCrossarm", dCrossarm)
    print("dShield", dShield)

    k = 1.4
    dSI = findSIClearance(1125, k)
    dLI = findLIClearance(1270, k)
    dEl = max(dAC, dSI, dLI)

    print("---------------")
    print("PHASE TO PHASE")
    print("---------------")
    print("k", k)
    print("dAC", dAC)
    print("dLI", dLI)
    print("dSI", dSI)
    print("dEl", dEl)

    
    
    print("END")

if __name__ == "__main__":
# This is the standard boilerplate that calls the main() function.
    # a = float(sys.argv[1])
    ohldesign()
    
