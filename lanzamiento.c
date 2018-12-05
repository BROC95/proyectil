#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI		3.14159265358979323846

float velocidad_x(float vel,float theta);
float velocidad_y(float vel,float theta);
float grados(float rad);
float rad(float grados);
float Hmax(float vel,float t);

int main()
{   float v,a,vx,vy,t,x,y,v_y,M,Angulo,t0,H,t2,R;
    int w,n;

    do
    {
    printf("\n1-LANZAMIENTO DE UN PROYECTIL\n0-SALIR\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        {
            printf("Velocidad del proyectil\n");
            scanf("%f",&v);
            printf("Angulo del lanzamiento\n");
            scanf("%f",&a);
            a=rad(a);
            printf("componente en x\n");
            vx=velocidad_x(v,a);
            printf("vx=%f\n",vx);
            printf("componente en y\n");
            vy=velocidad_y(v,a);
            printf("vx=%f\n",vy);
            printf("posicion del proyectil en el instante t segundos\n");
            scanf("%f",&t);
            printf("\nposicion en el eje x\n");
            x=vx*t;
            printf("x= %f m",x);
            printf("\nposicion en el eje y\n");
            y=vy*t-(0.5*9.8*t*t);
            printf("y= %f m",y);
            printf("\nvelocidad del proyectil en el instante t segundos\n");
            printf("vel en el eje x\nvx=%f",vx);
            printf("\nvel en el eje y\n");
            v_y=vy-9.8*t;
            printf("vy=%f",v_y);
            printf("\nmagnitud y direccion del proyectil\n");
            M=sqrt(pow(vx,2)+ pow(v_y,2));
            printf("V=%f\n",M);
            Angulo=atan(v_y/vx);
            Angulo=grados(Angulo);
            printf("Theta=%f\n",Angulo);
            printf("Instante de la altura maxima Im y Altura maxima h\n");
            t0=vy/9.8;
            printf("Im=%f\n",t0);
            H=Hmax(vy,t0);
            printf("h=%f\n",H);
            printf("Alcance e instante maximo horizontal del proyectil\n ");
            t2=2*t0;
            R=vx*t2;
            printf("tmax=%f\n",t2);
            printf("Xmax=%f",R);
            break;
        }
    }

    w++;
    }
    while(n!=0);
    return 0;
}

float velocidad_x(float vel,float theta)
{
    float vx;
    vx=vel*cos(theta);
    return vx;
}
float velocidad_y(float vel,float theta)
{
    float vy;
    vy=vel*sin(theta);
    return vy;
}
float grados(float rad)
{
    float g;
    g=rad*180/M_PI;
    return g;
}

float rad (float grados)
{   float rad;
    rad=grados*M_PI/180;
    return rad;
}
float Hmax(float vel,float t)
{
    float  Hmax;
    Hmax=vel*t-9.8*t;
    return Hmax;
}
