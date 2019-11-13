#include <iostream>

//Se incluyen los metodos que se utilizan en el desarrollo del ejercicio
float **Producto(float **Matriz_1, float **Matriz_2, int fB, int fA, int cB, int cA);
float **Matriz_1(int n, int m);
float **Matriz_2(int n, int m);
void show(double M[20][20],int f,int c)
void relleno(float** Matriz, int n);

// Metodo que ejecuta todo
int main(int argc, char **argv){
    int N = atoi(argv[1]);
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
   
    float **Cauchy = Matriz_1(5,3);
    float **Cauchy_2 = Matriz_2(3,4);
   
    std::cout<<"Punto dos Cauchy primero:"<<std::endl;
    show(Cauchy, 6, 2);
    std::cout<<"punto dos Cauchy segundo:"<<std::endl;
    show(Cauchy_2, 4, 3);
    std::cout<<"Se multiplican las matrices:"<<std::endl;
    float **Product = Producto(Cauchy, Cauchy_2, 6, 2, 2, 3);
    show(Product, 6, 3);
   
    std::cout<<"Punto cinco de Nilpotent"<<std::endl;
    float **C = new float*[N];
    for(int i=0;i<N;i++){
        C[i] = new float[N];
    }
   
    relleno(C,N);
    std::cout<<"Se rellena la matriz"<<"\n";
    show(C,N,N);
    std::cout<<"\n";
    std::cout<<"Se multiplica por ella misma"<<std::endl;
    float **Potencia = Producto(C,C,N,N,N,N);
    std::cout<<"k="<<2<<"\n";
    show(Potencia,N,N);
    for(int i=3;i<10;i++){
        std::cout<<"k="<<i<<"\n";
        Potencia = Producto(Potencia,C,N,N,N,N);
        show(Potencia,N,N);
    }
}

void relleno(float** Matriz, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( j== n-1){
                if(i==0){
                    *(*(Matriz+i)+j)=1-n;
                }
                else{
                    *(*(Matriz+i)+j)=-n;
                }
            }
            else if(i==0){
                *(*(Matriz+i)+j)=2;
            }
            else if(i==(j+1)){
                *(*(Matriz+i)+j)=n+2;
            }
            else{
                *(*(Matriz+i)+j)=1;
            }
        }
    }
}



float **Producto(float **Matriz_1, float **Matriz_2, int fB, int fA, int cB, int cA){
   
    float **result = new float*[fA];
    for(int i=0;i<fA;i++){
        result[i] = new float[cB];
    }
   
    for(int i=0;i<fA;i++){
        for(int j=0;j<cB;j++){
            for(int k=0;k<fB;k++){
                *(*(result+i)+j) += *(*(Matriz_1+i)+k) * *(*(Matriz_2+k)+j);
            }
        }
    }
   
    return result;
}



float **Matriz_1(int n, int m){
    float **M = new float*[n];
    for(int i=0;i<n;i++){
        M[i] = new float[m];
        for(int j=0;j<m;j++){
            *(*(M+i)+j) = 1/(i + j + 1.0);
        }
    }
    return M;
}

float **Matriz_2(int n, int m){
    float **M_2 = new float*[n];
    for(int i=0;i<n;i++){
        M_2[i] = new float[m];
        for(int j=0;j<m;j++){
            *(*(M_2+i)+j) = 1/(2*i + j + 1.0);
        }
    }
    return M_2;
}

void show(double M[20][20],int f,int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            std::cout<<M[i][j]<<std::endl;
        }
    }
}