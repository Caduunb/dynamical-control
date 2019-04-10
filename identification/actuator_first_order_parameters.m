%calculate the parameters of the first order tranfer function of the
%actuator
size=length(step_gain.data);
time_step=0.01; %determined in the simulation
U_b=step_gain.data(2:size);
A=[step_gain.data(1:size-1), step_input.data(1:size-1)];
Theta=inv(A'*A)*A'*U_b;
Tal=time_step/(1-Theta(1));
Gain=(Tal*Theta(2))/time_step;
disp(Tal);
disp(Gain);
