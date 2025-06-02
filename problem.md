<!-- UCSD Theme Styling -->
<link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">
<style>
  body {
    background-color:rgb(200, 247, 253);
    color: #00274C;
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

<nav style="background-color: #FFD100; padding: 1em;">
  <a href="/ECE196_team10/" style="color:#000; margin-right: 15px; text-decoration: underline;">Home</a>
  <a href="/ECE196_team10/problem" style="color:#000; margin-right: 15px; text-decoration: underline;">The Problem</a>
  <a href="/ECE196_team10/solution" style="color: #000; margin-right: 15px; text-decoration: underline;">Our Solution</a>
  <a href="/ECE196_team10/milestones_progress" style="color:#000; margin-right: 15px; text-decoration: underline;"> Milestones and Progress </a>
  <a href="/ECE196_team10/pcb" style="color:#000;margin-right: 15px;  text-decoration: underline;">Our PCB</a>
  <a href="/ECE196_team10/team" style="color:#000; margin-right: 15px; text-decoration: underline;">About Us</a>
  <a href="/ECE196_team10/application_website_GPF/index.html" style="color:#000; margin-right: 15px; text-decoration: underline;">Our Application</a>
</nav>

<div class="content">

# Our Focus

## The Problem

As a student, it can be difficult to find parking for classes, especially during congested times of the day. This is especially true for students using campus parking structures. **Knowing how many spots are available gives better context for a student to understand where they might want to park, or if they should come to campus at all.**

<img src="source/problem/parking_structure.jpg" alt="Image of full parking structure" width="75%">

<small>*Photo credit: The UCSD Guardian – https://ucsdguardian.org/2024/02/05/the-parking-problem/</small>

---

## Our Motivation

This problem affects both students and faculty, often leading to lost time, stress, and even parking tickets. The issue isn’t just campus-specific — it also applies to public parking structures. Our team chose this project because we’ve experienced this ourselves, and we believe a real solution could significantly **improve campus life**.

<img src="source/problem/ParkingTicket.jpg" alt="Image of parking ticket" width="75%">

---

## Current Solutions

### <u>Information Distribution</u>

Students currently rely on a few imperfect options:
- **UCSD Parking Estimates** (based on data from the first two weeks of the quarter)

<img src="source/problem/parking_estimate_website.JPG" alt="Parking estimate screenshot" width="40%">
<small>*https://transportation.ucsd.edu/commute/availability.html</small>

- **Live Displays** outside parking structures (only visible on-site)

<img src="source/problem/parking_display.jpg" alt="Parking availability display" width="40%">
<small>*Image credit: https://today.ucsd.edu/story/parking-on-campus-theres-an-app-for-that</small>

- **UCSD Parking App** (provides general spot percentages but lacks detail by permit type)

<img src="source/problem/ucsd_app.jpg" alt="UCSD App" width="25%">
<small>*Image credit: https://today.ucsd.edu/story/parking-on-campus-theres-an-app-for-that</small>

---

### <u>Data Collection Issues</u>

Existing parking sensors are installed, but often unreliable:
- Sometimes display a green light for a spot that's actually full
- Cause confusion and reduce trust in the system

<img src="source/problem/ucsd_err1.jpg" alt="Faulty sensor reading 1" width="50%">
<img src="source/problem/ucsd_err2.jpg" alt="Faulty sensor reading 2" width="50%">

</div>
