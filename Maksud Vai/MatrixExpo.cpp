/**
    Matrix Expo.
    Md. Maksud Hossain.
*/

const int MatrixSize = 2;   ///Order of Matrix.
LL ExpoMod = 1000000009;

void MatrixCopy(LL a[][MatrixSize],LL b[][MatrixSize])
{
    int i,j;
    for(i=0;i<MatrixSize;i++)
        for(j=0;j<MatrixSize;j++)  a[i][j] = b[i][j];
}

void MatrixMul(LL a[][MatrixSize],LL b[][MatrixSize])
{
    int i,j,k;
    LL mat[2][2];

    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            mat[i][j] = 0;
            for(k=0;k<2;k++)
            {
//                mat[i][j] = (mat[i][j]+a[i][k]*b[k][j])%ExpoMod;
                mat[i][j] = (mat[i][j]+(a[i][k]*b[k][j])%ExpoMod)%ExpoMod;
            }
        }

    MatrixCopy(a,mat);
}


void MatrixBigMod(LL mat[][MatrixSize],LL pow)
{
    if(pow==1)    return;

    LL a[2][2];

    MatrixCopy(a,mat);

    MatrixBigMod(a,pow/2);

    MatrixMul(a,a);

    if(pow&1) MatrixMul(a,mat);
    MatrixCopy(mat,a);
}


void MatrixInitialise(LL mat[][MatrixSize])
{
    ///Initialise the Matrix:
    mat[0][0]=3;
    mat[0][1]=2;
    mat[1][1]=1;
    mat[1][0]=0;
}

LL MatrixExpo(LL pow)
{
    ///Base Cases:
    if(pow==1)  return 2%ExpoMod;

    LL ret=0;

    LL mat[MatrixSize][MatrixSize]; ///Matrix
    MatrixInitialise(mat);

    MatrixBigMod(mat,pow-1);

    ///Calculations:

//    ret = ( )%ExpoMod;


    return ret;
}


