from serial import Serial, SerialException
with Serial('COM30', 9600) as ser:
    while True:
        device_report = ser.readline().decode()
        print(device_report)