<link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">
<style>
  body {
    background-color:rgb(224, 232, 249);
    color:rgb(0, 0, 0);
    font-family: 'Roboto', sans-serif;
    margin: 0;
    padding: 0;
  }

  nav {
    background-color: #FFD100;
    padding: 1em;
    text-align: center;
    box-shadow: 0 2px 4px rgba(0,0,0,0.1);
  }

  nav a {
    color: #00274C;
    margin: 0 15px;
    font-weight: bold;
    text-decoration: none;
  }

  nav a:hover {
    text-decoration: underline;
  }

  .content {
    background-color: white;
    margin: 2em auto;
    padding: 2em;
    max-width: 960px;
    border-radius: 10px;
    box-shadow: 0 2px 6px rgba(0,0,0,0.08);
  }

  img {
    border-radius: 8px;
    margin: 1em 0;
  }
</style>

<nav style="background-color: rgb(224, 232, 249); padding: 1em;">


  <a href="/ECE196_team10/" style="color:#000; margin-right: 15px; text-decoration: underline;">Home</a>
  <a href="/ECE196_team10/problem" style="color:#000; margin-right: 15px; text-decoration: underline;">The Problem</a>
  <a href="/ECE196_team10/solution" style="color: #000; margin-right: 15px; text-decoration: underline;">Our Solution</a>
  <a href="/ECE196_team10/milestones_progress" style="color:#000; margin-right: 15px; text-decoration: underline;"> Milestones and Progress </a>
  <a href="/ECE196_team10/pcb" style="color:#000;margin-right: 15px;  text-decoration: underline;">Our PCB</a>
  <a href="https://docs.google.com/presentation/d/1rFXBSj3DbrjLsAPUIrnIcoYYUYrfbvTKr-7pOcrXOec/edit?usp=sharing" style="color:#000;margin-right: 15px;  text-decoration: underline;">Poster</a>
  <a href="https://drive.google.com/file/d/1jj1QcZ62BZAWAesPke6ln_tHwNwHV5pS/view?usp=sharing" style="color:#000;margin-right: 15px;  text-decoration: underline;">Video</a>
  <a href="https://aap127.github.io/ECE196_team10/team#mini-projects-3-tutorials" style="color:#000;margin-right: 15px;  text-decoration: underline;">Mini Project Tutorials</a>
  <a href="/ECE196_team10/team" style="color:#000; margin-right: 15px; text-decoration: underline;">About Us</a>
  <a href="/ECE196_team10/application_website_GPF/index.html" style="color:#000; margin-right: 15px; text-decoration: underline;">Our Application</a>
</nav>

# Our PCB Design

## Overview/ Explaination

We have created a 4 layer PCB board to support our smart parking indicator system with the following key highlights:

- It is centered around an **ESP32-Mini microcontroller** that will be used to communicate with our website. 

- It features **dual-row header pins** (J1 and J2) to connect to the ESP32 .

- Four LEDs with resistors labeled R1, R2, R5, and R6, serve as **parking mode indicators**. They indicate if the device is reporting for an A, B, S, or V spot. 

- The other two LEDs with resistors labeled R3 and R4 show **real-time availability** (i.e. if the spot is detected as occupied or not). 
  
- Two 4-pin connectors (J3 and J6) will support  **HC-SR04 ultrasonic sensors** to detect vehicle presence. 
  
- **Power and ground** are routed from the ESP32 through the board to supply all components. 
 

## Board Development

### 1. Wiring Schematic
<img src="source/pcb/ECE196_WiringSchem.png" alt="PCB Wiring Schematic" width="100%" height="auto">



### 2. PCB Schematic and Diagram
<img src="source/pcb/PCB_annotated.png" alt="PCB Board Diagram" width="48.5%" height="auto">
<img src="source/pcb/PCB_annotated2.png" alt="PCB 3D Model" width="45%" height="auto">


### 3. Physical Board
<img src="source/pcb/pcb_physical.jpg" alt="Physical PCB Board" width="50%" height="auto">


### 4. Assembled Board
<img src="source/pcb/pcb_assembled2.jpg" alt="Fully Assembled PCB" width="100%" height="auto">



## Design Challenges/ Pivots

Our board initially was designed to run the ultrasonic sensors off of <strong>3.3V supply voltage</strong> (as opposed to 5V), as our ESP-32 would then be able to accept the signals.

After our board was finalized and ordered, our team determined that our ultrasonic sensors, despite advertising and the datasheet, <strong>did not function correctly when supplied with 3.3V input</strong>. Due to this, we had to pivot our design to include a <strong>logic level shifter</strong>. This allows the ESP-32, which uses 3.3V to represent a HIGH signal, to communicate with the sensor, which uses 5V for its signals.

As seen in the image above, the setup uses additional wiring for the signals and reference voltages for the logic level shifter. This allows us to recieve the send and recieve the correct signals which the ESP-32 is able to use.
