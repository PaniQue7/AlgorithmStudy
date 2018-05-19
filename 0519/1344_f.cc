#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long double pa, pb,suma=0, sumb=0;
	cin >> pa >> pb;

	vector<long double> a(19,pa/100); //골을 넣을 확률

	vector<long double> la(19,1-(pa/100)); //골을 못 넣을 확률
	
	vector<long double> b(19,pb/100);

	vector<long double> lb(19,1-(pb/100));
	
	vector<long double> t(19,1);

	for(int i=2; i<19; i++)
	{
		a[i] *= a[i-1];	
		
		la[i] *= la[i-1];	
	
		b[i] *= b[i-1];	
		
		lb[i] *= lb[i-1];	
		
		t[i] = t[i-1] * i;
	}



	b[2]=0;
	b[3]=0;
	b[5]=0;
	b[7]=0;
	b[13]=0;
	b[17]=0;

	a[2]=0;
	a[3]=0;
	a[5]=0;
	a[7]=0;
	a[13]=0;
	a[17]=0;
	
	la[0]=1;
	lb[0]=1;

	a[0]=1;
	b[0]=1;



	for(int i=0; i<19; i++)
	{
		cout << "a["<<i<<"] : " << a[i]<<endl;
		
		suma += la[18-i]*(t[18]/(t[18-i]*t[i]))*a[i];
		
		sumb += lb[18-i]*(t[18]/(t[18-i]*t[i]))*b[i];
	}

	
	cout << 1-(suma*sumb);
	
	return 0;
}
