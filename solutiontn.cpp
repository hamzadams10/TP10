#include "matrix.h"

double* Grad_Conjug(double** A, double* b, double* x_k, int dim, double epsilon) 
{   
    int count_itere = 0;
    double* r_k = new double[dim];
    double* p_k = new double[dim];
    double* r_k_1 = new double[dim];
    double* x_k_1 = new double[dim];
    double* p_k_1 = new double[dim];
    double* dot_x = dot_col(A, x_k, dim);
    double* dot_p = new double[dim];
    double * diff = create_col(dim);
    for(int i=0; i<dim; i++)
        r_k[i] = b[i] - dot_x[i];
    for(int i=0; i<dim; i++){
        p_k[i] = r_k[i];
    }
    double alpha_k;
    double beta_k;
    double * test_grad_conjug = create_col(dim);
    test_grad_conjug = dot_col(A, x_k, dim);
    cout << "dot_col = " ;
    print_array(test_grad_conjug, dim);
    cout << "must_ be equal to ";
    print_array(b, dim);
}
