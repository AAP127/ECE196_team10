from serial import Serial, SerialException

#Example Parking spot sensor setup

# Function to print available spots
# Accepts list of current availabilities and keys
# Expects availability[i] represents number of prdering[i] spots available
def availability_report(availability, ordering):
    for i in range(len(ordering)):
        spot_report = ordering[i] + ": " + str(availability[i])
        print(spot_report)


# Function to streamline formatting of reporting updated parking availability
def print_updated_report(availability,ordering):
    print("--------------------------")
    print("Parking Availability has been updated:")
    availability_report(availability,ordering)
    print("--------------------------")


# Define how many parking spots exist for each type
# List to store spot availability
# Order is A, B, S, V
spots_available = [140, 350, 30, 20]
spot_ordering = ['A','B','S','V']

# Store existing states of all parking spots
# List size = number of spots supported
# For demo, this is a single spot, but 5 spots would have 5 indices
parking_states = [False]


with Serial('COM30', 9600) as ser:
    while True:
        device_report = ser.readline().decode()
        # print(device_report)

        # Determine device spot type
        # Assumes format of "Spot type: {num}, ..."
        # A-1, B-2, S-3, V
        spot_type = int(device_report.split("Spot type: ")[1][0])

        #Process spot detection based on availability and type
        # Spot is now empty
        if("EMPTY" in device_report and parking_states[0]):
            parking_states[0] = False
            spots_available[spot_type] +=1
            print_updated_report(spots_available, spot_ordering)

        #Spot is now full
        elif("OCCUPIED" in device_report and not parking_states[0]):
            parking_states[0] = True
            spots_available[spot_type] -=1
            print_updated_report(spots_available, spot_ordering)
