import math
import numpy as np
import matplotlib
from matplotlib import pyplot as plt
bStandardIDMT = True;

def findTMS(t, I, psm, In):
    if bStandardIDMT:
        tms = t / (0.14/(math.pow((I/(psm*In)), 0.02) - 1));
    else:
        tms = t / (80/(math.pow((I/(psm*In)), 2) - 1));
    return round(tms, 3);

def findOperatingTime(tms, I, psm, In):
    if bStandardIDMT:
        t = tms * (0.14/(math.pow((I/(psm*In)), 0.02) - 1));
    else:
        t = tms * (80/(math.pow((I/(psm*In)), 2) - 1));
        
    return round(t, 3);

def relayCoordination(tmsT, tmsS, tmsR):
    print("Relay Coordination START")
    print("--------------------------------------------------")
    # Fuse Characteristics
    xI = [105, 130, 150, 210, 480, 3180]
    yT = [10, 1, 0.4, 0.1, 0.01, 0.01]

    # --------------------------------------------------
    print("RELAY T")
    # --------------------------------------------------
    psm = 3.25
    print("T: PSM: ", psm)
    In = 100
    print("T: Time to trip: ", 0.51)
    tms = findTMS(0.51, 1270, psm, In)
    print("T: Calculated TMS", tms)
    tms = tmsT
    print("T: TMS", tms)

    faultCurrentsT = [400, 480, 500, 550, 600, 650, 700, 750, 800, 850, 900, 1000, 1100, 1270, 1587];
    timeT = []
    for i in faultCurrentsT:
        temp = findOperatingTime(tms, i, psm, In);
        timeT.append(temp);
        if i in [480, 1270, 1587, 2120, 3180]:
            print("T: current,", i, ", time:", temp)

    tLocal = findOperatingTime(tms, 1587, psm, In)
    print("T: Local fault action time: ", tLocal)
    print("--------------------------------------------------")
    # --------------------------------------------------
    print("RELAY S")
    # --------------------------------------------------
    tTrip = tLocal + 0.5
    psm = 5.5
    print("S: PSM: ", psm)
    In = 100
    print("S: Time to trip: ", tTrip)
    tms = findTMS(tTrip, 1587, psm, In)
    print("S: Calculated TMS", tms)
    tms = tmsS
    print("S: TMS", tms)

    faultCurrentsS = [600, 650, 700, 750, 800, 850, 900, 1000, 1100, 1270, 1587, 1700, 1800, 1900, 2000, 2120];

    timeS = []
    for i in faultCurrentsS:
        temp = findOperatingTime(tms, i, psm, In);
        timeS.append(temp);
        if i in [480, 1270, 1587, 2120, 3180]:
            print("S: current,", i, ", time:", temp)

    tLocal = findOperatingTime(tms, 2120, psm, In)
    print("T: Local fault action time: ", tLocal)
    print("--------------------------------------------------")
    # --------------------------------------------------
    print("RELAY R")
    # --------------------------------------------------
    tTrip = tLocal + 0.5
    psm = 7.25
    print("R: PSM: ", psm)
    In = 100
    print("R: Time to trip: ", tTrip)
    tms = findTMS(tTrip, 2120, psm, In)
    print("R: Calculated TMS", tms)
    tms = tmsR
    print("R: TMS", tms)

    faultCurrentsR = [750, 800, 850, 900, 1000, 1100, 1270, 1587, 1700, 1800, 1900, 2000, 2120, 2250, 2400, 2600, 2800, 3180];

    timeR = []
    for i in faultCurrentsR:
        temp = findOperatingTime(tms, i, psm, In);
        timeR.append(temp);
        if i in [1270, 1587, 2120, 3180]:
            print("R: current,", i, ", time:", temp)

    fig1, ax1 = plt.subplots()
    ax1.plot(xI, yT, 'b', label="Fuse")
    ax1.plot(faultCurrentsT, timeT, '-g', label="Relay T")
    ax1.plot(faultCurrentsS, timeS, '-y', label="Relay S")
    ax1.plot(faultCurrentsR, timeR, '-r', label="Relay R")

    plt.title('IDMT Relay Coordination : Standard Inverse')
    plt.xlabel('Current (A)')
    plt.ylabel('Time (s)')
    ax1.set_xscale('log')
    ax1.set_yscale('log')
    ax1.set_xticks([100, 480, 1000, 1270, 1587, 2120, 3180])
    ax1.get_xaxis().set_major_formatter(matplotlib.ticker.ScalarFormatter())
    plt.legend()
    plt.grid(visible=True, which='major', linewidth=2, linestyle='-') 
    plt.grid(visible=True, which='minor', linewidth=1, linestyle='--')
    plt.show()

    ''' Save the PNG file '''
    filename = "idmtstandard.png"
    plt.savefig(filename)

def main():
    global bStandardIDMT

    print("Standard IDMT")
    tmsT = 0.1
    tmsS = 0.15
    tmsR = 0.2
    relayCoordination(tmsT, tmsS, tmsR);
 #   bStandardIDMT = False;
  #  print("Extreme IDMT")
   # tmsT = 0.1
    #tmsS = 0.1
#    tmsR = 0.15
 #   relayCoordination(tmsT, tmsS, tmsR);

if __name__ == '__main__':
       main()
