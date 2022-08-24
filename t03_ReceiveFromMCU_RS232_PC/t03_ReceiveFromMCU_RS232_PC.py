import serial
import time


def getValuMCU():
    SerialObj = serial.Serial('/dev/ttyACM0')
    SerialObj.timeout = 1
    time.sleep(1)
    try:
        while True:
            ReceivedString = SerialObj.readline()
            print(ReceivedString)
            # return(ReceivedString)
    except KeyboardInterrupt:
        pass

    SerialObj.close()

getValuMCU()

# carStatus = getValuMCU()
# print(carStatus)