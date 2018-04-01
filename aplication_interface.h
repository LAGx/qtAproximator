#ifndef APLICATION_INTERFACE_H
#define APLICATION_INTERFACE_H

class IAplicationManager{
public:

    virtual void plotResult() = 0;

    virtual void changeSizeXAxis(double newSize) {} // gives opportunity change axes range
    virtual void changeSizeYAxis(double newSize) {} // gives opportunity change axes range
};

#endif // APLICATION_INTERFACE_H
