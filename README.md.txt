KEPLER'S EQUATION SOLVER

Algorithm:
1.Intial estimate of eccentric anomaly(En) 
If mean_anomaly < Pi(3.14...)
then 
En = mean_anomaly + eccentricity/2
else
En = mean_anomaly - eccentricity/2
2. Set epsilon = 0.00000001
3. Calculate Ens = En - ((En-eccentricity*sin(En)- mean_anomaly)/(1 - eccentricity*cos(En)))
4. Check whether modulus(En-Ens) < epsilon
if yes 
return Ens
else
set En = Ens
set Ens = En - ((En - eccentricity*sin(En) - mean_anomaly)/(1 - eccentricity*cos(En)))
go to step 4
5. After getting eccentric anomaly 
calculate true_anomaly = atan(sqrt((1+eccentricity)/(1-eccenticity))*tan(eccentric_anomaly/2))
6. End

Input  -  1. Mean anomaly [radians]
          2. Eccentricity (0-1)

Output -  1. Eccentric anomaly [radians]
          2. True anomaly [radians]

Example:-
1.0245
0.254
Eccentric Anomaly=1.2669
True Anomaly=1.5218
