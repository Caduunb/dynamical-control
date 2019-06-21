%% Genarate Simulink observer process simulation

function openmodelsim()
    load dadosSS.mat

    open_system('simProcObsSquare');
    open_system('simProcObsStep');
end
