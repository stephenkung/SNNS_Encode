#include <iostream.h>
#include <stdlib.h>
#include "./encode.h"
#include "./encode.c"


int main(void)   {
	int i=0;
	int j=0;

	float snns_output[5];
	float err_rate[5];
	float average_err_rate=0;

	float input[5][5]={	{0.85, 0.15, 0.22, 0.46, 0.66},
						{0.89, 0.81, 0.79, 0.11, 0.88},
						{0.27, 0.4,  0.08, 0.47, 0.566},
						{0.99, 0.15, 0.42, 0.34, 0.6},
						{0.64, 0.57, 0.89, 0.72, 0.89}};


	float golden_output[5][5]={	{0.556,  0.3717, 0.4132, 0.4479, 0.4559},
								{0.7062, 0.648,  0.624,  0.6308, 0.6083},
								{0.286,  0.3318, 0.3678, 0.3889, 0.4016},
								{0.6518, 0.3797, 0.4236, 0.4591, 0.4642},
								{0.6408, 0.6343, 0.73,   0.6994, 0.7001}};


	for(i=0;i<5;i++){
	cout<<"the "<<i<<"th test pattern:"<<endl;
	snns_encode(input[i],snns_output, 0);
		for(j=0;j<5;j++){
			err_rate[j]= fabs((snns_output[j]-golden_output[i][j])/golden_output[i][j]);
			cout<<"out["<<j<<"]:"<<snns_output[j]<<";golden_value:"<<golden_output[i][j]<<endl;
			cout<<"err rate:"<<err_rate[j]<<endl;
			average_err_rate += err_rate[j];
		}
		average_err_rate /= 5;  
		cout<<"average_err_rate:"<<average_err_rate<<endl<<endl;
	}
return 0;
}