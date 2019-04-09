%calculate the parameters of the system dynamics plus filter, has to be run
%after dead_zone.m because it uses delta_plus and delta_minus values
size=length(step_omega.data);
time_step=0.01; %determined in the simulation

W_m=step_omega.data(3:size);


U_c=step_gain.data;
i=1;
while i<=length(step_gain.data)
    if U_c(i)<delta_minus
        U_c(i)=U_c(i)-delta_minus;
    end
    
    if U_c(i)>=delta_minus&&U_c(i)<=delta_plus
        U_c(i)=0;
    end
    
    if U_c(i)>delta_plus
        U_c(i)=U_c(i)-delta_plus;
    end    
    
    i=i+1;
end

    
A_2=[step_omega.data(2:size-1), step_omega.data(1:size-2), U_c(1:size-2)];

Theta_2=inv(A_2'*A_2)*A_2'*W_m;
Tal_2=(time_step*time_step)/(1-Theta_2(1)-Theta_2(2));
we=-(Theta_2(1)-2+(time_step/Tal_2))/time_step;
K=Theta_2(3)/(((time_step*time_step)/Tal_2)*we);
disp(Tal_2);
% disp(we);
% disp(K);
disp(Theta_2);