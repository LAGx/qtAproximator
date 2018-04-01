#ifndef LEAST_SQUARE_METHOD_H
#define LEAST_SQUARE_METHOD_H

#include <QVector>
#include "graph_interface.h"


class LeastSquareMethod_3pow: public IGraph{
public:

    GrapgicType getType(){
        return LSM;
    }

    void changeState(const QVector<QPointF>& );

    double operator()(double x); //returning y

    double getError();

private:

    double a0 = 0.001, a1 = 0.001, a2 = 0.001, a3 = 0.001;

    QVector<QPointF> basePoints;
    
    QVector<QVector<double>> b_coef;
    QVector<double> c_coef;

    QVector<double> gausSolve(const QVector<QVector<double>>& matrix, const QVector<double>& b);

};


#endif // LEAST_SQUARE_METHOD_H
