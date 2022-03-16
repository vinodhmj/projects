import math
import numpy as np
import matplotlib
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
    psm = 2.25
    In = 100
    tms = findTMS(0.51, 1270, psm, In)
    print("T: TMS", tms)

    faultCurrentsT = [350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900, 1000, 1100, 1270, 1587];
    timeT = []
    for i in faultCurrentsT:
        temp = findOperatingTime(tms, i, psm, In);
        timeT.append(temp);
        print("T: current,", i, ", time:", temp)
    # --------------------------------------------------
    # Relay S
    # --------------------------------------------------
    print("RELAY S")
    psm = 4.25
    In = 100
    t1 = 1.01
    tms = findTMS(1.01, 1587, psm, In)
    print("S: TMS", tms)

    faultCurrentsS = [500, 550, 600, 650, 700, 750, 800, 850, 900, 1000, 1100, 1270, 1587, 1700, 1800, 1900, 2000, 2120];

    timeS = []
    for i in faultCurrentsS:
        temp = findOperatingTime(tms, i, psm, In);
        timeS.append(temp);
        print("S: current,", i, ", time:", temp)

    # --------------------------------------------------
    # Relay R
    # --------------------------------------------------
    print("RELAY R")
    psm = 6.5
    In = 100
    tms = findTMS(1.51, 2120, psm, In)
    print("R: TMS", tms)

    tms = 0.2
    faultCurrentsR = [750, 800, 850, 900, 1000, 1100, 1270, 1587, 1700, 1800, 1900, 2000, 2120, 2250, 2400, 2600, 2800, 3180];

    timeR = []
    for i in faultCurrentsR:
        temp = findOperatingTime(tms, i, psm, In);
        timeR.append(temp);
        print("R: current,", i, ", time:", temp)

    fig1, ax1 = plt.subplots()
    ax1.plot(xI, yT, 'b', label="Fuse")
    ax1.plot(faultCurrentsT, timeT, '-g', label="Relay T")
    ax1.plot(faultCurrentsS, timeS, '-y', label="Relay S")
    ax1.plot(faultCurrentsR, timeR, '-r', label="Relay R")
#    ax1.axvline(x=1587, color='k', linestyle=':')

    plt.title('IDMT Relay Coordination')
    plt.xlabel('Current (A)')
    plt.ylabel('Time (s)')
    ax1.set_xscale('log')
    ax1.set_yscale('log')
    ax1.set_xticks([100, 480, 1000, 1270, 1587, 2120, 3180])
    ax1.get_xaxis().set_major_formatter(matplotlib.ticker.ScalarFormatter())
    plt.legend()
    plt.grid(visible=True, which='major', linewidth=2, linestyle='-') 
    plt.grid(visible=True, which='minor', linewidth=1, linestyle='--')
    # plt.show()

    ''' Save the PNG file '''
    filename = "ED_Graphical_Solution.png"
    plt.savefig(filename)

    # plt.loglog(xI, yT, 'b', label="Fuse")
    # plt.loglog(faultCurrentsT, timeT, '-g', label="Relay T")
    # plt.loglog(faultCurrentsS, timeS, '-y', label="Relay S")
    # plt.loglog(faultCurrentsR, timeR, '-r', label="Relay R")
    # plt.axvline(x=1587, color='k', linestyle=':')

    # plt.title('IDMT Relay Coordination')
    # plt.xlabel('Current (A)')
    # plt.ylabel('Time (s)')
    # #plt.set_xscale('log')
    # #plt.set_xticks([1, 10, 100, 1000, 1587, 2120, 3180])
    # plt.legend()
    # plt.grid(visible=True, which='major', linewidth=2, linestyle='-') 
    # plt.grid(visible=True, which='minor', linewidth=1, linestyle='--')
    # plt.show()

if __name__ == '__main__':
        main()
