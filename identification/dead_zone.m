% Calculate d+ and d-
offset_plus=0;
offset_minus=0;
i = 1;
flagpos=0;
flagneg=0;
size=length(triangle_omega.data);
while i<=size                                                     
    if flagpos==0&&triangle_omega.data(i)>0
        delta_plus=triangle_gain.data(i);
        flagpos=1;
    end
    if flagneg==0&&triangle_omega.data(i)<0
        delta_minus=triangle_gain.data(i);
        flagneg=1;
        break;
    end
    i=i+1;
end

disp(delta_plus);

disp(delta_minus);
