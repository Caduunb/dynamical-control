% Info on dadosQ and dadosT
% date: June 4, 2019.
% Dynamical Control Lab
% author: Caio Oliveira

# dadosQ: OK

    1. Time (0.002s step);
    2. System output (omega);
    3. Actuator output;
    4. System input (amp 10Vpp, 50% duty cycle, 0.5Hz).

## First Order Q: OK

system =    b
         -------
          s + a

theta =    
        (1 - a*T)
        bT

theta = 

    
    
a = 20
b = 20

## Second order Q: OK

system =      c
        -------------
        s^2 + s*a + b

theta = 
    2 - aT
    aT - bT^2 -1
    cT^2

a = 652.7447;
b = 7555.5563;
c = 181707.3116

---------------------------------------------------
# dadosT: OK

1. Time (0.002s step);
2. System output (omega);
3. Actuator output;
4. System input.

## First Order T: OK

theta =

    0.9600
    0.0400

a = (1-theta(1))/T = 20
b = 

## Dead Zone: OK

Obs.: O algoritmo de identificação está errado. Zona morta obtida analiticamente, observando-se os gráficos.
    
delta = [0.968, -0.75];

## Second Order T: NOT OK

system =      c
        -------------
        s^2 + s*a + b

theta = 
    2 - aT
    aT - bT^2 -1
    cT^2

a = 741.7348;
b = -365986.1259;
c = 64876.979
