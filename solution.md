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
Students are currently limited to basing their knowledge of current parking on the historical data from the first two weeks of the quarter. <u> We propose a website which displays the current availability of parking spots with realtime or near-relatime update frequency </u>. This information can be viewed from anywhere and doesn't require the usage of a phone, improving accessibility and student planning ability.



#### Data Collection
<u>To more reliably collect information for the website, we propose the deployment of per-parking-spot occupancy detection devices.</u> These consist of a microcontroller and ultrasonic sensor, which are connected and indicate status via our team's PCB. The device will detect if a vehicle is present and communicate this is a computer or other server device which updates the website for students to view. For students actively inside the parking structure, indicator lights are also present, showing if a spot is occupied and what type of spot it is.



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

