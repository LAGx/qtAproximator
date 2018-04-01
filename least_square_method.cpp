#include "least_square_method.h"
#include <math.h>



void LeastSquareMethod_3pow::changeState(const QVector<QPointF>& _basePoints){
    basePoints = _basePoints;
    const int rang = 4;
    
    for(auto& line: b_coef)
        line.clear();
    b_coef.clear();
   c_coef.clear();
    
    b_coef.reserve(rang);
    for(auto& line: b_coef)
        line.reserve(rang);
   
    for(int k = 0; k < rang; k++){
        b_coef.push_back(QVector<double>());
        for(int g = 0; g < rang; g++){
            b_coef[k].push_back(0);
            for(int i = 0; i < basePoints.size(); i++)
                b_coef[k][g] += pow( basePoints[i].x(), (rang+2) - g - k);
         }
    }
    
    
    for(int k = 0; k < rang; k++){
        c_coef.push_back(0);
        for(int i = 0; i < basePoints.size(); i++)
            c_coef[k] += basePoints[i].y()*pow(basePoints[i].x(), rang-1 - k);
    }

    QVector<double> solve = gausSolve(b_coef, c_coef);
    a0 = solve[0];
    a1 = solve[1];
    a2 = solve[2];
    a3 = solve[3];
    
}



double LeastSquareMethod_3pow::operator()(double x){
    return a0*pow(x, 3) + a1*pow(x, 2) + a2*pow(x, 1) + a3*pow(x, 0);
}



double LeastSquareMethod_3pow::getError(){
    double error = 0;

    for(auto& point: basePoints)
        error += pow((double)point.y() - this->operator()(point.x()),2);

    return error;
}


QVector<double> LeastSquareMethod_3pow::gausSolve(const QVector<QVector<double>>& matrix, const QVector<double>& b){

    QVector<QVector<double>> A = matrix;

    for(int i = 0; i < A.size();i++){
        A[i].push_back(b[i]);
    }


    int n = A.size();

           for (int i=0; i<n; i++) {

            double maxEl = abs(A[i][i]);
            int maxRow = i;
            for (int k=i+1; k<n; k++) {
                if (abs(A[k][i]) > maxEl) {
                    maxEl = abs(A[k][i]);
                    maxRow = k;
                }
            }

            for (int k=i; k<n+1;k++) {
                double tmp = A[maxRow][k];
                A[maxRow][k] = A[i][k];
                A[i][k] = tmp;
            }


            for (int k=i+1; k<n; k++) {
                double c = -A[k][i]/A[i][i];
                for (int j=i; j<n+1; j++) {
                    if (i==j) {
                        A[k][j] = 0;
                    } else {
                        A[k][j] += c * A[i][j];
                    }
                }
            }
        }

        QVector<double> x(n);


        for (int i=n-1; i>=0; i--) {
            x[i] = A[i][n]/A[i][i];
            for (int k=i-1;k>=0; k--) {
                A[k][n] -= A[k][i] * x[i];
            }
        }

    return x;
}



