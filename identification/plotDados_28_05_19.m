% Aula 28 de Maio de 2019
clear all; close all;
load ('dadosQ.mat')

hold on;

plot(dados(1, 1:end), dados(5, 1:end),'r');
plot(dados(1, 1:end), dados(4, 1:end),'g', 'LineWidth', 2);
plot(dados(1, 1:end), dados(2, 1:end),'b');

legend('Entrada', 'Saída do atuador', 'Saída')
