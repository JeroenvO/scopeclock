#include <stdio.h>
#include <math.h>
#include <time.h>

char cir2aud(float coord){
	return (char) round((coord+1.0)/2.0*255.0);
}

void emit(float x, float y){
	printf("%c%c", cir2aud(y), cir2aud(x));
}

void arm(float x, float y, float steps, float length){
	int i,ai;
	for(i=-steps; i<=steps; i++){
		ai=abs(i);
		emit(x*ai/steps*length, y*ai /steps*length);
	}
}

int main(int argc, char *argv[], char *envp[])
{

	int i, j, dwell, arm1, arm2, arm3;
	float increment = 2.0*3.1415926535/60.0;
	float x=0.0, y=0.0, angle = 0.0;
	float n=1;
	time_t rawtime;
  	struct tm * timeinfo;
	while(1){ 
  		time (&rawtime);
	  	timeinfo = localtime (&rawtime);
		arm2 = timeinfo->tm_min;
		arm1 = ((timeinfo->tm_hour % 12)*5)+arm2/12.0;
		angle = 0.0;
		for(i=0;i<=60;i++){
			if(i%5 == 0){
				dwell = 5*n;
			}else{
				dwell = n;
			}
			angle += increment;
			x = cos(angle);
			y = sin(angle);
			for(j=0;j<dwell;j++){
				emit(x, y);
			}
			if(i == arm1){
				arm(x,y,n*50.0,0.5);
			}
			if(i == arm2){
				arm(x,y,n*30.0,0.7);
			}
			if(i == timeinfo->tm_sec){
				arm(x,y,n*20.0,0.9);
			}
			for(j=0;j<dwell;j++){
				emit(x, y);
			}
		}
	}	
}
