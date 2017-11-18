#include "Twiddle.h"
#include <iostream>
#include <limits>
#include <math.h>

using namespace std;


Twiddle::Twiddle() {
  best_error = numeric_limits<double>::max();
  parameter = 0;
  iteration = 0;
  total_error = 0;

  dP[0] = 0.025;
  dP[1] = 0.0001;
  dP[2] = 0.25;

  for (int i = 0; i < 3; i++) {
    P[i] = 0.0;
    tried_lower[i] = false;
  }
}

Twiddle::~Twiddle() {}

void Twiddle::Update(double control, double error) {

  total_error += error;

  if ((iteration + 1) % 7) {
    iteration += 1;
    return;
  }

  cout << "CALIBRATING" << endl;

  P[parameter] += dP[parameter];

  if (total_error < best_error) {
    best_error = total_error;
    dP[parameter] *= 1.05;

    tried_lower[parameter] = false;

    parameter = (parameter + 1) % 3;
  } else {
    if (tried_lower[parameter]) {
      dP[parameter] *= 0.95;

      tried_lower[parameter] = false;

      parameter = (parameter + 1) % 3;
    } else {
      P[parameter] -= 2 * dP[parameter];

      tried_lower[parameter] = true;
    }
  }

  iteration = 0;
  total_error = 0;
}

