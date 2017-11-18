[//]: # (Image References)
[image1]: ./animation.gif

# Simple PID Controller with Parameter Estimation ("twiddle")
Self-Driving Car Engineer Nanodegree Program

---

## Project Introduction
When running the simulator, the controller receives updates on the car's perpendicular distance from the center of the road. This error is used in a PID controller as well as an online parameter estimator using the "twiddle" technique outlined in the Udacity lessons.

The controller parameters are initialized at zero. Every 7-10 iterations, the parameters are "twiddled". This allows the controller to adapt to different conditions throughout the track.

After some time on the track the parameters settled on these values. I didn't use a PID controller on the throttle and the "twiddler" could still use some tweaking.


`Kp = 0.138`

`Ki = 0.001`

`Kd = 4.766`


![alt text][image1]


#### Installation
This project requires the Udacity Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases).

Docker is the easiest, simply cd to the directory where you clone this repo and run:

``docker run -t -d --rm -p 4567:4567 -v `pwd`:/work udacity/controls_kit:latest``


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`

