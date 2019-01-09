#include"fontions.h"
#include"matrix.h"

int main(){
	double **mat1 = create_mat(5) ;
	double **mat2 = create_mat(5) ;
	double **mat3 = create_mat(5) ;

	

    double a [5][5] = {{320, 4, 5, 6, 10},
    				   {4, 300, 7 ,71,20},
    				   {5, 7, 200, 5,  2}, 
    				   {6, 71,5,350,4}, 
    				   {10, 20,2,4,250}};

    double a2 [4][4] = {{1, 1, 1, 1 },
                        {1, 5, 5, 5 },
                        {1, 5, 14,14}, 
                        {1, 5,14,15}};
    double a3[4][4] = {{1, 2, 3, 4},
                       {0, 3, 5, 7},
                       {0, 0, 7, 9},
                       {0, 0, 0, 4}};

    double ** lower1 = create_mat(5);
    double ** lower2 = create_mat(4);

    
    for (int i = 0 ; i < 5; i++){
    	for (int j = 0; j < 5; j++){
    		mat1[i][j] = a[i][j] ;
    	}
    }
    for (int i = 0 ; i < 4; i++){
        for (int j = 0; j < 4; j++){
            mat2[i][j] = a2[i][j];
            mat3[i][j] = a3[i][j];
        }
    }

    //TESTING GRADIENT CONJUGUE
    cout << "testing grad conjug" << endl;
    cout << " " << endl;

    double * x_conjug  = create_col(dim);
    double * grad_conjug_test = Grad_Conjug(mat, col, x_conjug, dim,eps);
    double * dot_conjug = dot_col(mat, x_conjug, dim);
    cout << "dot_conjug = ";
    print_array(dot_conjug, dim);
    

    


    //free memory
    //delete[] col_1;
    free_matrix(mat1,5);
    free_matrix(mat2,4);
    free_matrix(mat3,4);
    free_matrix(lower1,5);
    free_matrix(lower2,4);




	return 0;

}
