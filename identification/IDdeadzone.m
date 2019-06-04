% Calculate d+ and d-
% author: Arthur R Costa, Caio E C Oliveira & Lucas E Silva
% date:   June 2, 2019.
% This code is supposed to identify the voltage threshold of a dead zone.
% Obs.: not working.

clear all; close all; clc;

load ('dadosT');
data = dados;

%{
offset_plus  = 0;
offset_minus = 0;
i = 1;
flagpos = 0;
flagneg = 0;

while i <= length(dados)
    if flagpos == 0 && data(2, i) > 0
        deltaPlus = data(2, i);
        flagpos = 1;
    elseif flagneg == 0 && data(2, i) < 0
        deltaMinus = data(2, i);
        flagneg=1;
        break;
    i=i+1;
    end
end
%}

%%
entrada = data(3, 1:end);   % saída do atuador
saida   = data(2, 1:end);   % saída do sistema

%%
i = 1;
while i <= length(dados)
    if (entrada(i) > 0 && saida(i) > 0)
        
    end
    i = i + 1;
end

%{
disp('', deltaPlus);
disp(deltaMinus);
%}