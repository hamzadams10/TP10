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
    while(1){
        dot_p = dot_col(A, p_k, dim);
        alpha_k = scalar_product(r_k, r_k, dim)/scalar_product(dot_p, p_k, dim);
        for(int i=0; i<dim; i++){
          x_k_1[i] = x_k[i] + alpha_k*p_k[i];
          r_k_1[i] = r_k[i] - alpha_k*dot_p[i]; 
        }
        count_itere++;
        cout << "scalar_product = " <<scalar_product(r_k_1, r_k_1, dim) <<endl;
        if(scalar_product(r_k_1, r_k_1, dim) < epsilon){
          delete []r_k;
          delete []p_k;
          delete []r_k_1;
          delete []p_k_1;
          delete []dot_x;
          delete []dot_p;
          cout << "le nombre d'itérations est :   " << count_itere << endl;
          return x_k_1;
        }
        beta_k = scalar_product(r_k_1, r_k_1, dim)/scalar_product(r_k, r_k, dim);
        for(int i=0; i<dim; i++)
            p_k_1[i] = r_k_1[i] + beta_k*p_k[i];
        for(int i=0; i<dim; i++){
            r_k[i] = r_k_1[i];
            p_k[i] = p_k_1[i];
            x_k[i] = x_k_1[i];
        }
        for (int i = 0; i < dim; i++){
            diff[i] = abs(dot_col(A, x_k, dim)[i] - b[i]);
        }
        cout << "diff array & norme = ";
        print_array(diff, dim);
        cout << "nor =  " << endl;
        cout << norm(diff, dim);
    }
    double * test_grad_conjug = create_col(dim);
    test_grad_conjug = dot_col(A, x_k, dim);
    cout << "dot_col = " ;
    print_array(test_grad_conjug, dim);
    cout << "must_ be equal to ";
    print_array(b, dim);
}
