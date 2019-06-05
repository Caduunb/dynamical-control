% Creates a process via a script, calculates the feedback transfer function and 
% opens the siso tool to evaluate a PID compensator applied to it. Made on
% class.

% author: Caio E. Coelho de Oliveira, Mechatronics Engineering Undergraduate, University of Brasília.
% date: April 23, 2019.

clear all
close all

% Space State Definition
A = [-4 -0.03; 0.75 -10];
B = [2; 0];
C = [0 1];
D = 0;
sys_proc = ss(A,B,C,D);
disp("Space State matrixes created");

% PID
kp = 30;    % proportional
ki = 120;   % integrative
kd = 2;     % derivative
sys_pid = tf([kp kd ki], [0 1 0]);
disp ("PID matrixes created");

zpk(sys_proc);      % Zero-pole-gain format
dcgain(sys_proc);   % DC gain

% Transfer function
sys_series = series(sys_pid, sys_proc); % Series transfer function
sys_fb = feedback(sys_series, 1);       % Feedback transfer function


pzmap(sys_fb)
step(sys_fb)
pole(sys_fb);
zero(sys_fb);

t = 1:0.01:25;                  % time vector
r = sign(sin(2*pi*0.2*t));      % input signal
y = lsim(sys_fb, r, t);         % linear simulation

figure;

subplot(2,1,1); plot(t,r);
subplot(2,1,2); plot(t,y);

sisotool(sys_proc)
