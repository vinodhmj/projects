import numpy
from matplotlib import pyplot as plt

def graphicalOPF():
    x = numpy.arange(0, 500, 10)
    y1 = 275 - x
    y23 = 480 - 2 * x
    ax = plt.subplot(1, 1, 1)
    ax.plot(x, y1, label = "L=P1+P2")
    ax.plot(x, y23, label = "L23")
    ax.legend()
    plt.axhline(y=50, xmin=0, xmax=300, color='r', linestyle='--', linewidth=1)
    plt.axhline(y=200, xmin=0, xmax=300, color='g', linestyle='--', linewidth=1)
    plt.axvline(x=50, ymin=0, ymax=300, color='r', linestyle=':', linewidth=1)
    plt.axvline(x=300, ymin=0, ymax=300, color='g', linestyle=':', linewidth=1)
    ax.set_ylim(bottom=0.)
    ax.set_ylim(top=310.)
    ax.set_xlim(left=0.)
    ax.set_xlim(right=310.)
    plt.xticks(numpy.arange(0, 310, 10))
    plt.yticks(numpy.arange(0, 310, 10))
    plt.show()
    
    # plt.set_ylim(bottom=0)
    # plt.plot(x, y1, label = "Gen 1", )
    # plt.legend()
    # plt.savefig('plot.png')
    # plt.show()


def main():
    graphicalOPF();
    # x = numpy.arange(10, 250, 0.1)
    # y1 = 430 - (12.5*x) + (0.15 * pow(x,2))
    # y2 = 150 - (12*x) + (0.08 * pow(x,2))


    # plt.plot(x, y1, label = "Gen 1")
    # plt.plot(x, y2, label = "Gen 2")
    # plt.legend()
    # plt.savefig('plot.png')
    # plt.show()


if __name__ == '__main__':
        main()
