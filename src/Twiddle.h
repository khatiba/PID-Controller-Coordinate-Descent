#ifndef Twiddle_H
#define Twiddle_H

class Twiddle {
  public:
    double P[3];
    double dP[3];
    bool tried_lower[3];
    int parameter;
    int iteration;
    double best_error;
    double total_error;

    Twiddle();
    void Update(double control, double error);

    virtual ~Twiddle();
};


#endif /* Twiddle_H */
