<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ECE 196 Team 10 – Smart Parking</title>
  <link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">
  <style>
    body {
      margin: 0;
      font-family: 'Roboto', sans-serif;
      background-color: #f4f6fa;
      color: #00274C;
    }
    nav {
      background-color: #FFD100;
      padding: 1em;
      text-align: center;
    }
    nav a {
      color: #00274C;
      margin: 0 15px;
      text-decoration: none;
      font-weight: bold;
    }
    nav a:hover {
      text-decoration: underline;
    }
    header {
      padding: 2em;
      text-align: center;
      background: white;
      box-shadow: 0 2px 4px rgba(0,0,0,0.1);
    }
    header h1 {
      color: #00629B;
    }
    header p {
      max-width: 800px;
      margin: auto;
      font-size: 1.1em;
    }
    .images {
      display: flex;
      justify-content: center;
      gap: 1em;
      flex-wrap: wrap;
      padding: 2em;
    }
    .images img {
      max-width: 300px;
      border-radius: 10px;
      box-shadow: 0 2px 8px rgba(0,0,0,0.1);
    }
  </style>
</head>
<body>
  <nav>
    <a href="/ECE196_team10/">Home</a>
    <a href="/ECE196_team10/problem">The Problem</a>
    <a href="/ECE196_team10/solution">Our Solution</a>
    <a href="/ECE196_team10/milestones_progress">Milestones and Progress</a>
    <a href="/ECE196_team10/pcb">Our PCB</a>
    <a href="/ECE196_team10/team">About Us</a>
  </nav>

  <header>
    <h1>ECE 196 Spring 25 Team 10: Improving the Student Parking Experience</h1>
    <p>Welcome to the official website of ECE 196 Team 10. Our project focuses on enhancing the student parking experience at UC San Diego by providing real-time visibility into parking availability. By integrating Bluetooth-enabled ultrasonic sensors and a custom web dashboard, we aim to deliver accurate, live data on parking space occupancy, helping students make informed decisions before arriving on campus.</p>
  </header>

  <div class="images">
    <img src="source/index/UCSDLogo_JSOE_BlueGold_Print.jpg" alt="UCSD Logo">
    <img src="source/index/geisel.jpg" alt="Geisel Library">
    <img src="source/index/south.jpg" alt="South Parking Structure">
  </div>
</body>
</html>
