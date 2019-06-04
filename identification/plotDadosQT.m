% Aula 28 de Maio de 2019
% author: Caio E C Oliveira
% date:   June 2, 2019.

function data_load = plotDadosQT(file)
    if (strcmp(file, 'Q') || strcmp(file, 'q'))
        file = 'dadosQ';
    elseif(strcmp(file, 'T') || strcmp(file, 't'))
        file = 'dadosT';
    end
    if(strcmp(file, 'dadosQ.mat') || strcmp(file, 'dadosQ'))
        load (file);
        disp ('Dados da entrada quadrada');
        figure; hold on;
        plot(dados(1, 1:end), dados(4, 1:end),'r', 'LineWidth', 2); % entrada sistema
        plot(dados(1, 1:end), dados(3, 1:end),'g', 'LineWidth', 2); % saída atuador
        plot(dados(1, 1:end), dados(2, 1:end),'b');                 % saída sistema
    elseif (strcmp(file, 'dadosT.mat') || strcmp(file, 'dadosT'))
        load (file);
        disp ('Dados da entrada triangular');
        figure; hold on;
        plot(dados(1, 1:end), dados(4, 1:end),'r', 'LineWidth', 2); % entrada sistema
        plot(dados(1, 1:end), dados(3, 1:end),'g', 'LineWidth', 2); % saída atuador
        plot(dados(1, 1:end), dados(2, 1:end),'b');                 % saída sistema
    else
        error('Dados não encontrados ou diferentes do esperado. Encerrando script.')
    end
    
    legend('Entrada do sistema', 'Saída do Atuador', 'Saída do sistema')
    xlabel('Tempo (s)');
    ylabel('Voltagem (V)');
    data_load = dados;
end
