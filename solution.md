<nav style="background-color: white; padding: 1em;">
  <a href="/" style="color:#000; margin-right: 15px; text-decoration: underline;">Home</a>
  <a href="/problem" style="color:#000; margin-right: 15px; text-decoration: underline;">The Problem</a>
  <a href="/solution" style="color: #000; margin-right: 15px; text-decoration: underline;">Our Solution</a>
  <a href="/milestones_progress" style="color:#000; margin-right: 15px; text-decoration: underline;"> Milestones and Progress </a>
  <a href="/pcb" style="color:#000;margin-right: 15px;  text-decoration: underline;">Our PCB</a>
  <a href="/team" style="color:#000; margin-right: 15px; text-decoration: underline;">About Us</a>
</nav>


# Our Solution

## Description
![Image of parking structure and website](source/solution/solution_diagram_2.png)

Currently, we have identified two key concerns with the current student experience of parking on campus: **Information Distribution** and **Data Collection**

#### Information Distribution
Students are currently limited to basing their knowledge of current parking on the historical data from the first two weeks of the quarter. We propose a website which displays the current availability of parking spots with realtime or near-relatime update frequency. The site report the information collected by parking sensors in campus parking structures, greatly improving accessibility.




- The solution involves the usage of a proximity sensor, which detects a car being present, communicating to a microcontroller. 
- This microcontroller communicates parking data to a host computer
- The computer can then update the website with accurate parking information.


#### Data Collection


## Technology Block Diagram
![Hardware Block Diagram](source/solution/tech_diagram_2.png)


## Technology Highlights
\* Key technological usage in the project includes:
- Proximity sensor/ wiring
- Microcontroller 
  - Wiring
  - Programming to interpret sensor data
  - Programming to communicate with computer server
- Program design
  - Code to interpret microcontroller communication
  - Code to update website
- Website
  - Webfront
  - Database to pull parking data from

