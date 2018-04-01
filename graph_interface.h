#ifndef GRAPH_INTERFACE_H
#define GRAPH_INTERFACE_H
#include <QPointF>
#include <QVector>

enum GrapgicType{
    LANGRANGE,
    LSM,
    DEFAULT
};

class IGraph{
public:

    virtual GrapgicType getType(){
        return DEFAULT;
    }

    virtual void changeState(const QVector<QPointF>& ) = 0;

    virtual double operator()(double x) = 0; //returning y
};


#endif // GRAPH_INTERFACE_H
