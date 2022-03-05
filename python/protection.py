import math
import numpy as np
from matplotlib import pyplot as plt

def findTMS(t, I, psm, In):
    tms = t / (0.14/(math.pow((I/(psm*In)), 0.02) - 1));
    return round(tms, 3);

def findOperatingTime(tms, I, psm, In):
    t = tms * (0.14/(math.pow((I/(psm*In)), 0.02) - 1));
    return round(t, 3);

def main():
    # Fuse Characteristics
    xI = [105, 130, 150, 210, 480]
    yT = [10, 1, 0.4, 0.1, 0.01]

    # --------------------------------------------------
    # Relay T
    # --------------------------------------------------
    print("RELAY T")
    psm = 2
    In = 100
    tms = findTMS(0.51, 1270, psm, In)
    print("T: TMS", tms)
    
    faultCurrents = [500, 750, 1000, 1270, 1587, 2120, 3180, 4000];
    timeT = []
    for i in faultCurrents:
        temp = findOperatingTime(tms, i, psm, In);
        timeT.append(temp);
        print("T: current,", i, ", time:", temp)
    # --------------------------------------------------
    # Relay S
    # --------------------------------------------------
    print("RELAY S")
    psm = 3
    In = 100
    tms = findTMS(1.01, 1587, psm, In)
    print("S: TMS", tms)
    
    timeS = []
    for i in faultCurrents:
        temp = findOperatingTime(tms, i, psm, In);
        timeS.append(temp);
        print("S: current,", i, ", time:", temp)

    # --------------------------------------------------
    # Relay R
    # --------------------------------------------------
    print("RELAY R")
    psm = 3
    In = 100
    tms = findTMS(1.51, 2120, psm, In)
    print("R: TMS", tms)
    
    timeR = []
    for i in faultCurrents:
        temp = findOperatingTime(tms, i, psm, In);
        timeR.append(temp);
        print("R: current,", i, ", time:", temp)

  
    plt.loglog(xI, yT, 'b', label="Fuse")
    plt.loglog(faultCurrents, timeT, 'o-g', label="Relay T")
    plt.loglog(faultCurrents, timeS, 'o-y', label="Relay S")
    plt.loglog(faultCurrents, timeR, 'o-r', label="Relay R")
    plt.title('IDMT Relay Coordination')
    plt.xlabel('Current (A)')
    plt.ylabel('Time (s)')
    plt.legend()
    plt.grid(visible=True, which='major', linewidth=2, linestyle='-') 
    plt.grid(visible=True, which='minor', linewidth=1, linestyle='--')
    plt.show()

if __name__ == '__main__':
        main()
