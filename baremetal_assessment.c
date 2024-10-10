/*
NAME :ANIL KUMAR 
DATE :10-10-2024
DESCRIPTION : Basemetal Assessment 
SAMPLE INPUT : 
SAMPLE OUTPUT :
 */

#include<stdio.h>

typedef struct _Vector
{
    
    double v1,v2,v3;

}Vector;

typedef struct _Quaterion
{
    
    double s;
    Vector v ;

}Quaterion;


Quaterion q_def(double a,double b,double c, double d)
{
    //Defining scalar and vector values of Quaterion-1
    Quaterion q;
    
    q.s = a;
    
    q.v.v1 = b;
    q.v.v2 = c;
    q.v.v3 = d;
    
    return q;
}


Quaterion compliment(Quaterion q)
{
   //Complimenting the vector values of Quaterion-1
    q.s *= 1;
    
    q.v.v1 *= -1;
    q.v.v2 *= -1;
    q.v.v3 *= -1;
    
    return q;
}


Quaterion multiplication(Quaterion q,Quaterion q_bar)
{
    //Product of 2 Quaterions and returning the result
    Quaterion result;

    result.s	=	q.s * q_bar.s - q.v.v1 * q_bar.v.v1 - q.v.v2 * q_bar.v.v2 - q.v.v3 * q_bar.v.v3;
    
    result.v.v1	=	q.s * q_bar.v.v1 + q.v.v1 * q_bar.s + q.v.v2 * q_bar.v.v3 - q.v.v3 * q_bar.v.v2;
    result.v.v2	=	q.s * q_bar.v.v2 + q.v.v2 * q_bar.s + q.v.v3 * q_bar.v.v1 - q.v.v1 * q_bar.v.v3;
    result.v.v3	=	q.s * q_bar.v.v3 + q.v.v3 * q_bar.s + q.v.v1 * q_bar.v.v2 - q.v.v2 * q_bar.v.v1;
    
    return result;
}


double dot_prod(Quaterion q,Quaterion q2)
{
    //Dot product of 2 Quaterions
    double dot	=	q.s * q2.s + q.v.v1 * q2.v.v2 + q.v.v2 * q2.v.v2 + q.v.v3 * q2.v.v3;
    
    return dot;
}


int main()
{
    Quaterion q	=	q_def(1,2,3,4); //q is main quaterion

    Quaterion q_bar	=	compliment(q); //Collecting a compliment of a main quaterion

    printf("Compliment:\n Input:Quat(%g ,%g ,%g ,%g )\n Ouput:Quat(%g ,%g ,%g ,%g )\n",q.s,q.v.v1,q.v.v2,q.v.v3,q_bar.s,q_bar.v.v1,q_bar.v.v2,q_bar.v.v3);

    Quaterion q2	=	q_def(0,1,1,1); //q2 is another quaterion

    Quaterion result	=	multiplication(q,q2); //Collecting a product of two quaterions q and q2

    printf("Multiplication:\n Input : Quat1(%g ,%g ,%g ,%g),Quat2(%g ,%g ,%g ,%g)\n Output:result_Quat(%g ,%g ,%g ,%g)\n",q.s,q.v.v1,q.v.v2,q.v.v3,q2.s,q2.v.v1,q2.v.v2,q2.v.v3,result.s,result.v.v1,result.v.v2,result.v.v3);
    
    double dot	=	dot_prod(q,q2); //Collecting dot product of quaterions
    
    printf("Dot product:\n Input : Quat1(%g ,%g ,%g ,%g),Quat2(%g ,%g ,%g ,%g)\n Output:%g\n",q.s,q.v.v1,q.v.v2,q.v.v3,q2.s,q2.v.v1,q2.v.v2,q2.v.v3,dot);

    return 0;
}


