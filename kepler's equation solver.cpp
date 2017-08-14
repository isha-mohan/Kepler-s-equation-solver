#include<stdio.h>
#include<math.h>
double eccentric_anomaly(double , double);
double true_anomaly(double , double);
double modulus(double);
int main()
{
	double mean_anomaly,eccentricity,eccentric_ano,true_ano;
	scanf("%lf",&mean_anomaly);
	scanf("%lf",&eccentricity);
	eccentric_ano = eccentric_anomaly(mean_anomaly,eccentricity);
	true_ano = true_anomaly(eccentricity,eccentric_ano);
	printf("Eccentric Anomaly=%.4lf\n",eccentric_ano);
	printf("True Anomaly=%.4lf",true_ano);
	return 0;
}
double eccentric_anomaly(double M,double e)
{
	double En, Ens, eps;
	eps = 0.00000001;
	if(M > M_PI)
	{
		En = M - e/2;
	}
	else
	{
		En = M + e/2;
	}
	Ens = En - ((En-e*sin(En)- M)/(1 - e*cos(En)));
	while(modulus(En-Ens)>eps||modulus(En-Ens)==eps)
	{
		En = Ens;
		Ens = En - ((En - e*sin(En) - M)/(1 - e*cos(En)));
	}
	return Ens;
}
double modulus(double x)
{
	if(x>=0)
	{
		return x;
	}
	else
	{
		return -x;
	}
}
double true_anomaly(double e,double E)
{
	double true_ano,x;
	x = atan(sqrt((1+e)/(1-e))*tan(E/2));
	true_ano = 2*x;
	return true_ano;
}
