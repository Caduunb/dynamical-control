% Aula 28 de Maio de 2019
% author: Caio E C Oliveira
% date:   June 2, 2019.

function data_load = plotDadosQT(file)
    if (strcmp(file, 'Q') || strcmp(file, 'q'))
        file = 'dadosQ';
        disp ('Dados da entrada quadrada');
    elseif(strcmp(file, 'T') || strcmp(file, 't'))
        file = 'dadosT';
        disp ('Dados da entrada triangular');
    end
    load(file);
    % Graficos
    figure(1); hold on;
    plot(dados(1, :), dados(4, :),'r', 'LineWidth', 2); % entrada sistema
    plot(dados(1, :), dados(3, :),'g', 'LineWidth', 2); % sa�da atuador
    title('Entrada do sistema e Sa�da do Atuador');
    xlabel('Tempo (s)');
    ylabel('Voltagem (V)');
    legend('Entrada do sistema', 'Sa�da do Atuador');

    figure(2);
    plot(dados(1, :), dados(2, :),'k', 'LineWidth', 2); % sa�da sistema
    title('Sa�da do sistema');
    xlabel('Tempo (s)');
    ylabel('Voltagem (V)');
    legend('Sa�da do sistema');
    
    data_load = dados;
end
