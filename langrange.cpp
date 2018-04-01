#include "langrange.h"



void Langrange::changeState(const QVector<QPointF>& _vec){

    QVector<QPointF> vec = _vec;

    //for extrapolation {
    double sum = 0, amount = 0;
    for(auto& el :vec){
        sum += el.y();
        ++amount;
    }

    vec.push_front(QPointF(vec[0].x()-1, sum/amount));
    vec.push_back(QPointF(vec.back().x()+1, sum/amount));
    // }

    langrange_coefs.clear();
    x_points.clear();

    double denominator = 1;

    for(int i = 0; i < vec.size(); i++){

        for(int j = 0 ; j <  vec.size(); j++){
            if(j == i)
                continue;

            denominator *= (vec[i].x() - vec[j].x());
        }

        langrange_coefs.push_back(vec[i].y() /denominator);
        denominator = 1;
    }


    for(auto& el: vec)
        x_points.push_back(el.x());

}




double Langrange::operator()(double x){
    double func = 0;
    double numerator = 1;

    for(int i = 0; i < langrange_coefs.size(); i++){

        for(int j = 0 ; j <  langrange_coefs.size(); j++){
            if(j == i)
                continue;

            numerator *= (x - x_points[j]);
        }

        func += langrange_coefs[i]*numerator;
        numerator = 1;
    }

    return func;
}
