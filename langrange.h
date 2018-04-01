#ifndef LANGRANGE_H
#define LANGRANGE_H
#include <QPoint>
#include <QVector>
#include "graph_interface.h"


class Langrange: public IGraph{
public:

    GrapgicType getType(){
        return LANGRANGE;
    }

    void changeState(const QVector<QPointF>& );

    double operator()(double x);

private:

    QVector<double> langrange_coefs;
    QVector<double> x_points;

};


#endif // LANGRANGE_H
