%% Calculate the parameters of the system dynamics plus filter, 
% Needs to be run
% after dead_zone.m because it uses delta_plus and delta_minus values
% author: Arthur R Costa, Caio E C Oliveira & Lucas E Silva
% date:   June 2, 2019.
% Perform a system identification.

%clearvars;
close all;
clc;

file = 'q';
dados = plotDadosQT(file); close all;

datasize = length(dados);
T= dados(1,2) - dados(1,1);             % discrete time step
disp(['Data size: ', num2str(size(dados)), ';', ' Time Step: ', num2str(T), ';']);

%% Matrices definition
startpoint = 500;                        % Ignoring noisy initial signal
delta = [0.968, -0.75];                  % dead zone threshold
input =  (dados(3, startpoint:end))';    % actuator output
output = (dados(2, startpoint:end))';    % system output 

% Dead zone output estimation.
ddzone = zeros(length(input), 1);
i=1;
while i <= length(input)
    if ((input(i) < delta(2)))
        ddzone(i) = input(i) - delta(2);
    elseif((input(i) > delta(1)))
        ddzone(i) = input(i) - delta(1);
    end
    i=i+1;
end

figure; hold on;
subplot(1, 2, 1);
zoom = startpoint:int16(length(dados)/4);
plot(dados(1, zoom), input(zoom), 'k', 'LineWidth', 2);
title('Dead Zone Input (zoom in)');
ylabel('Dead Zone Input (V)');
xlabel('time (s)');

subplot(1,2,2);
zoom = startpoint:int16(length(dados)/8);
plot(dados(1, zoom), ddzone(zoom), 'g', 'LineWidth', 2);
title('Dead Zone Output (zoom in)');
ylabel('Dead Zone Output (V)');
xlabel('time (s)');

clear zoom i;

%% Calculate theta(1:3)
A = [output(2:length(output) - 1), output(1:length(output)-2)];
A = [A, ddzone(1:(length(ddzone)-2))];
Y = output(3:length(output));

theta = inv(A'*A)*A'*Y;

a = (2 - theta(1))/T;
b = (a*T - 1 - theta(2)) / T^2;
c = theta(3)/T^2;

disp ('System type: c/(s^2 + s*a + b)');
disp(['a = ', num2str(a), ';', 'b = ', num2str(b), ';', 'c = ', num2str(c)])
close all;
%% Simulation
time  = dados(1, 1:length(ddzone));
g = tf([c], [1 a b]);
sys2order = lsim (g, ddzone, time);

figure;
plot(time, output, 'k', time, sys2order, 'g', 'LineWidth', 2);
legend('Saida Medida', 'Resposta Simulada');
