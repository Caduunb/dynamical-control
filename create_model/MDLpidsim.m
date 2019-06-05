% Creates a PID controller using sisotool
% author: Caio Oliveira.
% date:   June 5, 2019.

load '../IDmodelo.mat'

% Space State

rlocus(sys);   % root locus open loop t. function
sisotool (sys) % open loop transfer function
