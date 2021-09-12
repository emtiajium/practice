clear
row=input('Input dimension');
col=row+1;
for i=1:row
	for j=1:col
		arr(i,j)=input('input value');
	end
end
for k=2:row
	pivot=arr(k-1,k-1);
	for i=k:row
		up=arr(i,k-1);
		for j=1:col
			arr(i,j)=arr(i,j)-(up/pivot)*arr(k-1,j);
		end
	end
end
for i=row:-1:1
	sol(i)=arr(i,col-1);
	for j=col-2:-1:1
		if(j==i) continue;
		end
		sol(i)=sol(i)-arr(i,j)*sol(j);
	end
	sol(i)=sol(i)/arr(i,i);
end
sol