
function numbin=dec_to_bia(numdec,N)



if (numdec>= 0)      %����ת������  
    numbin = dec2bin(numdec,N);
else      
    %����ת������  
    numbin = dec2bin(abs(numdec),N);    
    l1=length(numbin);    
    numbin4=0; 
    for i=1:l1          
        if (numbin(l1-i+1)==num2str(1))
            %��λȡ������ʮ���Ʊ�ʾ            
            numbin4=numbin4+0; 
        else              
            numbin4=numbin4+2^(i-1); 
    end
    end
    %ĩλ��1      
    numbin4=numbin4+1;     
    %�Ѵ������ʮ������ת�ɶ����ƣ��������numbin     
    numbin5=dec2bin(numbin4); 
    numbin=num2str(numbin5,N); 
end