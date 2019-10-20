# bird-backpacks
HackUmass VII

## Description as a Tweet:

As birds migrate south each winter, they can be difficult to track, especially in extreme climates. Our product, Bird Backpacks provides a cheap, simple way to monitor them by using light-level geolocators, pushing data to the cloud, and predicting their possible locations.

## Inspiration:

A professor introduced one of our team members to a similar device that tracks small migrations of birds, specifically the Dark Eyed Junco, but doesn’t actively log data in real time and in a hard-to-interpret CSV file. We realized how important it is to track these migrations, especially during these times of climate change and extreme natural phenomena where patterns can drastically change, and knew we could create a more viable product. 
Another one of our team members has been recently following the bird migration tracking research with deep learning being done at UMass’s College of Information and Computer Science, and thought it would be interesting to create something revolving around similar ideas, as an avid birder herself.

## What it does:

Tracking a bird’s migratory patterns has historically been extremely difficult as sending satellite telemetry is usually extremely expensive and often is not effective for long-term tracking. Geolocation trackers are a more popular way for researchers to track birds, however, the devices themselves come with many disadvantages. Firstly, after attaching the device to the bird, there is no way to monitor the bird or the data while the bird is migrating. All data is stored on a tiny memory chip. One of the biggest hurdles of tracking bird migrations has been the need to recapture the bird after a period of usually several months to 1-2 years. Many times researchers are only able to recapture a small fraction of the birds they are tracking which prohibits the volume of research produced. One of the metrics researchers use in order to calculate the locations of the bird during its migration is light and time. What our project aimed to do was implement a way to stream this light and time data to a cloud service in order to allow researchers to view data as soon as they attach a tracker to a bird as well as set the time intervals they want data to be recorded. We also implemented a web interface that allows researchers to view their data in a more aesthetic manner which in the future can be expanded to provide visualizations in real-time of the bird’s location. Geolocation trackers can also often be extremely expensive compared to the computing power of the actual device. We created our own tracker that uses an independent microcontroller and photoresistors to record metrics and make it easy to download/retrieve data from the device.

## How we built it:

We took a series of photoresistors and wired them up to an Arduino so that it could retrieve serial values for the amount of light present. We then hooked this up to a Raspberry Pi using Python scripts as well as generated a separate CSV file that continuously grabs values from the Arduino. The Raspberry Pi is then used to convert the data of light values, time stamps, and relative location into JSON format and send it over to Google Cloud Platform where we used their IoT Core and Cloud Datalab to organize the data. We then used Cloud Dataflow to stream the data in real time, Cloud Pub/Sub to store it, and used this to tell BigQuery to organize the data and populate it with our flow of data. Google Cloud Platform was running most of the processes using Kubernetes Engine and Compute Engine. Finally, we took Google Cloud Platform’s Big Query API to push our data to a web interface, created using Flask, HTML, and CSS.

## Technologies we used:

HTML/CSS
SQL
C/C++/C#
Python
Flask
Arduino
Raspberry Pi
Microcontrollers
AI/Machine Learning

## Challenges we ran into:

We faced numerous challenges throughout the course of the weekend. First we had issues getting serial data off the Arduino into a standard file format; however with the tremendous help of mentor Matt, we were able to overcome this within a couple hours. 
A much larger task at hand to tackle was feeding data from the Raspberry Pi into the cloud. We had to use a Google Cloud provided python script meant for sending data from the Arduino sensors into our cloud project, which consumed most of our time. It was a very technical process trying to translate the serial data in various functions in real time and send the correct data in the correct formats. Various scripts would fail in the shell and virtual machine, which slowed us down a lot, and didn’t allow us to progress as much as we wanted to. Eventually, we managed to get over this hurdle and get the data streaming into the cloud.

## Accomplishments we're proud of:

We are very proud of building a cheap bird tracking device that efficiently retrieves data. Our market competitors’ products cost thousands of dollars to bring up the same information in a-many-times difficult to interpret CSV file. We are also proud of learning how to use so many new technologies and integrating them within our project during this short time period.

## What we've learned:

We learned how to integrate various aspects of software and hardware together, including hooking up an Arduino to a Raspberry Pi, getting serial values off a photoresistor, bringing all the data gathered by our hardware into the cloud using scripts, and deploying it all on a web interface. We learned about JSON web tokens, how data is stored in Arduino, and learned how to use BigQuery's API to dynamically display datasets on the web. We all came in with a wide variety of skill sets and we were able to effectively communicate with one another and use everyone’s strengths to create a viable product. Google Cloud was a tool none of us were familiar with before coming here but after this event, we learned it is a powerful platform for storing data and is an amazing tool when it comes to sending telemetry. It allowed us to collect and store data in real time which has very good implications in transforming the process of bird tracking.

## What's next:

Next, we are looking to solidify a deep learning algorithm/neural network using our training data and extensive convolutions to effectively predict the migratory patterns and locations of certain bird species. We also plan to scale our prototype to a size that can be attached to smaller birds and track accurately while consistently sending data.

## Built with:

We built our project using various hardware, including an Arduino, Raspberry Pi, and sensors. We used Python scripts to push data to Google Cloud Platform, and made use of their various APIs including IoT Core, Cloud Dataflow, BigQuery, Cloud Datalab, Kubernetes Engine, Compute Engine and more to analyze our data to track migrations and display the results, as well as creating our own SQL database. We also used Flask, HTML, Bootstrap, and the GCP APIs to display our data on a web interface.
