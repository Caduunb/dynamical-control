format longG

clearvars; close all; clc;

load IDmodelo.mat
num = sys.Numerator;
den = sys.Denominator;
num = num{:};
den = den{:};                                 % third order OLTF denominator
root3order = roots(den);
disp('todas as raízes: ');
disp(root3order);
root2order = [root3order(2), root3order(3)];
disp('raizes aproximadas: ');
disp(root2order);

%den        = poly(root2order)*root3order(1);  % second order OLTF denominator
%% Define State Space Matrices of the system
[A, B, C, D] = tf2ss(num, den);       % ss matrices using open loop transfer function
disp('A:');
disp(A);
disp('B:');
disp(B);
disp('C:');
disp(C);
disp('D:');
disp(D);

OLpoles = eig(A);                     % pólos do sistema
disp ('Pólos dos sistema de malha aberta: ');
disp (OLpoles);

disp('Assumindo que o sistema é controlável, iremos realocar os pólos do processo aonde for conveniente.')
%% Define K so as to place poles of the process
polosProc = [-8, -9, -10, -11]
Aext = [A, [0; 0; 0]; -C, 0];
Bext = [B; 0];
Kext  = acker(Aext, Bext, polosProc); % realocar os pólos para que a planta possa responder.
Kproc = [Kext(1), Kext(2), Kext(3)];
Ki    = Kext(4);
Ac = Aext - Bext*Kext;
disp('Pólos realocados do sistema. Matriz Ac = Aext - BextK')
disp(eig(Ac))

% Define poles of the observer
% They should be allocated at least 3x further from the origin than the
% furthest pole of the process.
polosObs = [-40, -42, -41];
L = (acker(A', C', polosObs))';
disp('ki: ')
disp(Ki);
disp('k: ')
disp(Kproc)
disp('L:');
disp(L);
save('dadosSS.mat', 'Kext', 'Kproc', 'Ki', 'L', 'A', 'B', 'C', 'D', 'Ac', 'Aext', 'Bext');

% Generate Simulink model
%openmodelsim();