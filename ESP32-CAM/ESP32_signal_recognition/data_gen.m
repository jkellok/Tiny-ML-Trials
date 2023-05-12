WantedAmountData = 10000;

v = zeros(WantedAmountData, 100);
labels = zeros(WantedAmountData,1);

for y = 1: WantedAmountData
    
    %this determines which of the 4 signals is generated
    num = rand();
    
    %random noise
    if (num < 0.25)
        rnoise = 0;
        last = rand()*0.9999;
        pos = 0;
        for n=1: 100
            
            rnoise = rand() * 0.04 -0.02;
            if (rnoise+last > 0.999)
                last = 0.9499 + rand() * 0.0499;
                v(y, n) = last;
            elseif (rnoise +last < 0)
                last = rand() * 0.0499;
                v(y, n) = last;
            end
            last = (last + rnoise);

            v(y, n) = last;

        end
        
        labels(y,1) = 3;
    
    %sine wave
    elseif (num < 0.5) 
        
        phaseShift = rand() * 3.14;
        freq =  5 + rand() * 25;
        amp =  0.05 + rand() * 0.5;
        pos = -0.01;
        dc_sin = rand() * 0.9;
        
        while (true) 
            if (amp + dc_sin > 0.999 || dc_sin - amp <0)
            amp =  0.15 + rand() * 0.3;
            dc_sin = 0.05 + rand() * 0.8;
            else
                break;
            end
        end

        for k = 1: 100
            pos = pos + 0.01;
            v(y,k) = amp * sin(freq * pos + phaseShift) + dc_sin;

            pos = pos + 0.01;
        end
    
    labels(y,1) = 0;
    
    %sawtooth
    elseif (num > 0.75) 

        pos = -0.01;
        a =  normrnd(1.5,0.3);
        if (a < 0.2)
            a = normrnd(1.5,0.1);
        end
        back = 0;
        bottom = rand() * 0.5;
        top = bottom + rand() * 0.9;
        while (true)
            if (top > 0.99 || top-bottom < 0.15)
                bottom = rand() * 0.5;
                top = bottom + rand() * 0.9;
            else
                break
            end
        end
        for j = 1: 100
        pos = pos + 0.01;
        if (a * pos-back+bottom) > top
            back = back + top -bottom;
        end
        
            v(y,j) = a * pos-back + bottom;

        end
        labels(y,1) = 1;
    
    %square wave
    else 
        low = 0.05 + rand()*8;
        high = low + rand()*0.8+0.05;
        while(true) 
            if (high > 0.999)
                low = normrnd(0.5,0.1);
                high = low + rand()*0.8+0.05;
            else 
                break;
            end
        end

        frq = randi(5)*5;
        shift = randi(20);

        dice = rand();
        if (dice > 0.5)
            state = low;
        elseif(y == 3) 
            state = high;
        end    
            pos = 0;
        for u = 1:100
            if (mod((u + shift), frq) == 0)
                if (state > low)
                    state = low;
                else
                    state = high;
                end

            end


        v(y, u) = state + rand() * 0.04 - 0.02;

        end
        labels(y,1) = 2;
    end
end

v = single(v);

writematrix(v, 'filename_x.csv')
writematrix(labels, 'filename_y.csv')





writematrix(v, 'filename_x.csv')
writematrix(labels, 'filename_y.csv')
