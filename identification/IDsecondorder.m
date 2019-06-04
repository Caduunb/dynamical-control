%% Calculate the parameters of the system dynamics plus filter, 
% Needs to be run
% after dead_zone.m because it uses delta_plus and delta_minus values
% author: Arthur R Costa, Caio E C Oliveira & Lucas E Silva
% date:   June 2, 2019.
% Perform a system identification.

clear all; close all; clc;

file = 'q';
dados = plotDadosQT(file);

datasize = length(dados);
timeStep= dados(1,2) - dados(1,1);             % discrete time step
disp(['Data size: ', num2str(size(dados)), ';', ' Time Step: ', num2str(timeStep), ';']);
%% Matrices definition
delta = [0.968, -0.75];      % dead zone threshold
if (strcmp(file, 'q'))
    output = (dados(2, 1:end))';    % system output 
    input =  (dados(4, 1:end))';    % actuator output
elseif(strcmp(file, 't'))
    output = (dados(2, 1:end))';    % system output 
    input =  (dados(3, 1:end))';    % actuator output
end
%%
% Dead zone output estimation.
ddzone = zeros(length(input), 1);
i=1;
while i <= length(input)
    if ((input(i) > 0 && input(i) < delta(1)))
        ddzone(i) = 0;
    elseif ((input(i) >= delta(2)) && (input(i) < 0))
        ddzone(i) = 0;
    else
        ddzone(i) = input(i);
    end
    i=i+1;
end
figure; hold on;
subplot(1, 2, 1);
plot(dados(1, int16(1:length(dados)/4)), input(int16(1:length(dados)/4)), 'k', 'LineWidth', 2);
title('Dead Zone Input (zoom in)')
ylabel('Dead Zone Input (V)')
xlabel('time (s)')
subplot(1,2,2);
plot(dados(1, 1:int16(length(dados)/8)), ddzone(1:int16(length(ddzone)/8)), 'g', 'LineWidth', 2);
title('Dead Zone Output (zoom in)')
ylabel('Dead Zone Output (V)')
xlabel('time (s)')
%% Calculate theta(1:3)
A = [output(2:length(output) - 1), output(1:length(output)-2), ddzone(1:(length(ddzone)-2))];
Y = output(3:length(output));

theta = inv(A'*A)*A'*Y;
%%
a = (2 - theta(1))/timeStep;
b = a - ((1 + theta(2))/timeStep^2);
c = theta(3)/timeStep^2;

disp(['a = ', num2str(a), ';', 'b = ', num2str(b), ';', 'c = ', num2str(c)])
