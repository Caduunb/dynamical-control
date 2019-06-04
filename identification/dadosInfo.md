% Info on dadosQ and dadosT

# dadosQ:

    1. Time (0.002s step);
    2. System output (omega);
    3. ?
    4. Actuator output;
    5. System input (amp 6Vpp, 50% duty cycle, 0.5Hz).

## First Order:

system =    b
         -------
          s + a

theta =    
        (1 - a*time_step)
        b

theta = 

    0.9812
    0.0199
    
a = (1-theta(1))/time_step = 9.4
b = 0.02

## Second order

system =      c
        -------------
        s^2 + s*a + b

theta = 
    2 - aT
    aT - bT^2 -1
    cT^2

a = 680.3854;
b = -332535.3506;
c = 123639.896


# dadosT:

1. Time (0.002s step);
2. System output (omega);
3. Actuator output;
4. System input.

## First Order:

theta =

    0.9600
    0.0400

a = (1-theta(1))/time_step = 20
b = 0.04

## Dead Zone:

Obs.: O algoritmo de identificação está errado. Zona morta obtida analiticamente, observando-se os gráficos.
    
delta = [0.968, -0.75];

## Second Order:
    