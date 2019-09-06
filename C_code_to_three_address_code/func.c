void func(int i,double d){
	float mat[2][2] = {1.2, 2.0; 3.5, 4.3};
	while(mat[i][i] > d)
	{
		i=i-1;
	}
}

double getFib(int n) {
    if(n <= 1) return n;
    int a[2][2];
    a[0][0] = a[0][1] + 1;
    a[1][0] = a[1][1] * 5;
    return (a[0][0] + a[0][1]);
}



int main(){
	int a;
	double b,c;
	a=1;
	b=2.0;
	func(a,b);
	a= 5;
	b = getFib(a);
	
}