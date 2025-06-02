<link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">
<style>
  body {
    background-color: rgb(222, 251, 234);
    color: rgb(1, 21, 39);
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

<nav>
  <a href="/ECE196_team10/">Home</a>
  <a href="/ECE196_team10/problem">The Problem</a>
  <a href="/ECE196_team10/solution">Our Solution</a>
  <a href="/ECE196_team10/milestones_progress">Milestones and Progress</a>
  <a href="/ECE196_team10/pcb">Our PCB</a>
  <a href="/ECE196_team10/team">About Us</a>
  <a href="/ECE196_team10/application_website_GPF/index.html">Our Application</a>
</nav>

<div class="content">

## The Problem:

As a student, it can be difficult to find parking for classes, especially during congested times of the day. This is especially true for students using campus parking structures. **Knowing how many spots are available gives better context for a student to understand where they might want to park, if they should show up to campus at all.**


<img src="source/problem/parking_structure.jpg" alt="Image of full parking structure" width="75%" height="auto">

<small>*Photo credit to The UCSD Guardian (https://ucsdguardian.org/2024/02/05/the-parking-problem/)</small>





## Our Motivation:

The team chose to tackle this issue because it is a recurring problem that affects both students and faculty, often leading to negative consequences. These include wasted time and the need to park in illegal spaces-- resulting in the risk of recieving overpriced parking tickets. This challenge also extends beyond on-campus parking and includes many public parking strutures. Our motivation comes from not only how common this issue is, but also from experiencing it ourselves. By tackling this problem, we aim to create a solution that **improves campus life for students and faculty**.


<img src="source/problem/ParkingTicket.jpg" alt="Image of parking ticket" width="75%" height="auto">


## Current Solutions:

#### <u>Information Distribution</u>:
Currently, to know where they should park, students have a few options:

* UCSD releases parking data collected during the first two weeks of each quarter, giving a rough estimate of demand. 

<img src="source/problem/parking_estimate_website.JPG" alt="Image of parking estimation website" width="40%" height="auto">

<small>*https://transportation.ucsd.edu/commute/availability.html</small>


* Students can view the displays outside the parking structure to see how many spots are reported to be available. However, this requires them to have already chosen to drive to campus.

<img src="source/problem/parking_display.jpg" alt="Image of parking availability display" width="40%" height="auto">

<small>*Image credit: https://today.ucsd.edu/story/parking-on-campus-theres-an-app-for-that</small>


* The most robust option is the UCSD app, which reports the percentage of spot types (A,B,S, etc) available. The total estimated number of spots available is also reported. The main drawbacks are still requiring the usage of a phone, and not reporting the estimated amount of spots per each type available (i.e. how many A spots, B spots) vs just a total.

<img src="source/problem/ucsd_app.jpg" alt="Image of ucsd app" width="25%" height="auto">

<small>*Image credit: https://today.ucsd.edu/story/parking-on-campus-theres-an-app-for-that</small>




#### <u>Data Collection</u> :
Additionally, parking sensors have already been implemented, however they may not always function as intended. Specifically, the number of available spots displayed does not accurately reflect the actual availability on each parking level. _In some cases, the system shows a green light indicating an open space, even when the spot is already occupied._ Ensuring the sensors operate as designed would greatly improve parking accuracy and reduce confusion for drivers.


<img src="source/problem/ucsd_err1.jpg" alt="Image of incorrect sensor UCSD- 1" width="50%" height="auto">
<img src="source/problem/ucsd_err2.jpg" alt="Image of incorrect sensor UCSD- 2" width="50%" height="auto">